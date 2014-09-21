//
//  Panel.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-19.
//
//

#include "Panel.h"

bool Panel::init() {
    
    if (!Layer::init()) {
        return false;
    }
    Texture2D* paddleTexture = TextureCache::sharedTextureCache()->addImage(RES_PADDLE_UP);
    m_pPaddleUp = Paddle::paddleWithTexture(paddleTexture);
    
    paddleTexture = TextureCache::sharedTextureCache()->addImage(RES_PADDLE_DOWN);
    m_pPaddleDown = Paddle::paddleWithTexture(paddleTexture);
    
    paddleTexture = TextureCache::sharedTextureCache()->addImage(RES_PADDLE_LEFT);
    m_pPaddleLeft = Paddle::paddleWithTexture(paddleTexture);
    
    paddleTexture = TextureCache::sharedTextureCache()->addImage(RES_PADDLE_RIGHT);
    m_pPaddleRight = Paddle::paddleWithTexture(paddleTexture);
    
    paddleTexture = TextureCache::sharedTextureCache()->addImage(RES_PADDLE_FIRE);
    m_pPaddleFire = Paddle::paddleWithTexture(paddleTexture);
    
    Size size = getContentSize();
    
    //set up shoubing
    int localX[5] = {static_cast<int>(size.width*4.5f / 26), static_cast<int>(size.width*4.5f / 26), static_cast<int>(size.width*2.3f / 26), static_cast<int>(size.width*6.7f / 26), static_cast<int>(size.width*6.7 / 26)};
    int localY[5] = {static_cast<int>(size.height*6.7f / 26), static_cast<int>(size.height*2.3 / 26), static_cast<int>(size.height*4.5f / 26), static_cast<int>(size.height*4.5f / 26), static_cast<int>(size.height*5.0 / 26) };
    
    Paddle *paddle[] = {m_pPaddleUp, m_pPaddleDown, m_pPaddleLeft, m_pPaddleRight, m_pPaddleFire};
    
    for (int i = 0; i < sizeof(paddle) / sizeof(paddle[0]); ++i) {
        
        addChild(paddle[i]);
        paddle[i]->setPosition(Vec2(localX[i], localY[i]));
        Size szPaddle = paddle[i]->getContentSize();
        paddle[i]->setScale(size.height * 4.5 / 26 / szPaddle.height);
    }
    
    return true;
}

enumOrder Panel::getOrder() {
    
    enumOrder order = cmdNothing;
    if (m_pPaddleUp->getstate() == kPaddleStateGrabbed)
        order = cmdGoUP;
    else if (m_pPaddleDown->getstate() == kPaddleStateGrabbed)
        order = cmdGoDown;
    else if (m_pPaddleLeft->getstate() == kPaddleStateGrabbed)
        order = cmdGoLeft;
    else if (m_pPaddleRight->getstate() == kPaddleStateGrabbed)
        order = cmdGoRight;
    else if (m_pPaddleFire->getstate() == kPaddleStateGrabbed)
        order = cmdFire;
    
    return order;
}