#include "FrameworkPCH.h"
#include "GameCore.h"
#include "FWCore.h"

namespace fw
{
	GameCore::GameCore(FWCore* pFramework)
	{
		m_pFramework = pFramework;
	}

	GameCore::~GameCore()
	{

	}

	sf::RenderWindow* GameCore::GetWindow()
	{
		return m_pFramework->GetWindow();
	}

}