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
