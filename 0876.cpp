//876. Middle of the Linked List
/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
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
    ListNode* middleNode(ListNode* head) {
        int c{0};
        ListNode* temp = head;
        while(temp != nullptr)
        {
            c++;
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        while(i < c/2)
        {
            temp = temp->next;
            i++;
        }
        return temp;
    }
};
