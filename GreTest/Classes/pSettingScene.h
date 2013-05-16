//
//  pSettingScene.h
//  GreTest
//
//  Created by lyy on 13-5-3.
//
//

#ifndef __GreTest__pSettingScene__
#define __GreTest__pSettingScene__

#include "cocos2d.h"
#include <string.h>
#include "cocos-ext.h"
//#include "TableBar.h"

class pSetting : public cocos2d::CCLayer,public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(pSetting);
    
private:
    cocos2d::CCMenu* _menu;
    cocos2d::CCDictionary* plistDic;
    cocos2d::CCLabelTTF *titleLabel;
    
    int selectIndex;
    std::map<std::string, std::string> aTTFStrMap;
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);

};

#endif /* defined(__GreTest__pSettingScene__) */
