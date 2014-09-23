//
//  CityScene.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-18.
//
//

#include "CityScene.h"

CityScene::CityScene() :mRound(1) {
    mPlayerTank[0] = nullptr;
    mPlayerTank[1] = nullptr;
}
CityScene::~CityScene() {
    
}
bool CityScene::init() {
    if (!Layer::init()) {
        return false;
    }
    
    char szRound[260];
    sprintf(szRound, "Round%d.tmx", mRound);
    TileMapInfo* tileMapInfo = TileMapInfo::createMapInfoWithFile(szRound);
    TMXTiledMap* tmxTileMap = tileMapInfo->getTileMap();
    this->addChild(tmxTileMap);
    
    mPlayerTank[0] = Tank::createTankWithTankType("player2U.png", tileMapInfo);
    
    
    Size tileSize = tmxTileMap->getTileSize();
    Size mapSize = tmxTileMap->getContentSize();
    mPlayerTank[0]->setPosition(Vec2(mapSize.width / 2 - tileSize.width * 3, tileSize.height));
    
    mLayerPanel = Panel::create();
    addChild(mLayerPanel, 3);
    
    return true;
}
void CityScene::onEnter() {
    
}
void CityScene::update(float delta) {
    
}

Scene *CityScene::scene() {
    
    Scene* scene = Scene::create();
    CityScene * layer = CityScene::create();
    scene->addChild(layer);
    return scene;
}
Scene *CityScene::scene(int round) {
    
    Scene* scene = Scene::create();
    CityScene * layer = CityScene::create(round);
    scene->addChild(layer);
    return scene;
}
CityScene *CityScene::create(int round) {
    
    CityScene* pRet = new CityScene();
    if (pRet) {
        
        pRet->setRound(round);
        if (pRet->init()) {
            pRet->autorelease();
            return pRet;
        }
    }
    return NULL;
}




















