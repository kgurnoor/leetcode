/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // Add a dummy node to handle the case of removing the head
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advance the second pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            if (second == nullptr) { // Handle cases where n is larger than the list length (optional, but good practice)
                return head;
            }
            second = second->next;
        }

        // Move both pointers until the second pointer reaches the end
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Now the 'first' pointer is just before the node to be removed
        ListNode* nodeToRemove = first->next;
        first->next = nodeToRemove->next;
        delete nodeToRemove;

        ListNode* result = dummy->next;
        delete dummy; // Clean up the dummy node
        return result;
    }
};