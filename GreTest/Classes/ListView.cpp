//
//  ListView.cpp
//  GreTest
//
//  Created by lyy on 13-5-17.
//
//
/*
#include "ListView.h"
#include "AppMacros.h"
#include "CustomTableViewCell.h"


using namespace cocos2d;
using namespace std;
USING_NS_CC_EXT;

ListView* ListView::create(ListView* dataSource, CCSize size)
{
    return ListView::create(dataSource, size, NULL);
}

ListView* ListView::create(ListView* dataSource, CCSize size, CCNode *container)
{
    ListView *listView = new ListView();
    listView->initWithViewSize(size, container);
    listView->autorelease();
    
    return listView;
}
*/
//bool ListView::initWithViewSize(CCSize size, CCNode* container/* = NULL*/)
/*{
    if (CCTableView::initWithViewSize(size,container))
    {
        return true;
    }
    return false;
}

ListView::ListView()
{
    ;
}

ListView::~ListView()
{
    ;// CC_SAFE_DELETE(m_pIndices);
}

void ListView::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    selectIndex = cell->getIdx();
}

CCSize ListView::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    return CCSizeMake(table->getContentSize().width, cellSize);
}

CCTableViewCell* ListView::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell)
    {
        cell = new CustomTableViewCell();
        cell->autorelease();
        
        CCLabelTTF *label = CCLabelTTF::create("", "Helvetica", cellSize);
        label->setPosition(CCPointZero);
        const char * labelStr = "";
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

unsigned int ListView::numberOfCellsInTableView(CCTableView *table)
{
    return aTTFStrMap.size();
}
*/
