//
//  TableBar.h
//  GreTest
//
//  Created by lyy on 13-5-16.
//
//

#ifndef __GreTest__TableBar__
#define __GreTest__TableBar__

#include "cocos2d.h"
#include <string.h>


class TableBar : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(TableBar);
    
    static std::string classPlistName;
    static int mainItemNum;
    static std::vector<std::string> itemVec;
    static std::vector<std::string> itemTitleVec;

private:
    
    cocos2d::CCMenu* _menu;
    cocos2d::CCDictionary* plistDic;
    cocos2d::CCSprite * pTabBar;
    cocos2d::CCSprite * mainitemSprite;
    cocos2d::CCSprite * m_highlightSp;

    void menuselect(CCObject* pSender);
    void resetSceneArgument();
};

#endif /* defined(__GreTest__TableBar__) */
