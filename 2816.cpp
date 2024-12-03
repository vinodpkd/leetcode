//2816. Double a Number Represented as a Linked List
/*
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.
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
    ListNode* doubleIt(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* r = reverseList(head);
        ListNode* s = r;
        ListNode* t;
        int c = 0;
        while(r != nullptr)
        {
            r->val += r->val + c;
            
            if(r->val > 9)
            {
                //std::cout << "if c = " << c << " r->val = " << r->val << '\n';
                c = 1;
                r->val -= 10;
                //std::cout << "if c = " << c << " r->val = " << r->val << '\n';
            }
            else
            {
                c = 0;
                //std::cout << "else c = " << c << " r->val = " << r->val << '\n';
            }

            if(r->next == nullptr)
            {
                t = r;
            }
            
            r = r->next;

            
        }

        //std::cout << "last c = " << c << '\n';

        if(c == 1)
        {
            t->next = new ListNode(1);            
        }

        s = reverseList(s);
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
