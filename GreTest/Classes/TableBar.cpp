//
//  TableBar.cpp
//  GreTest
//
//  Created by lyy on 13-5-16.
//
//

#include "TableBar.h"
#include "AppMacros.h"
#include "ScriptParser.h"

#include "pSettingScene.h"
#include "S11PrepareResScene.h"
#include "S1MainScene.h"

#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点
#define rate1 1.0
#define rate2 1.0

#define fontName_macro "Thonburi"
#define titleFontSize_macro 40
#define fontSize_macro 20
#define gray_macro ccc3(168.0,168.0,168.0)
#define White_macro ccc3(255.0,255.0,255.0)
#define zNum 100

using namespace cocos2d;
using namespace std;

std::string TableBar::classPlistName = "";
int TableBar::mainItemNum = 0;
vector<string> TableBar::itemVec;
vector<string> TableBar::itemTitleVec;

CCScene* TableBar::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TableBar *layer = TableBar::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TableBar::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //每个项目都要创建的东西
    _menu = CCMenu::create(NULL);
    _menu->setPosition(CCPointZero);
    this->addChild(_menu, zNum+1);
    
    pTabBar = CCSprite::create("pTabBar.png");
    pTabBar->setPosition(ccp(1024.0,49.0));    
    this->addChild(pTabBar,zNum);

    
    m_highlightSp = CCSprite::create("pTabBarSelectedHighlight.png");


    string plistStr = TableBar::classPlistName;
    plistStr += ".plist";
    plistDic = CCDictionary::createWithContentsOfFile(plistStr.c_str());
    
    for (int i = 0; i<itemVec.size(); i++)
    {
        const char * picNameStr =  (itemVec[i]+".png").c_str();
        CCSprite * aSprite = CCSprite::create(picNameStr);
        
        if (i == TableBar::mainItemNum)
        {
            mainitemSprite = aSprite;
        }
        
        const char * positionName = itemVec[i].c_str();
        aSprite->setPosition(ScriptParser::getPositionFromPlist(plistDic,positionName));        
        this->addChild(aSprite,zNum);
        
        CCMenuItem * aItem = CCMenuItem::create(this, menu_selector(TableBar::menuselect));
        aItem->setPosition(aSprite->getPosition());
        aItem->setContentSize(m_highlightSp->getContentSize());
        _menu ->addChild(aItem,zNum);
        aItem->setTag(i);
        
        const char * itemTitleStr = itemTitleVec[i].c_str();
        CCLabelTTF* pLabel = CCLabelTTF::create(itemTitleStr,fontName_macro,fontSize_macro);
        if (i == TableBar::mainItemNum)
        {
            pLabel->setColor(White_macro);
        }
        else
        {
            pLabel->setColor(gray_macro);
        }

        const char * labelNameStr =  (itemVec[i]+"Label").c_str();
        pLabel->setPosition(ScriptParser::getPositionFromPlist(plistDic,labelNameStr));
        this->addChild(pLabel, zNum);
    }

    m_highlightSp->setPosition(ccp(mainitemSprite->getPosition().x,pTabBar->getPosition().y+pTabBar->getContentSize().height/2-50));
    this->addChild(m_highlightSp,zNum);
    m_highlightSp->setColor(ccc3(200, 200, 200));
    
    return true;
}


void TableBar::menuselect(CCObject* pSender)
{
    CCMenuItemSprite * aItem = (CCMenuItemSprite *)pSender;
    string className = itemTitleVec[aItem->getTag()];
 
    CCScene *newScene = CCScene::create();

    if(className.find("GRE模考")!= string::npos)
    {
        newScene->addChild(S1Main::create());
    }
    else if (className.find("备考资料")!= string::npos)
    {
        newScene->addChild(S11PrepareRes::create());
    }
    else if (className.find("设置")== string::npos)
    {
        newScene->addChild(pSetting::create());
    }
    
    resetSceneArgument();
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(0.0, newScene));
}
void TableBar::resetSceneArgument()
{
    TableBar::classPlistName = "";
    mainItemNum = 0;
    TableBar::itemVec.clear();
    TableBar::itemTitleVec.clear();
}

