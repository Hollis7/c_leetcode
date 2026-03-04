#include <iostream>
#include "list_node.h"
using namespace std;

int get_listnode_length(ListNode *head)
{
    int length = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}
ListNode *move_forward(ListNode *node, int step)
{
    while (step > 0)
    {
        node = node->next;
        step--;
    }
    return node;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    int a_len = get_listnode_length(headA);
    int b_len = get_listnode_length(headB);
    ListNode *pa = headA;
    ListNode *pb = headB;
    if (a_len > b_len)
    {
        pa = move_forward(pa, a_len - b_len);
    }
    else
    {
        pb = move_forward(pb, b_len - a_len);
    }
    while (pa != NULL)
    {
        if (pa == pb)
        {
            return pa;
        }
        else
        {
            pa = pa->next;
            pb = pb->next;
        }
    }
    return NULL;
}
/*
1、指针a和b两条链路都会走一遍，且如果相交最后一定会走到公共节点
2、如果不相交，两个指针都会为空，相等退出
*/
ListNode *getIntersectionNodeBetter(ListNode *headA, ListNode *headB)
{
    ListNode *pa = headA;
    ListNode *pb = headB;
    while (pa != pb)
    {
        pa = (pa == NULL ? headB : pa->next);
        pb = (pb == NULL ? headA : pb->next);
    }
    return pa;
}
int main()
{

    cout << __FILE__ << endl;
    return 0;
}