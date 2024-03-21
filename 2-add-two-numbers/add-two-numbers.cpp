/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* current = dummyHead;
        ListNode* temp1 = num1;
        ListNode* temp2 = num2;

        int carry = 0;
        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            ListNode* addNode = new ListNode(sum % 10);
            carry = sum / 10;

            current->next = addNode;
            current = current->next;
        }

        if (carry) {
            ListNode* addNode = new ListNode(carry);
            current->next = addNode;
        }
        return dummyHead->next; // node starting after -1
    }
};