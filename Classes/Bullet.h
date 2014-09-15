//
//  Bullet.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#ifndef __TanksWar__Bullet__
#define __TanksWar__Bullet__

#include "cocos2d.h"
#include "Tank.h"

using namespace cocos2d;

class Bullet : public Sprite {
    
public:
    Bullet();
    ~Bullet();
    
    static Bullet* createBulletWithTank(Tank* tank);
    void initBulletWithTank(Tank* tank);
    bool fire();
    bool stopFire();
    virtual void update(float delta);
    void bulletBoom();
    
private:
    Tank* mTank;
    TileMapInfo* mTileMapInfo;
    float stepX, stepY;
    
    CC_SYNTHESIZE(Rect, mMovedRect, MovedRect);
    CC_SYNTHESIZE(bool, IsBlock, Block);
    CC_SYNTHESIZE(bool, mFlyState, FlyState);
};


#endif /* defined(__TanksWar__Bullet__) */
