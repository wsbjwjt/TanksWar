//
//  Paddle.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-16.
//
//

#ifndef __TanksWar__Paddle__
#define __TanksWar__Paddle__

#include "cocos2d.h"

USING_NS_CC;

typedef enum tagPaddleState {
    kPaddleStateGrabbed,
    kPaddleStateUngrabbed
} PaddleState;

class Paddle : public Sprite {
    
    CC_SYNTHESIZE(PaddleState, m_state, state);
public:
    Paddle();
    ~Paddle();
    
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchMoved(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    
    virtual bool initWithTextrue(Texture2D* pTexture);
    static Paddle* paddleWithTexture(Texture2D* pTexture);
    Rect rect();
    bool containTouchLocation(Touch* touch);
    
    virtual void onEnter();
    virtual void onExit();
    
};




#endif /* defined(__TanksWar__Paddle__) */
