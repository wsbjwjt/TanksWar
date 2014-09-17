#include "HelloWorldScene.h"
#include "ChoiceScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    setKeypadEnabled(true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    MenuItemImage *pCloseItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width / 2,origin.y + visibleSize.height - pCloseItem->getContentSize().height / 2));
    Menu *pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu, 1);
    
    //创建游戏标题界面
    MenuItemImage *pItemPlay = MenuItemImage::create("playgameNormal.png", "playgameClose.png", CC_CALLBACK_1(HelloWorld::menuPlayGameCallback, this));
    pItemPlay->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 1.0f / 4.0f));
    pItemPlay->setScaleX(visibleSize.width / 600);
    pItemPlay->setScaleY(visibleSize.height / 400);
    
    Menu *pMenuPlay = Menu::create(pItemPlay, NULL);
    pMenuPlay->setPosition(Vec2::ZERO);
    this->addChild(pMenuPlay, 1);
    
    Sprite *pSprite = Sprite::create("ScenceStart.png");
    pSprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    Size size = pSprite->getContentSize();
    
    pSprite->setScaleX(visibleSize.width / size.width);
    pSprite->setScaleY(visibleSize.height / size.height);
    this->addChild(pSprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuPlayGameCallback(Ref* pSender) {
    
    Scene* pScene = ChoiceScene::scene();
    Director::getInstance()->pushScene(pScene);
}








