//
//  ChoiceScene.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#include "ChoiceScene.h"

using namespace cocos2d;

ChoiceScene::ChoiceScene() :mRound(1) {
    
}

bool ChoiceScene::init() {
    
    if (!Layer::init()) {
        return false;
    }
    setKeypadEnabled(true);
    
    Size winSize = Director::getInstance()->getWinSize();
    Sprite *pSprite = Sprite::create("Black.png");
    pSprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    Size szSprite = pSprite->getContentSize();
    pSprite->setScaleX(winSize.width / szSprite.width);
    pSprite->setScaleY(winSize.height / szSprite.height);
    this->addChild(pSprite, 0);
    
    const char *szImgs[4] = {"paddle/btn_play.png", "paddle/btn_rewind.png", "paddle/btn_fast_forward.png", "fonts/fps_images.png"};
    float fSettings[4][4] = {
        {20.0f / 480, 16.0f / 320, 280.0f / 480, 160.0f / 320},
        {20.0f / 480, 16.0f / 320, 200.0f / 480, 160.0f / 320},
        {20.0f / 480, 16.0f / 320, 240.0f / 480, 160.0f / 320},
        {20.0f / 480, 22.0f / 320, 280.0f / 480, 172.0f / 320}
    };
    
    for (int i = 0; i < 3; ++i) {
        
        float* fSetting = fSettings[i];
        Texture2D* paddleTexture = Director::getInstance()->getTextureCache()->addImage("Black.png");
        Sprite* pPaddle = Sprite::createWithTexture(paddleTexture);
        Size szBtn = pPaddle->getContentSize();
        pPaddle->setScaleX(winSize.width / szBtn.width * fSetting[0]);
        pPaddle->setScaleY(winSize.height / szBtn.height * fSetting[1]);
        pPaddle->setPosition(Vec2(winSize.width * fSetting[2], winSize.height * fSetting[3]));
        this->addChild(pPaddle);
        
    }
    
    int i = 3;
    Color3B color = {0, 0, 0};
    float* fSetting = fSettings[i];
    LabelAtlas* label1 = LabelAtlas::create("1", szImgs[i], 16, 32, '.');
    
    Size sz = label1->getContentSize();
    label1->setAnchorPoint(Vec2(0.5f, 0.5f));
    label1->setScaleX(winSize.width / sz.width * fSetting[0]);
    label1->setScaleY(winSize.height / sz.height * fSetting[1]);
    label1->setPosition(Vec2(winSize.width * fSetting[2], winSize.height * fSetting[3]));
    label1->setColor(color);
    this->addChild(label1, 0);
    
    
    return true;
}

Scene *ChoiceScene::scene() {
    
    Scene *scene = Scene::create();
    ChoiceScene *layer = ChoiceScene::create();
    if (scene && layer) {
        
        scene->addChild(layer);
    }
    return scene;
}



//void ChoiceScene::keyBackClicked(void) {
    
//}

//void ChoiceScene::keyMenuClicked(void) {
    
//}

void ChoiceScene::touchDownAction(Ref* sender, unsigned int controlEvent) {
    
}

void ChoiceScene::update() {
    
}





















