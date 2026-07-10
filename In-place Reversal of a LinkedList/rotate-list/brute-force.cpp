
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/rotate-list/

// O(n × k)
class Solution
{
    int SizeCalculate(ListNode *head)
    {
        int n = 0;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }

        return n;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Calculate the size of the linked list
        int size = SizeCalculate(head);

        // Remove unnecessary full rotation cycles.
        //
        // Example: size = 3, k = 3
        // After 3 rotations, the list returns to its original state.
        //
        // Example: size = 3, k = 4
        // The first 3 rotations form one complete cycle,
        // so only 1 effective rotation is needed.
        //
        // Therefore:
        // 4 % 3 = 1
        k %= size;

        if (k == 0)
            return head;

        ListNode *curr = head;

        while (k--)
        {
            // Save the current head before moving the last node
            ListNode *firstNode = curr;

            // Reset for each rotation
            ListNode *prev = nullptr;

            // Traverse to the last node
            while (curr->next != nullptr)
            {
                ListNode *nextNode = curr->next;
                prev = curr;
                curr = nextNode;
            }

            // prev = second-last node
            // curr = last node

            // Detach the last node
            prev->next = nullptr;

            // Move the last node to the front
            curr->next = firstNode;
        }

        // curr is the new head
        return curr;
    }
};

int main()
{
    ListNode *head = createLinkedList({1, 2, 3, 4, 5, 6});
    int k = 2;

    Solution S;

    ListNode *ans = S.rotateRight(head, k);

    printLinkedList(ans);

    return 0;
}
