
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/swap-nodes-in-pairs/description/

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *left = head;
        ListNode *right = nullptr;

        ListNode *prevLeft = nullptr;
        ListNode *nextLeft = nullptr;

        ListNode *currHead = head->next;

        while (left != nullptr && left->next != nullptr)
        {
            // left = 1

            // 2
            right = left->next;

            // Connect previous swapped pair to current pair
            if (prevLeft)
                // 1 -> 4 (2nd iteration)
                prevLeft->next = right;

            // 3
            nextLeft = right->next;

            // 2 -> 1
            right->next = left;

            // 1 -> 3
            left->next = nextLeft;

            // Save tail of current swapped pair
            // 1
            prevLeft = left;

            // Move to next pair
            left = nextLeft;
        }

        return currHead;
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
