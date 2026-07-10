#include "linkedlist.h"
#include <iostream>

using namespace std;

ListNode *createLinkedList(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    return head;
}

void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

void createCycle(ListNode *head, int pos)
{
    if (head == nullptr || pos == -1)
        return;

    ListNode *cycleNode = nullptr;
    ListNode *tail = head;

    int index = 0;

    while (tail->next != nullptr)
    {
        if (index == pos)
            cycleNode = tail;

        tail = tail->next;
        index++;
    }

    if (index == pos)
        cycleNode = tail;

    tail->next = cycleNode;
}
