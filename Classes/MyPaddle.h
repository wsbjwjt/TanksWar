//
//  MyPaddle.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-22.
//
//

#ifndef __TanksWar__MyPaddle__
#define __TanksWar__MyPaddle__

#include "cocos2d.h"
#include "Paddle.h"
#include "ChoiceScene.h"

enum enum_evt {

    evt_start,
    evt_pressA,
    evt_pressB,
    evt_text
};

class MyPaddle : public Paddle {
    CC_SYNTHESIZE(enum_evt, m_evttyp, evttyp);
    CC_SYNTHESIZE(ChoiceScene*, m_pScene, pScene);
    
public:
    MyPaddle();
    ~MyPaddle();
    
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    
    static MyPaddle* paddleWithTexture(Texture2D* pTexture);
private:
    bool bFlag;
};







#endif /* defined(__TanksWar__MyPaddle__) */
