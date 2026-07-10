#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *createLinkedList(const std::vector<int> &arr);
void printLinkedList(ListNode *head);
void deleteLinkedList(ListNode *head);
void createCycle(ListNode *head, int pos);

#endif
