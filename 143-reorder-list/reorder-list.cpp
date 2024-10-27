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
    void reorderList(ListNode* head) {
        // Base case: If the list is empty or has only one or two nodes, no
        // reordering needed
        if (head == NULL)
            return;

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* current = slow->next;
        ListNode* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next; // Store the next node
            current->next = prev;     // Reverse the pointer
            prev = current;           // Move prev to current node
            current = nextNode;       // Move current to next node
        }
        slow->next = nullptr; // Break the original list into two halves

        // Merge the two halves of the linked list
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while (l1 && l2) {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            l1->next = l2;
            l2->next = p1;
            l1 = p1;
            l2 = p2;
        }
    }
};