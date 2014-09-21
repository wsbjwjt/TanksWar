//
//  Tank.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#include "Tank.h"


Tank::Tank() {
    
}
Tank::~Tank() {
    
}

Tank* Tank::createTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo) {
    
    SpriteFrameCache* pCache = SpriteFrameCache::sharedSpriteFrameCache();
    pCache->addSpriteFramesWithFile("tank.plist");
    
    Tank* tank = new Tank();
    tank->initWithSpriteFrameName(tankTypeName);
    tank->autorelease();
    
    return tank;
    
}
void Tank::initTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo) {
    
}
void Tank::remove() {
    
}
void Tank::move() {
    
}

void Tank::setBlock(bool isBlock) {
    
}

bool Tank::getBlock() {
    return true;
}
