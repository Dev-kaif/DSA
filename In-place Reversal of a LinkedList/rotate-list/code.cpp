
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/rotate-list/

// O(n)
class Solution
{

    // Count the total number of nodes
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
        // No rotation needed for an empty or single-node list
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Calculate the total size of the linked list
        int size = SizeCalculate(head);

        // Remove unnecessary full rotation cycles
        k %= size;

        // No effective rotation needed
        if (k == 0)
            return head;

        ListNode *curr = head;

        // Position of the node that becomes the new tail
        int newTailPos = size - k;
        int currPos = 1;

        // Preserve the original head for final reconnection
        ListNode *oldHead = head;

        // Traverse to the new tail node
        while (currPos != newTailPos)
        {
            currPos++;
            curr = curr->next;
        }

        // Save the new tail and new head
        ListNode *newTailNode = curr;
        ListNode *newHead = curr->next;

        // Traverse to the original last node
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        ListNode *lastNode = curr;

        // Break the list after the new tail
        newTailNode->next = nullptr;

        // Connect the original tail to the original head
        lastNode->next = oldHead;

        // Return the new head of the rotated list
        return newHead;
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
