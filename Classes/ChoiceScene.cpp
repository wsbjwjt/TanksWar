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

Scene *ChoiceScene::scene() {
    
    Scene *scene = Scene::create();
    ChoiceScene *layer = ChoiceScene::create();
    if (scene && layer) {
        
        scene->addChild(layer);
    }
    return scene;
}

bool ChoiceScene::init() {
    
    
    return true;
}

//void ChoiceScene::keyBackClicked(void) {
    
//}

//void ChoiceScene::keyMenuClicked(void) {
    
//}

void ChoiceScene::touchDownAction(Ref* sender, unsigned int controlEvent) {
    
}

void ChoiceScene::update() {
    
}





















