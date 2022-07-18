
/*
    Time Complexity : O(n/2) + O(n/2)+ O(n/2);
    Space Complexity : O(1);
*/

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *prev = NULL, *nex = NULL, *cur = head;

    while (cur != NULL)
    {
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseLinkedList(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }

    return true;
}