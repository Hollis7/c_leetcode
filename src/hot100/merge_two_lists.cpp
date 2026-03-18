#include <iostream>
#include "list_node.h"
using namespace std;
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode *head;
    head = list1->val <= list2->val ? list1 : list2;
    ListNode *cur = head;
    ListNode *tmp1 = NULL;
    ListNode *tmp2 = NULL;

    if (head == list1)
    {
        list1 = list1->next;
    }
    else
    {
        list2 = list2->next;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            cur->next = list1;
            cur = cur->next;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            cur = cur->next;
            list2 = list2->next;
        }
    }
    cur->next = list1 ? list1 : list2;
    return head;
}