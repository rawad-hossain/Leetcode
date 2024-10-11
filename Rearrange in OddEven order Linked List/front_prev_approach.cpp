#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val, Node *nextAdd)
    {
        data = val;
        next = nextAdd;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *oddEvenList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *front = head;
    Node *prev = head->next;

    Node *Even_head = prev;

    while (prev != NULL && prev->next != NULL)
    {
        front->next = front->next->next;
        front = front->next;

        prev->next = prev->next->next;
        prev = prev->next;
    }

    front->next = Even_head;

    return head;
}