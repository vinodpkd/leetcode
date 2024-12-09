//725. Split Linked List in Parts
/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts.
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<int> vec = ll2Vec(head);
        int n = vec.size();
	
	int units = n/k;
	int rem = n % k;
	
	//std::cout << "n = " << n << ", k = " << k << ", units = " << units << ", rem = " << rem << '\n'; 
	
	std::vector<int> parts(k,units);
	for(int i = 0;i < rem;i++)
	{
		parts[i]++;
	}
	
	//print(parts);
	
	std::vector<int> cumsum(parts.size());
	
	std::partial_sum(parts.begin(), parts.end(), cumsum.begin(), std::plus<int>());
	
	cumsum.insert(cumsum.begin(),0);
	
	//std::cout << "cumsum = ";
	//print(cumsum);
	
	//std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	
	std::vector<ListNode*> list{};
	
	/*
	std::vector<int> part1(parts[0]);
	
	std::copy(vec.begin(),vec.begin()+parts[0],part1.begin());
	
	print(part1);
	*/
	
	for(int i = 0;i < k;i++)
	{
		std::vector<int> partnow(parts[i]);
		std::copy(vec.begin()+cumsum[i],vec.begin()+cumsum[i+1],partnow.begin());
        ListNode* temp = vec2ll(partnow);
		list.push_back(temp);
	} 
	return list;
    }

     std::vector<int> ll2Vec(ListNode* l1)
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
