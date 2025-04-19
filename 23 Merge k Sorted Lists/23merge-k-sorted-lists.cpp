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
    // Line 12: Defines a custom comparator struct for the min-heap.
    struct CompareListNode {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; // Returns true if a's value is greater than b's, for a min-heap.
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, CompareListNode> minHeap;
        // Line 18: Declares a priority queue named 'minHeap'.
        //          - 'ListNode*': Specifies that the priority queue will store pointers to ListNode objects.
        //          - 'vector<ListNode*>': Specifies the underlying container to be used by the priority queue (a vector of ListNode pointers).
        //          - 'CompareListNode': Specifies the custom comparator struct to be used by the priority queue to order elements (min-heap).
        for (ListNode* list : lists) { // Line 19: Iterates through each ListNode pointer 'list' in the input vector 'lists'.
            if (list) {                // Line 20: Checks if the current list is not a null pointer (i.e., the list is not empty).
                minHeap.push(list);    // Line 21: If the list is not empty, its head node ('list') is pushed onto the 'minHeap'.
            }
        }
        if (minHeap.empty()) {       // Line 23: Checks if the 'minHeap' is empty. This would happen if the input 'lists' was empty or contained only empty lists.
            return nullptr;          // Line 24: If the 'minHeap' is empty, it means there are no nodes to merge, so the function returns a null pointer.
        }
        ListNode* mergedHead = minHeap.top(); // Line 26: Retrieves the node with the smallest value (the top element of the min-heap) and assigns its pointer to 'mergedHead', which will be the head of the merged list.
        minHeap.pop();                     // Line 27: Removes the smallest node from the 'minHeap'.
        ListNode* current = mergedHead;     // Line 28: Creates a pointer 'current' and initializes it to 'mergedHead'. This pointer will be used to build the merged list.
        if (mergedHead->next) {            // Line 29: Checks if the initial head of the merged list has a next node.
            minHeap.push(mergedHead->next); // Line 30: If it does, the next node of the initial head is pushed onto the 'minHeap' for subsequent comparison.
        }
        while (!minHeap.empty()) {      // Line 32: Continues the loop as long as the 'minHeap' is not empty, meaning there are still nodes to be added to the merged list.
            ListNode* smallest = minHeap.top(); // Line 33: Retrieves the node with the smallest value from the 'minHeap'.
            minHeap.pop();                     // Line 34: Removes the smallest node from the 'minHeap'.
            current->next = smallest;        // Line 35: Appends the 'smallest' node to the end of the merged list by making the 'next' pointer of the current last node point to it.
            current = smallest;              // Line 36: Moves the 'current' pointer to the newly added node, which is now the last node of the merged list.
            if (smallest->next) {           // Line 37: Checks if the newly added node has a next node.
                minHeap.push(smallest->next); // Line 38: If it does, the next node is pushed onto the 'minHeap'.
            }
        }
        return mergedHead; // Line 41: Returns the pointer to the head of the fully merged and sorted linked list.
    }
};