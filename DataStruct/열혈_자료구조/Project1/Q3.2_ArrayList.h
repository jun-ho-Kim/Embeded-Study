#pragma once
#ifdef  __Array_List_NameCard_H__
#define __Array_List_NameCard_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

NameCard * MakeNameCard(char* name, char* phone);

void ShowNameCardInfo(NameCard * pcard);

#endif //  __Array_List_NameCard_H__
