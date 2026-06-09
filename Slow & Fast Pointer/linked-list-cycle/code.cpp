#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/linked-list-cycle/description/

int main()
{
    // head = [3,2,0,-4], pos = 1
    ListNode *head = createLinkedList({3, 2, 0, -4});
    createCycle(head, 1);

    ListNode *fast = head;
    ListNode *slow = head;

    bool hasCycle = false;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            hasCycle = true;
            break;
        }
    }

    cout << (hasCycle ? "true" : "false") << endl;

    return 0;
}
