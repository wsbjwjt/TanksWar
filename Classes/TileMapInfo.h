//
//  TileMapInfo.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#ifndef __TanksWar__TileMapInfo__
#define __TanksWar__TileMapInfo__

#include "cocos2d.h"

USING_NS_CC;

enum enumTileType {
    
    tileNone, tileGrass,
    tileSteel, tileWall,
    tileRiver, tileKing
};

//根据地图中gid获取对应的tile的类型
static enumTileType gidToTileType[] =
{
	tileNone,
    
	tileNone, tileNone, tileGrass, tileGrass, tileSteel, tileSteel,
	tileNone, tileNone, tileGrass, tileGrass, tileSteel, tileSteel,
    
	tileWall, tileWall, tileRiver, tileRiver, tileKing, tileKing,
	tileWall, tileWall, tileRiver, tileRiver, tileKing, tileKing,
    
	tileKing, tileKing, tileNone, tileNone, tileNone, tileNone,
	tileKing, tileKing, tileNone, tileNone, tileNone, tileNone
};

class TileMapInfo {
    
public:
    bool collisionTest(Rect rect);
    
    static TileMapInfo* createMapInfoWithFile(const char* tmxFile);
    void initMapInfoWithFile(const char* tmxFile);
    CC_SYNTHESIZE(TMXTiledMap*, mTMXTileMap, TileMap);
    
private:
    TMXLayer* mTMXLayers[2];
    
};


#endif /* defined(__TanksWar__TileMapInfo__) */
