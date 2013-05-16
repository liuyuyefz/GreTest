//
//  pSettingScene.cpp
//  GreTest
//
//  Created by lyy on 13-5-3.
//
//

#include "pSettingScene.h"

#include "TableBar.h"
#include "AppMacros.h"
#include "CustomTableViewCell.h"
#include "ScriptParser.h"


#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点

#define rate1 1.0
#define rate2 1.0

#define classPlistName_macro "Psetting.plist"
#define titleLabelStr_macro "设置"
#define s1FontName_macro "Thonburi"
#define s1TitleFontSize_macro 40
#define s1FontSize_macro 20
#define zNum 100

using namespace cocos2d;
using namespace std;
USING_NS_CC_EXT;

CCScene* pSetting::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    pSetting *layer = pSetting::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool pSetting::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //common initial
    
    _menu = CCMenu::create(NULL);
    _menu->setPosition(CCPointZero);
    this->addChild(_menu, zNum);

    plistDic = CCDictionary::createWithContentsOfFile(classPlistName_macro);
    
    //main logic

    {
        CCSprite * aSprite = CCSprite::create("pBackground.png");
        aSprite->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
        this->addChild(aSprite,zNum-1);
    }

    {
        CCSprite * aSprite = CCSprite::create("pNavBar.png");
        aSprite->setAnchorPoint(ccp(0.0,1.0));
        aSprite->setPosition(ccp(0,visibleSize.height-40));
        this->addChild(aSprite,zNum);
    }
    
    titleLabel = CCLabelTTF::create(titleLabelStr_macro,s1FontName_macro,s1TitleFontSize_macro);
    CCLabelTTF* pLabel = titleLabel;
    pLabel->setColor(ccWHITE);
    pLabel->setPosition( ScriptParser::getPositionFromPlist(plistDic,"titleLabel"));
    pLabel->setPosition( ccp( visibleSize.width/2,pLabel->getPosition().y));
    this->addChild(pLabel, zNum);
    
    aTTFStrMap = ScriptParser::paserScript(classPlistName_macro,"tableView");
    
    CCTableView* pTableView = CCTableView::create(this, CCSizeMake(100, 100));//ScriptParser::getSizeFromPlist(plistDic,"tableView"));
    pTableView->setDirection(kCCScrollViewDirectionVertical);
    pTableView->setPosition(ScriptParser::getPositionFromPlist(plistDic,"tableView"));
    pTableView->setDelegate(this);
    //   设置顺序是自上往下
    pTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    this->addChild(pTableView,1);
    pTableView->reloadData();
    
    //tableBar
    TableBar::classPlistName = classPlistName_macro;
    TableBar::mainItemNum = 2;

    TableBar::itemVec.push_back("pPencilIcon");
    TableBar::itemVec.push_back("pDocumentIcon");
    TableBar::itemVec.push_back("pSettingsIconActive");

    TableBar::itemTitleVec.push_back("GRE模考");
    TableBar::itemTitleVec.push_back("备考资料");
    TableBar::itemTitleVec.push_back("设置");
    
    TableBar * tableBar = TableBar::create();
    this->addChild(tableBar,zNum);
    
    return true;
}

void pSetting::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    //CCLOG("cell touched at index: %i  %i", cell->getIdx(),aTTFArry->count());
    selectIndex = cell->getIdx();
}

CCSize pSetting::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    return CCSizeMake(table->getContentSize().width, 30.0);
}

CCTableViewCell* pSetting::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell)
    {
        cell = new CustomTableViewCell();
        cell->autorelease();

        CCLabelTTF *label = CCLabelTTF::create("点击输入", "Helvetica", 30.0);
        label->setPosition(CCPointZero);
        // int to String
        ostringstream oss;
        oss<<idx;
        const char * labelStr = aTTFStrMap[oss.str()].c_str();
        label->setString(labelStr);
        label->setAnchorPoint(CCPointZero);
        label->setTag(123);
        cell->addChild(label);
        
        if (idx==0)
        {
            selectIndex=0;
        }
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
        string idxStr = CCString::createWithFormat("%d",idx)->getCString();
        map<string,string>::iterator aIterator = aTTFStrMap.find(idxStr);
        if (aIterator !=aTTFStrMap.end())
        {
            label->setString(aIterator->second.c_str());
        }
    }
    return cell;
}

unsigned int pSetting::numberOfCellsInTableView(CCTableView *table)
{
    return aTTFStrMap.size();
}
