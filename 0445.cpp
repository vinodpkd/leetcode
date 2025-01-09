//445. Add Two Numbers II
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* one = reverseList(l1);
        ListNode* two = reverseList(l2);
        ListNode* sum = addTwoNumbers_1(one,two);
        return reverseList(sum);
    }
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {

        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;

        ListNode *p = l1, *q = l2, *r, *s;
        r = new ListNode(0);
        s = r;
        int c{0};
        while(p != nullptr || q != nullptr)
        {
            if(p != nullptr && q != nullptr)
            {
                r->val = p->val + q->val + c;
                p = p->next;
                q = q->next;
                
            }                
            else if(p == nullptr)
            {
                r->val = q->val + c;
                q = q->next;
                
            }
            else if(q == nullptr)
            {
                r->val = p->val + c;
                p = p->next;
        
            }
            c = 0;
            if(9 < r->val)
            {
                c = 1;
                r->val = r->val - 10;
            }
            if(p != nullptr || q != nullptr)// || (1 == c)
            {
                ListNode* t = new ListNode(0);
                r->next = t;
                r = t;
            }
            
            
        }

        if(1 == c)
        {
            
            ListNode* t = new ListNode(c);
            r->next = t;
            r = t;
            
            
        }

        return s;

    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
        
    }
};
