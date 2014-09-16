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
    
    const char *szImgs[4] = {"paddle/btn_play.png", "paddle/btn_rewind.png", "paddle/btn_fast_forward.png", "fonts/fps_imgaes.png"};
    float fSettings[4][4] = {
        {20.0f / 480, 16.0f / 320, 280.0f / 480, 160.0f / 320},
        {20.0f / 480, 16.0f / 320, 200.0f / 480, 160.0f / 320},
        {20.0f / 480, 16.0f / 320, 240.0f / 480, 160.0f / 320},
        {20.0f / 480, 22.0f / 320, 280.0f / 480, 172.0f / 320}
    };
    
    for (int i = 0; i < 3; i ++) {
        
        float* fSetting = fSettings[i];
        Texture2D* paddleTexture = TextureCache::getInstance()->addImage(szImgs[i]);
        
        
    }
    
    
    
    
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





















