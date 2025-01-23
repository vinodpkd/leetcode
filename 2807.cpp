//2807. Insert Greatest Common Divisors in Linked List
/*
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/
----------
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

       ListNode* temp = head;
        while(temp->next)
        {
            int a = std::gcd(temp->val,temp->next->val);
            
            ListNode* mid = new ListNode(a);
            
            
            mid->next = temp->next;
			temp->next = mid;
            
			temp = mid->next;
            //std::cout << a << ' ';
        }

        return head;
    }
};
--------------
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr)
            return head;

        std::vector<int> vec = ll2vec(head);
        std::vector<int> g(vec.size()-1,0);
        for(int i = 1;i < vec.size();i++)
        {
            g[i-1] = std::gcd(vec[i],vec[i-1]);
        }

        std::vector<int> res(g.size()+vec.size());
        int j = 0;
        for(int i = 0;i < res.size()-1;i = i + 2)
        {
            res[i] = vec[j];
            res[i+1] = g[j];
            j++;
        }
        res[res.size()-1] = vec[vec.size()-1];

        head = vec2ll(res);
        return head;
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
