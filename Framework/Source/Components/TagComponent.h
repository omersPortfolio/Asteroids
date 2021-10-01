#pragma once


struct TagComponent
{
	TagComponent() = default;
	TagComponent(const TagComponent&) = default;
	TagComponent(const std::string& tag)
		: m_Tag(tag) {}


	std::string m_Tag;
};