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
        if(!head) return;

        //finding middle node
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=nullptr  && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reversing second half after middle node
        ListNode * current = slow->next;

        slow->next = nullptr;

        ListNode * prevptr = nullptr;
        ListNode * nextptr;
        while (current!= nullptr){
            nextptr = current->next;
            current->next = prevptr;

            prevptr = current;
            current = nextptr;
        }
        //merging both lists
        ListNode * first = head;
        current = prevptr;

        while(current!=nullptr){
            ListNode * temp1 = first->next;
            ListNode * temp2 = current->next;
            first->next = current;
            current->next = temp1;
            first = temp1;
            current = temp2;
        }
    }
};