//
//  CityScene.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-18.
//
//

#ifndef __TanksWar__CityScene__
#define __TanksWar__CityScene__

#include "cocos2d.h"
#include "Tank.h"
#include "TileMapInfo.h"


class CityScene : public Layer {
    
public:
    CityScene();
    ~CityScene();
    virtual bool init();
    virtual void onEnter();
    virtual void update(float delta);
    
    static Scene *scene();
    static Scene *scene(int round);
    CREATE_FUNC(CityScene);
    static CityScene *create(int round);
    
    CC_SYNTHESIZE(int, mRound, Round);
    
private:
    Tank* mPlayTank[2];
    
};

















#endif /* defined(__TanksWar__CityScene__) */
