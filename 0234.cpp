//234. Palindrome Linked List
/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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
    bool isPalindrome(ListNode* head) {
        std::vector<int> vec = ll2vec(head);
        for(int i = 0;i < vec.size()/2;i++)
        {
            if(vec[i] != vec[vec.size()-1-i])
                return false;
        }
        return true;
    }

    std::vector<int> ll2vec(ListNode* l1)
    {
        std::vector<int> num{};
        ListNode* t = l1;
        while(t != nullptr)
        {
            num.push_back(t->val);
            t = t->next;
        }
        
        return num;
    }

    ListNode* vec2ll(std::vector<int>& num)
    {
	    if(num.empty())
            	return nullptr;
        
        ListNode* t = new ListNode(num[0]);
		ListNode* s = new ListNode();
		s = t;
		int i = 1;
        while(i < num.size())
        {            
			ListNode* u = new ListNode(num[i]);            
			t->next = u;
            t = t->next;
			i++;
        }
        
        return s;
    }
};

----------------------
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
    bool isPalindrome(ListNode* head) {
        std::stack<int> s{};
        ListNode* temp = head;
        while(temp)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp)
        {
            if(temp->val == s.top())
            {
                temp = temp->next;
                s.pop();
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
