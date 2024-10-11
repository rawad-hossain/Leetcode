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

Node *removeDuplicateOccurrences(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *front = head->next;
    Node *temp = head;

    while (front != NULL)
    {
        if (temp->data != front->data)
        {
            front = front->next;
            temp = temp->next;
        }

        else
        {
            temp->next = front->next;
            front = front->next;
        }
    }

    return head;
}