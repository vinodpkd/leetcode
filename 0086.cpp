//86. Partition List
/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        std::vector<int> vec = ll2vec(head);
       //the relative order of the elements is preserved.
        auto div = std::stable_partition(vec.begin(),vec.end(),[x](int n){return n < x;});
        head = vec2ll(vec);
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
