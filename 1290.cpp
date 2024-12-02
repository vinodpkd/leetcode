//1290. Convert Binary Number in a Linked List to Integer
/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
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
    int getDecimalValue(ListNode* head) {

        if(nullptr == head)
            return 0;

        ListNode* temp = new ListNode();
        temp = head;
        std::vector<int> d{};

        while(temp != nullptr)
        {
            d.push_back(temp->val);
            //std::cout << temp->val << ' ';
            temp = temp->next;
        }
        int num{0};
        int mul{1};
        for(int i = d.size()-1;i >= 0;i--)
        {
            num += d[i]*mul;
            mul = mul*2;
        }

        return num;
        
        
    }
};
