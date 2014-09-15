//
//  Bullet.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#include "Bullet.h"

Bullet::Bullet() :mFlyState(false) {
    
}
Bullet::~Bullet() {
    
}

Bullet* Bullet::createBulletWithTank(Tank* tank) {
    Bullet* bullet = new Bullet();
    bullet->initBulletWithTank(tank);
    bullet->autorelease();
    
    return bullet;
}

void Bullet::initBulletWithTank(Tank* tank) {
    
    mTank = tank;
    mTileMapInfo = mTank->getTileMapInfo();
    
    initWithSpriteFrameName("bullet.png");
    setScale(1.5 / 3.0);
    setVisible(false);
    mTileMapInfo->getTileMap()->addChild(this);
}

bool Bullet::fire() {
    return true;
}
bool Bullet::stopFire() {
    return true;
}
void Bullet::update(float delta) {
    
}
void Bullet::bulletBoom() {
    
}
