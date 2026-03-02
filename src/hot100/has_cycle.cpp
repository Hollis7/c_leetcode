#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include "list_node.h"
using namespace std;
bool hasCycle(ListNode *head)
{
    ListNode *fast_p = head;
    ListNode *low_p = head;
    bool is_cycle = false;
    if (head == NULL)
    {
        return false;
    }
    while (fast_p->next != NULL && fast_p->next->next != NULL)
    {
        fast_p = fast_p->next->next;
        low_p = low_p->next;
        if (fast_p == low_p)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    return 0;
}