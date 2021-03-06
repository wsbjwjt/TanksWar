//
//  Tank.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#ifndef __TanksWar__Tank__
#define __TanksWar__Tank__

#include "cocos2d.h"
#include "TileMapInfo.h"
#include "CommonValue.h"
#include "Panel.h"

USING_NS_CC;

class Tank : public Sprite {
    
public:
    Tank();
    ~Tank();
    
    static Tank* createTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo);
    void initTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo);
    bool command(enumOrder oder);
    void remove();
    void move();
    
    void setBlock(bool isBlock);
    bool getBlock();
    
private:
    bool mIsBlock;
    
    CC_SYNTHESIZE(TileMapInfo*, mTileMapInfo, TileMapInfo);
    
};






#endif /* defined(__TanksWar__Tank__) */
