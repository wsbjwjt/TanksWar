//
//  TileMapInfo.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#include "TileMapInfo.h"



TileMapInfo* TileMapInfo::createMapInfoWithFile(const char* tmxFile) {
    
    TileMapInfo* tileMapInfo = new TileMapInfo();
    tileMapInfo->initMapInfoWithFile(tmxFile);
    
    return tileMapInfo;
}
void TileMapInfo::initMapInfoWithFile(const char* tmxFile) {
    
}

bool TileMapInfo::collisionTest(Rect rect) {
    return true;
}
