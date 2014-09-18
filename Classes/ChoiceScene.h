//
//  ChoiceScene.h
//  TanksWar
//
//  Created by Eric Wang on 14-9-15.
//
//

#ifndef __TanksWar__ChoiceScene__
#define __TanksWar__ChoiceScene__

#include "cocos2d.h"
#include "Paddle.h"

USING_NS_CC;

class ChoiceScene : public cocos2d::Layer {
    
public:
    ChoiceScene();
    virtual bool init();
    CREATE_FUNC(ChoiceScene);
    
    static cocos2d::Scene *scene();
    
//    virtual void keyBackClicked(void);
//    virtual void keyMenuClicked(void);
    
    void touchDownAction(Ref* sender, unsigned int controlEvent);
    
private:
    void update();
    int mRound;
};







#endif /* defined(__TanksWar__ChoiceScene__) */
