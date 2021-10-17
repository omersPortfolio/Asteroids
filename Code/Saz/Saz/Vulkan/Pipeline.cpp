#include "SazPCH.h"
#include "Pipeline.h"
#include "Saz/FileHelpers.h"

#include <Saz/Vulkan/Model.h>

namespace
{
	VkShaderModule CreateShaderModule(const VkDevice logicalDevice, const DynamicArray<char>& shaderData)
	{
		VkShaderModuleCreateInfo createInfo;
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = shaderData.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(shaderData.data());
		createInfo.flags = 0;
		createInfo.pNext = nullptr;

		VkShaderModule shaderModule = VK_NULL_HANDLE;
		vkCreateShaderModule(logicalDevice, &createInfo, nullptr, &shaderModule);
		return shaderModule;
	}
}

namespace vulkan
{
	Pipeline::Pipeline(vulkan::Device& device,
		const PipelineConfig& config) : m_Device(device)
	{
		DynamicArray<char> vertShader;
		bool vertSuccess = Saz::file::LoadFileAsChar("D:/Dev/Saz/Data/Shaders/SimpleShader.vert.spv", vertShader);
		SAZ_ASSERT(vertSuccess, "Failed to load vertex shader!");
		m_VertShaderModule = CreateShaderModule(m_Device.device(), vertShader);
		SAZ_ASSERT(m_VertShaderModule != VK_NULL_HANDLE, "Failed to create vertex shader module!");

		DynamicArray<char> fragShader;
		bool fragSuccess = Saz::file::LoadFileAsChar("D:/Dev/Saz/Data/Shaders/SimpleShader.frag.spv", fragShader);
		SAZ_ASSERT(fragSuccess, "Failed to load vertex shader!");
		m_FragShaderModule = CreateShaderModule(m_Device.device(), fragShader);
		SAZ_ASSERT(m_FragShaderModule != VK_NULL_HANDLE, "Failed to create vertex shader module!");

		SAZ_ASSERT(config.pipelineLayout != VK_NULL_HANDLE, "Cannot create graphics pipeline:: no pipelineLayout provided in PipelineConfig");
		SAZ_ASSERT(config.renderPass != VK_NULL_HANDLE, "Cannot create graphics pipeline:: no renderPass provided in PipelineConfig");

		VkPipelineShaderStageCreateInfo shaderStages[2];
		shaderStages[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		shaderStages[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
		shaderStages[0].module = m_VertShaderModule;
		shaderStages[0].pName = "main";
		shaderStages[0].flags = 0;
		shaderStages[0].pNext = nullptr;
		shaderStages[0].pSpecializationInfo = nullptr;

		shaderStages[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		shaderStages[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		shaderStages[1].module = m_FragShaderModule;
		shaderStages[1].pName = "main";
		shaderStages[1].flags = 0;
		shaderStages[1].pNext = nullptr;
		shaderStages[1].pSpecializationInfo = nullptr;

		auto attributeDescriptions = Vertex::GetAttributeDescriptions();
		auto bindingDescriptions = Vertex::GetBindingDescriptions();
		VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
		vertexInputInfo.vertexBindingDescriptionCount = static_cast<uint32_t>(bindingDescriptions.size());
		vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();
		vertexInputInfo.pVertexBindingDescriptions = bindingDescriptions.data();

		VkGraphicsPipelineCreateInfo pipelineInfo{};
		pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineInfo.stageCount = 2;
		pipelineInfo.pStages = shaderStages;
		pipelineInfo.pVertexInputState = &vertexInputInfo;
		pipelineInfo.pInputAssemblyState = &config.inputAssemblyInfo;
		pipelineInfo.pViewportState = &config.viewportInfo;
		pipelineInfo.pRasterizationState = &config.rasterizationInfo;
		pipelineInfo.pMultisampleState = &config.multisampleInfo;
		pipelineInfo.pColorBlendState = &config.colorBlendInfo;
		pipelineInfo.pDepthStencilState = &config.depthStencilInfo;
		pipelineInfo.pDynamicState = &config.dynamicStateInfo;

		pipelineInfo.layout = config.pipelineLayout;
		pipelineInfo.renderPass = config.renderPass;
		pipelineInfo.subpass = config.subpass;

		pipelineInfo.basePipelineIndex = -1;
		pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;

		bool success = vkCreateGraphicsPipelines(m_Device.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_GraphicsPipeline) == VK_SUCCESS;
		SAZ_ASSERT(success, "Failed to create the Graphics Pipeline!");
	}

	Pipeline::~Pipeline()
	{
		vkDestroyShaderModule(m_Device.device(), m_VertShaderModule, nullptr);
		vkDestroyShaderModule(m_Device.device(), m_FragShaderModule, nullptr);
		vkDestroyPipeline(m_Device.device(), m_GraphicsPipeline, nullptr);
	}

	bool Pipeline::ReadFile(const FilePath& filepath)
	{
		std::ifstream file{ filepath, std::ios::ate | std::ios::binary };
		
		if (!file.is_open())
			return false;

		size_t fileSize = static_cast<size_t>(file.tellg());

		DynamicArray<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return true;
	}

	void Pipeline::Bind(VkCommandBuffer commandBuffer)
	{
		vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, m_GraphicsPipeline);
	}

	void Pipeline::DefaultPipelineConfig(PipelineConfig& config)
	{
		config.inputAssemblyInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		config.inputAssemblyInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		config.inputAssemblyInfo.primitiveRestartEnable = VK_FALSE;

		config.viewportInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		config.viewportInfo.viewportCount = 1;
		config.viewportInfo.pViewports = nullptr;
		config.viewportInfo.scissorCount = 1;
		config.viewportInfo.pScissors = nullptr;

		config.rasterizationInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		config.rasterizationInfo.depthClampEnable = VK_FALSE;
		config.rasterizationInfo.rasterizerDiscardEnable = VK_FALSE;
		config.rasterizationInfo.polygonMode = VK_POLYGON_MODE_FILL;
		config.rasterizationInfo.lineWidth = 1.0f;
		config.rasterizationInfo.cullMode = VK_CULL_MODE_NONE;
		config.rasterizationInfo.frontFace = VK_FRONT_FACE_CLOCKWISE;
		config.rasterizationInfo.depthBiasEnable = VK_FALSE;
		config.rasterizationInfo.depthBiasConstantFactor = 0.0f;  // Optional
		config.rasterizationInfo.depthBiasClamp = 0.0f;           // Optional
		config.rasterizationInfo.depthBiasSlopeFactor = 0.0f;     // Optional

		config.multisampleInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		config.multisampleInfo.sampleShadingEnable = VK_FALSE;
		config.multisampleInfo.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		config.multisampleInfo.minSampleShading = 1.0f;           // Optional
		config.multisampleInfo.pSampleMask = nullptr;             // Optional
		config.multisampleInfo.alphaToCoverageEnable = VK_FALSE;  // Optional
		config.multisampleInfo.alphaToOneEnable = VK_FALSE;       // Optional

		config.colorBlendAttachment.colorWriteMask =
			VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT |
			VK_COLOR_COMPONENT_A_BIT;
		config.colorBlendAttachment.blendEnable = VK_FALSE;
		config.colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;   // Optional
		config.colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO;  // Optional
		config.colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;              // Optional
		config.colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;   // Optional
		config.colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;  // Optional
		config.colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;              // Optional

		config.colorBlendInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		config.colorBlendInfo.logicOpEnable = VK_FALSE;
		config.colorBlendInfo.logicOp = VK_LOGIC_OP_COPY;  // Optional
		config.colorBlendInfo.attachmentCount = 1;
		config.colorBlendInfo.pAttachments = &config.colorBlendAttachment;
		config.colorBlendInfo.blendConstants[0] = 0.0f;  // Optional
		config.colorBlendInfo.blendConstants[1] = 0.0f;  // Optional
		config.colorBlendInfo.blendConstants[2] = 0.0f;  // Optional
		config.colorBlendInfo.blendConstants[3] = 0.0f;  // Optional

		config.depthStencilInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		config.depthStencilInfo.depthTestEnable = VK_TRUE;
		config.depthStencilInfo.depthWriteEnable = VK_TRUE;
		config.depthStencilInfo.depthCompareOp = VK_COMPARE_OP_LESS;
		config.depthStencilInfo.depthBoundsTestEnable = VK_FALSE;
		config.depthStencilInfo.minDepthBounds = 0.0f;  // Optional
		config.depthStencilInfo.maxDepthBounds = 1.0f;  // Optional
		config.depthStencilInfo.stencilTestEnable = VK_FALSE;
		config.depthStencilInfo.front = {};  // Optional
		config.depthStencilInfo.back = {};   // Optional

		config.dynamicStateEnables = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };
		config.dynamicStateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		config.dynamicStateInfo.pDynamicStates = config.dynamicStateEnables.data();
		config.dynamicStateInfo.dynamicStateCount =
			static_cast<uint32_t>(config.dynamicStateEnables.size());
		config.dynamicStateInfo.flags = 0;
	}
}