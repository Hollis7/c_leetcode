#include <iostream>
#include "list_node.h"
ListNode *reverseList(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

int main()
{
    return 0;
}