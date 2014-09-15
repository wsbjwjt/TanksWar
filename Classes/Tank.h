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

using namespace cocos2d;


class Tank : public Sprite {
    
public:
    Tank();
    ~Tank();
    
    static Tank* createTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo);
    
    
};






#endif /* defined(__TanksWar__Tank__) */
