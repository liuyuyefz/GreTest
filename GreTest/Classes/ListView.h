//
//  ListView.h
//  GreTest
//
//  Created by lyy on 13-5-17.
//
//
/*
#ifndef __GreTest__ListView__
#define __GreTest__ListView__

#include "cocos2d.h"
#include <string.h>
#include "cocos-ext.h"
NS_CC_EXT_BEGIN

class ListView : public cocos2d::extension::CCTableView,public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:
    ListView();
    virtual ~ListView();
*/    
    /**
     * An intialized table view object
     *
     * @param dataSource data source
     * @param size view size
     * @return table view
     */
/*    static ListView* create(ListView* dataSource, CCSize size);*/
    /**
     * An initialized table view object
     *
     * @param dataSource data source;
     * @param size view size
     * @param container parent object for cells
     * @return table view
     */
  /*  static ListView* create(ListView* dataSource, CCSize size, CCNode *container);

    bool initWithViewSize(CCSize size, CCNode* container = NULL);
    
    
    int selectIndex;
    std::map<std::string, std::string> aTTFStrMap;
    float cellSize;
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {};
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
    
};
#endif*/ /* defined(__GreTest__ListView__) */
