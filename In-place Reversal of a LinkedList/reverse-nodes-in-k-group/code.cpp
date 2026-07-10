
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class Solution
{
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        int size = k;
        ListNode *left = head;
        ListNode *right = nullptr;
        ListNode *prevLeft = nullptr;
        ListNode *newHead = nullptr;

        while (true)
        {
            right = left;
            for (int i = 0; i < size - 1; i++)
            {
                if (right == nullptr)
                    break;

                right = right->next;
            }

            if (right)
            {
                ListNode *nextLeft = right->next;
                reverse(left, size);
                if (prevLeft)
                {
                    prevLeft->next = right;
                }
                prevLeft = left;
                if (newHead == nullptr)
                {
                    newHead = right;
                }

                left = nextLeft;
            }
            else
            {
                if (prevLeft)
                {
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
    ListNode *head = createLinkedList({1});
    int k = 1;

    Solution S;

    ListNode *ans = S.reverseKGroup(head, k);

    printLinkedList(ans);

    return 0;
}
