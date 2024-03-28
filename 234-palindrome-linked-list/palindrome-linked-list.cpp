/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        /* reverse the rest list and put
          the first element at the end */
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        // STep-1: Find mid(slow) node of LL by tortoise and hare algo
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step - 2 : reverse nodes after slow/mid node
        ListNode* newHead = reverse(slow->next);

        // Step-3: Compare nodes before slow and after it(reversed one)
        ListNode* first = head;
        ListNode* second = newHead;
        
        while (second != NULL) {
            if (first->val != second->val) {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};