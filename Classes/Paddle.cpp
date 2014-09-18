//
//  Paddle.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-16.
//
//

#include "Paddle.h"


Paddle::Paddle(){}
Paddle::~Paddle(){}

bool Paddle::onTouchBegan(Touch *touch, Event *event) {
    
    if (m_state != kPaddleStateGrabbed) return false;
    if (!containTouchLocation(touch)) return false;
    
    m_state = kPaddleStateGrabbed;

    return true;
}

void Paddle::onTouchMoved(Touch *touch, Event *event) {
    
}
void Paddle::onTouchEnded(Touch *touch, Event *event) {
    
    m_state = kPaddleStateGrabbed;
}

bool Paddle::initWithTextrue(Texture2D* pTexture) {
    
    if (Sprite::initWithTexture(pTexture)) {
        m_state = kPaddleStateGrabbed;
    }
    return true;
}
Paddle* Paddle::paddleWithTexture(Texture2D* pTexture) {
    
    Paddle *pPaddle = new Paddle();
    pPaddle->initWithTextrue(pTexture);
    pPaddle->autorelease();
    
    return pPaddle;
}

Rect Paddle::rect() {
    
    Size size = getTexture()->getContentSize();
    return CCRectMake(-size.width / 2, -size.height / 2, size.width, size.height);
}

bool Paddle::containTouchLocation(Touch* touch) {
    Vec2 vec = convertTouchToNodeSpaceAR(touch);
    return rect().containsPoint(vec);
}

void Paddle::onEnter() {
    
    Director *pDirector = Director::getInstance();
    
}
void Paddle::onExit() {
    
}
