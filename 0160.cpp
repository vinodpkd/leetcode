//160. Intersection of Two Linked Lists
/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> s{};
        ListNode* temp = headA;
        while(temp != nullptr)
        {
            s.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp != nullptr)
        {
            if(s.contains(temp))
                return temp;
            temp = temp->next;
        }

        return nullptr;
    }
};

--------------
Python code to prove the concatenation of two lists
from random import sample
from copy import deepcopy

NN = 100
MM = 30

for i in range(100):

    m = sample(range(10,MM),1)[0]
    n = sample(range(10,MM),1)[0]
    p = sample(range(10,MM),1)[0]
    
    a = sample(range(NN),m)
    b = sample(range(NN),n)
    c = sample(range(NN),p)

    a.extend(c)
    b.extend(c)

    d = deepcopy(a)
    e = deepcopy(b)

    d.extend(b)
    e.extend(a)

    assert(len(d) == len(e))

    for i in range(p):
        assert(d[len(d)-1-i] == e[len(e)-1-i])
        
        
    


