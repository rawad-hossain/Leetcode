/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *back;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->back = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->back = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *back) {
 *          this->data = data;
 *          this->back = back;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *deleteAllOccurrences(Node *head, int k)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->data == k)
        {
            if (temp == head)
                head = head->next;

           Node * front = temp->next;
           Node * prev = temp->back;

            if (front)
                front->back = prev;
            if (prev)
                prev->next = front;
            delete temp;
            temp = font;
        }
        else
            temp = temp->next;


    }        return head;
}
