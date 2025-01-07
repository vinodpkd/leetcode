//328. Odd Even Linked List
/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/
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
    ListNode* oddEvenList(ListNode* head) {
        // Handle edge cases
        if (!head || !head->next) {
            return head;
        }
        
        // Initialize pointers
        ListNode* odd = head;           // First node (1st)
        ListNode* even = head->next;    // Second node (2nd)
        ListNode* evenHead = even;      // Keep track of even list head
        
        // Rearrange nodes
        while (even && even->next) {
            // Connect odd nodes
            odd->next = even->next;
            odd = odd->next;
            
            // Connect even nodes
            even->next = odd->next;
            even = even->next;
        }
        
        // Connect odd list with even list
        odd->next = evenHead;
        
        return head;
    }
};
