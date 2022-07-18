#include <bits/stdc++.h>
using namespace std;

/*
       Time Complexity : O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2));
       Space Complexity : O(N);
    */

int getDiff(ListNode *headA, ListNode *headB)
{
    int len1 = 0, len2 = 0;
    while (headA != NULL)
    {
        len1++;
        headA = headA->next;
    }

    while (headB != NULL)
    {
        len2++;
        headB = headB->next;
    }

    return len1 - len2;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int dif = getDiff(headA, headB);

    if (dif < 0)
    {
        while (dif++ != 0)
            headB = headB->next;
    }
    else
        while (dif-- != 0)
            headA = headA->next;

    while (headA != NULL)
    {
        if (headA == headB)
            return headB;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

/*
    Time Complexity : O(2N);
    Space Complexity : O(N);
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, int> map;
    while (headA != NULL)
    {
        map[headA]++;
        headA = headA->next;
    }
    while (headB != NULL)
    {
        if (map[headB] > 0)
            return headB;
        headB = headB->next;
    }
    return NULL;
}