#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

HRESULT GameScene::init()
{
	// 게임씬에서 필요한 매니저들 초기화.
	OBJECTPOOL->Init();
	BULLETMANAGER->Init();

	// 플레이어, 에네미 메니저 초기화.
	PLAYERMANAGER->Init();
	ENEMYMANAGER->Init();

	return S_OK;
}

void GameScene::release()
{
}

void GameScene::update()
{
	PLAYERMANAGER->Update();
	ENEMYMANAGER->Update();

}

void GameScene::render()
{
	PLAYERMANAGER->Render(getMemDC());
	ENEMYMANAGER->Render(getMemDC());
}
