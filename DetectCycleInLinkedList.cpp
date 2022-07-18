#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(N) in worst case if no cycle is available
    Space Complexity : O(1);
*/
bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}