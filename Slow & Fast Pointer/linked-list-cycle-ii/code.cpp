
#include <iostream>
#include "../linkedlist.h"
#include "../linkedlist.cpp"

using namespace std;

int main()
{
    // head = [3,2,0,-4], pos = 1 at cycle starts
    ListNode *head = createLinkedList({3, 2, 0, -4});
    createCycle(head, 1);

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout << slow->val << endl;
            return 1;
        }
    }
    return 0;
}
