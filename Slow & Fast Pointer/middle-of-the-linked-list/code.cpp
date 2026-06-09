
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

// https://leetcode.com/problems/middle-of-the-linked-list/description/

int main()
{
    // head = [1,2,3,4,5]
    ListNode *head = createLinkedList({1, 2, 3, 4, 5});

    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->val << endl;
    return 0;
}
