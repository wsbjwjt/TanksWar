//
//  MyPaddle.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-22.
//
//

#include "MyPaddle.h"

MyPaddle::MyPaddle() :bFlag(false) {
    
}

MyPaddle::~MyPaddle() {}

MyPaddle* MyPaddle::paddleWithTexture(Texture2D* pTexture) {
    
    MyPaddle* pPaddle = new MyPaddle();
    pPaddle->initWithTextrue(pTexture);
    pPaddle->autorelease();
    return pPaddle;
}

bool MyPaddle::onTouchBegan(Touch *touch, Event *event) {
    
    if (Paddle::onTouchBegan(touch, event)) {
        bFlag = true;
        return true;
    }
    return false;
}

void MyPaddle::onTouchEnded(Touch *touch, Event *event) {
    
    Paddle::onTouchEnded(touch, event);
    if (bFlag) {
        bFlag = false;
        m_pScene->touchDownAction(this, m_evttyp);
    }
}