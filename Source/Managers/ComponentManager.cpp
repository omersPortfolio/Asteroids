//#include "GamePCH.h"
//
//#include "ComponentManager.h"
//#include "Components/Component.h"
//#include "Components/SpriteComponent.h"
//#include "Actors/Actor.h"
//
//ComponentManager::ComponentManager()
//{
//
//}
//
//ComponentManager::~ComponentManager()
//{
//
//}
//
//void ComponentManager::Draw(sf::RenderWindow* pWindow)
//{
//	/*std::vector<Component*>& list = m_Components[SpriteComponent::GetStaticType()];
//	for (int i = 0; i < list.size(); i++)
//	{
//		SpriteComponent* pSpriteComponent = static_cast<SpriteComponent*>(list[i]);
//
//		Actor* pActor = pSpriteComponent->GetOwner();
//
//		if (pActor != nullptr)
//		{
//			pWindow->draw(*pSpriteComponent->GetSprite());
//		}
//	}*/
//}
//
//void ComponentManager::Update(float deltaTime)
//{
//
//}
//
//void ComponentManager::AddComponent(Component* pComponent)
//{
//	assert(pComponent != nullptr);
//
//	const char* type = pComponent->GetType();
//
//	assert(std::find(m_Components[type].begin(), m_Components[type].end(), pComponent) == m_Components[type].end());
//
//	m_Components[type].push_back(pComponent);
//}
//
//void ComponentManager::RemoveComponent(Component* pComponent)
//{
//	const char* type = pComponent->GetType();
//
//	std::vector<Component*>& list = m_Components[type];
//	list.erase(std::remove(list.begin(), list.end(), pComponent), list.end());
//}
//
//std::vector<Component*>& ComponentManager::GetComponentList(const char* type)
//{
//	return m_Components[type];
//}
