#pragma

#ifndef __Array_LIST_H__
#define __Array_List_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist);

void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);

int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);

LData LCount(List* plist);


#endif // !__Array_LIST_H__
