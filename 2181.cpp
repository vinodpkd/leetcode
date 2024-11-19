//2181. Merge Nodes in Between Zeros
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
    ListNode* mergeNodes(ListNode* head) {
        
        if(NULL == head)
            return head;
        std::vector<int> vec{};
        vec = ll2Vec(head);
        //std::cout << vec[0] << '\n';
        int size = vec.size();
        //std::cout << size << '\n';
        std::vector<int> sumvec{};
        int i = 1;
        int sum = 0;
        while(i < size)
        {
            if(vec[i] != 0)
            {
                //std::cout << "vec[i] != 0 " << vec[i] << '\n';
                sum += vec[i];
                //std::cout << "sum = " << sum << '\n';
            }
            else
            {
                sumvec.push_back(sum);
                //std::cout << "sumvec sum = " << sum << '\n';
                sum = 0;
            }
            i++;
        }

        //for(int x : sumvec)
            //std::cout << x << '\n';

        ListNode* res = vec2ll(sumvec);

        return res;
    }

    std::vector<int> ll2Vec(ListNode* t)
    {
        std::vector<int> num{};
        //ListNode* t = new ListNode();
        while(t != NULL)
        {
            num.push_back(t->val);
            t = t->next;
        }
        
        return num;
    }

    ListNode* vec2ll(std::vector<int>& num)
    {
        
        ListNode* t = new ListNode(num[0]);
		ListNode* s = new ListNode();
		s = t;
		int i = 1;
        while(i < num.size())
        {            
			ListNode* u = new ListNode(num[i]);
            t->next = u;
			t = u;
			i++;
        }
        
        return s;
    }
};
