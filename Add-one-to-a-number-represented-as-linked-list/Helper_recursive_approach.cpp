/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

class Solution {
public:
    int addhelper(Node* temp) {
        if (temp == NULL)
            return 1;

        int carry = addhelper(temp->next);
        temp->data = temp->data + carry;

        if (temp->data < 10)
            return 0;

        temp->data = 0;
        return 1; // i.e carry is 1 which is returned to addNode func
    }

    Node* addOne(Node* head) {
        int carry = addhelper(head);
        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode; // head changed to carry, carry redirected to old head
        }
        return head;
    }
};
