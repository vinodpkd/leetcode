//2487. Remove Nodes From Linked List
/*
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.
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
    ListNode* removeNodes(ListNode* head) {
        std::vector<int> vec = ll2vec(head);
        std::vector<int> res{};
        for(int i = 0;i < vec.size()-1;i++)
        {
            int p = vec[i];
            int c = std::count_if(vec.begin()+i+1,vec.end(),[p](int n){return n > p;});
            if(0 == c)
                res.push_back(vec[i]);
        }
        res.push_back(vec[vec.size()-1]);

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
