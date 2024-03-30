#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int addOneHelper(Node *head, k)
{

    // If linked list is empty, return carry.
    if (head == NULL)
    {
        return k;
    }

    // Add carry obtained from next node to current node data.
    int carry =  addOneHelper(head->next)
    int res = head->data + carry;

    // Update data and return new carry(to add to the previous node).
    head->data = (res) % 10;
    return (res) / 10;
}

Node *addAnyNumber(Node *head. int k)
{
    // Removing leading zeroes
    while (head != NULL && head->data == 0)
    {
        head = head->next;
    }
    int carry = addOneHelper(head, k);

    // If there is carry after processing all nodes,add a new node at the beginning of the linked list.
    if (carry)
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode
    }
  
    return head;
}
