
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/reverse-linked-list-ii/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right || head == nullptr)
        {
            return head;
        }

        int pos = 1;
        ListNode *curr = head;
        ListNode *prev = nullptr;

        ListNode *before = nullptr;
        ListNode *after = nullptr;

        ListNode *leftptr = nullptr;
        ListNode *rightptr = nullptr;

        while (curr != nullptr && pos != left)
        {
            ListNode *next = curr->next;
            prev = curr;
            curr = next;
            pos++;
        }

        // 1
        before = prev;

        // 2
        leftptr = curr;

        prev = nullptr;

        // curr is on left
        // prev is on left before

        while (curr != nullptr && pos <= right)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        // 4
        rightptr = prev;

        // 5
        after = curr;

        if (before == nullptr)
        {
            // `left == 1`, so 4 becomes the new head
            head = rightptr;
        }
        else
        {
            // 1->4
            before->next = rightptr;
        }

        // 2->5
        leftptr->next = after;

        return head;
    }
};

int main()
{
    ListNode *head = createLinkedList({1, 2, 3, 4, 5});
    int left = 2, right = 4;

    Solution S;

    ListNode *ans = S.reverseBetween(head, left, right);

    printLinkedList(ans);

    return 0;
}
