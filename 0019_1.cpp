//19. Remove Nth Node From End of List
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);
        ListNode* temp = head;
        if(1 == n)
        {
            head = head->next;
            delete temp;
            return reverseList(head);
        }
        else
        {
            int i = 1;
            while(true)
            {
                if(i == n-1)
                    break;
                temp = temp->next;
                i++;
                
            }

            ListNode* r = temp->next;
            temp->next = r->next;
            delete r;
            return reverseList(head);
        }

        head = reverseList(head);
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
        
    }
};
