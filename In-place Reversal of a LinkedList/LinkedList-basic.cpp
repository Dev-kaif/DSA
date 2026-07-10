#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode *next;

    ListNode() : value(0), next(nullptr) {}

    ListNode(int x) : value(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : value(x), next(next) {}
};

int main()
{
    ListNode *First = new ListNode(3);
    ListNode *Second = new ListNode(10);

    // making first pointer's next point to Seconds address
    // (*First).next = Second;
    First->next = Second;

    // print Linked list
    ListNode *temp = First;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    delete First;

    // the pointers still contain old addresses:
    // cout << First->value; which is Undefined behavior!
    // so we point it to null to be safe
    First = nullptr;

    delete Second;
    Second = nullptr;
}