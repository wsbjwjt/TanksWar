//
//  ChoiceScene.cpp
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#include "ChoiceScene.h"
#include "CommonValue.h"
#include "MyPaddle.h"
#include "CityScene.h"

USING_NS_CC;


ChoiceScene::ChoiceScene() :mRound(1) {
    
}

Scene *ChoiceScene::scene() {
    
    Scene *scene = Scene::create();
    ChoiceScene *layer = ChoiceScene::create();
    if (scene && layer) {
        
        scene->addChild(layer);
    }
    return scene;
}


bool ChoiceScene::init() {
    
    if (!Layer::init()) {
        return false;
    }
    setKeypadEnabled(true);
    
    Size szWin = Director::getInstance()->getWinSize();
    Sprite *pSprite = Sprite::create("Black.png");
    pSprite->setPosition(Vec2(szWin.width / 2, szWin.height / 2));
    Size szSprite = pSprite->getContentSize();
    pSprite->setScaleX(szWin.width / szSprite.width);
    pSprite->setScaleY(szWin.height / szSprite.height);
    this->addChild(pSprite, 0);
    
    const char *szImgs[4] = {"paddle/btn_play.png", "paddle/btn_rewind.png", "paddle/btn_fast_forward.png", "fonts/fps_images.png"};
    float fSettings[4][4] = {
        {20.0f / 480, 16.0f / 320, 280.0f / 480, 160.0f / 320},
        {20.0f / 480, 16.0f / 320, 200.0f / 480, 160.0f / 320},
        {20.0f / 480, 16.0f / 320, 240.0f / 480, 160.0f / 320},
        {20.0f / 480, 22.0f / 320, 280.0f / 480, 172.0f / 320}
    };
    
    enum_evt evts[4] = {evt_start, evt_pressA, evt_pressB, evt_text};
    
    for (int i = 0; i < 3; ++i) {
        
        float* fSetting = fSettings[i];
        Texture2D* paddleTexture = Director::getInstance()->getTextureCache()->addImage(szImgs[i]);
        
        //Sprite* pPaddle = Sprite::createWithTexture(paddleTexture);
        MyPaddle* pPaddle = MyPaddle::paddleWithTexture(paddleTexture);
        Size szBtn = pPaddle->getContentSize();
        pPaddle->setScaleX(szWin.width / szBtn.width * fSetting[0]);
        pPaddle->setScaleY(szWin.height / szBtn.height * fSetting[1]);
        pPaddle->setPosition(Vec2(szWin.width * fSetting[2], szWin.height * fSetting[3]));
        this->addChild(pPaddle);
        
        pPaddle->setpScene(this);
        pPaddle->setevttyp(evts[i]);
        
    }
    
    int i = 3;
    Color3B color = {0, 0, 0};
    float* fSetting = fSettings[i];
    LabelAtlas* label1 = LabelAtlas::create("1", szImgs[i], 16, 32, '.');
    
    Size sz = label1->getContentSize();
    label1->setAnchorPoint(Vec2(0.5f, 0.5f));
    label1->setScaleX(szWin.width / sz.width * fSetting[0]);
    label1->setScaleY(szWin.height / sz.height * fSetting[1]);
    label1->setPosition(Vec2(szWin.width * fSetting[2], szWin.height * fSetting[3]));
    label1->setColor(color);
    this->addChild(label1, 0, evt_text);
    
    
    return true;
}

//void ChoiceScene::keyBackClicked(void) {
    
//}

//void ChoiceScene::keyMenuClicked(void) {
    
//}

void ChoiceScene::touchDownAction(Ref* sender, unsigned int controlEvent) {
    
    if (controlEvent == evt_pressA) {
        mRound = 1 + (mRound - 1 + ROUNDS - 1) % ROUNDS;
        update();
    }
    else if (controlEvent == evt_pressB) {
        mRound = 1 + (mRound + 1 + ROUNDS - 1) % ROUNDS;
    }
    else if (controlEvent == evt_start) {
        Scene* scene = CityScene::scene();
        Director::getInstance()->replaceScene(scene);
    }
}

void ChoiceScene::update() {
    
    char szTemp[260];
    LabelAtlas* label1 = (LabelAtlas* )getChildByTag(evt_text);
    sprintf(szTemp, "%d", mRound);
    label1->setString(szTemp);
}





















