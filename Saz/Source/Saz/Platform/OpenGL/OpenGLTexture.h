#pragma once

#include "Saz/Rendering/Texture.h"
#include <glad/glad.h>
namespace Saz
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(const String& path);
		virtual ~OpenGLTexture2D();

		uint32_t GetWidth() const override { return m_Width; }
		uint32_t GetHeight() const override { return m_Height; }
		virtual uint32_t GetRendererID() const override { return m_RendererID; }

		virtual void SetData(void* data, uint32_t size) override;

		virtual const std::string& GetPath() const override { return m_Path; }

		void Bind(uint32_t slot = 0) const override;

		virtual bool operator==(const Texture& other) const override 
		{ 
			return m_RendererID == other.GetRendererID();
		}

	private:
		std::string m_Path;
		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_RendererID;
		GLenum m_InternalFormat, m_DataFormat;
	};
}