
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

class Solution
{
    // reverse the nodes
    void reverse(ListNode *head, int times)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (times--)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

public:
    ListNode *swapPairs(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        int size = 2;

        ListNode *left = head;
        ListNode *right = nullptr;

        ListNode *prevLeft = nullptr;

        ListNode *newHead = nullptr;

        while (true)
        {

            // make right to come on first step
            right = left;

            // size - 1 , is bcz if size = 2
            // 2-1 =1 , thats the diff between left and right
            // ex: 3 & 4

            // so walk right foward by size - 1 times
            for (int i = 0; i < size - 1; i++)
            {
                if (right == nullptr)
                    break;

                right = right->next;
            }

            // left = 1
            // right = 2
            if (right)
            {

                // 3
                ListNode *nextLeft = right->next;

                // 2 -> 1 -> rest
                reverse(left, size);

                // connect previous left to new right
                // in second itration prevLeft =1 & right = 4

                if (prevLeft)
                {
                    // 1 -> 4
                    prevLeft->next = right;
                }

                // 1
                prevLeft = left;

                // make first right to be the new head
                if (newHead == nullptr)
                {
                    newHead = right;
                }

                // move left to new left
                left = nextLeft;
            }
            else
            {

                // means there is no right
                // aka odd list

                // in last ittreation prevLeft = 3 & left = 5
                if (prevLeft)
                {
                    // 3 -> 5
                    prevLeft->next = left;
                }

                break;
            }
        }

        return newHead;
    }
};

int main()
{
    ListNode *head = createLinkedList({1, 2, 3, 4, 5});

    Solution S;

    ListNode *ans = S.swapPairs(head);

    printLinkedList(ans);

    return 0;
}
