//
//  TileMapInfo.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#include "TileMapInfo.h"


void TileMapInfo::initMapInfoWithFile(const char* tmxFile) {
    
    mTMXTileMap = TMXTiledMap::create(tmxFile);
    mTMXLayers[0] = mTMXTileMap->layerNamed("layer_0");
    mTMXLayers[1] = mTMXTileMap->layerNamed("layer_1");
    
    Size winSize = Director::getInstance()->getWinSize();
    Size mapSize = mTMXTileMap->getContentSize();
    
    mTMXTileMap->setScale(winSize.height / mTMXTileMap->getContentSize().height);
    
    mTMXTileMap->setPosition(Vec2((winSize.width - mapSize.width * mTMXTileMap->getScale()) / 2, (winSize.height - mapSize.height * mTMXTileMap->getScale()) / 2));
}

TileMapInfo* TileMapInfo::createMapInfoWithFile(const char* tmxFile) {
    
    TileMapInfo* tileMapInfo = new TileMapInfo();
    tileMapInfo->initMapInfoWithFile(tmxFile);
    
    return tileMapInfo;
}

bool TileMapInfo::collisionTest(Rect rect) {
    
    int gid = 0;
    Size mapSize = mTMXTileMap->getContentSize();
    Size tileSize = mTMXTileMap->getTileSize();
    
    
    
    
    
    return true;
}






















