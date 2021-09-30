//#pragma once
//
//#include "Manager.h"
//
//class Component;
//
//namespace sf
//{
//	class RenderWindow;
//}
//
//class ComponentManager : public Manager
//{
//public:
//	ComponentManager();
//	~ComponentManager();
//
//	void Draw(sf::RenderWindow* pWindow);
//	void Update(float deltaTime);
//
//	void AddComponent(Component* pComponent);
//	void RemoveComponent(Component* pComponent);
//
//	std::vector<Component*>& GetComponentList(const char* type);
//
//protected:
//	std::map<const char*, std::vector<Component*>> m_Components;
//	
//};