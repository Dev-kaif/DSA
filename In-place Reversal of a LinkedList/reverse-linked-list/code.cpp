
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/reverse-linked-list/description/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != nullptr)
        {
            // store next adres
            ListNode *next = curr->next;

            // change address of next node to previous one
            curr->next = prev;

            // move previous to current
            prev = curr;

            // move current to next
            curr = next;
        }

        return prev;
    }
};


int main()
{
    ListNode *head = createLinkedList({1, 2, 3, 4, 5});

    Solution S;

    ListNode *ans = S.reverseList(head);

    printLinkedList(ans);
}
