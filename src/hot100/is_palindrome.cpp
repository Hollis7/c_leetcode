#include <iostream>
#include "list_node.h"
using namespace std;
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

bool isPalindrome(ListNode *head)
{
    if (head == NULL)
        return false;
    int len = 0;
    int halfLen = 0;
    ListNode *fast = head;
    ListNode *low = head;
    ListNode *new_p = NULL;
    /* get len */
    while (low != NULL)
    {
        low = low->next;
        len++;
    }
    /* reset low */
    low = head;

    /* move fast */
    halfLen = len / 2;
    while (halfLen > 0)
    {
        fast = fast->next;
        halfLen--;
    }

    /* reset halfLen and reverse */
    halfLen = len / 2 - 1;
    new_p = reverseList(fast);
    while (halfLen >= 0)
    {
        if (new_p->val != low->val)
        {
            return false;
        }
        new_p = new_p->next;
        low = low->next;
        halfLen--;
    }
    return true;
}

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    cout << "result: " << isPalindrome(node1) << endl;
}