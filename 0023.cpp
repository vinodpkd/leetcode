

class Solution {
public:

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.empty())
			return NULL;
		
		if(1 == lists.size())
			return lists[0];
		
		bool flag = false;
		
		std::multiset<int> mset {};
		
		for(int i = 0;i < lists.size();i++)
		{
			if(NULL == lists[i])
                {flag = true;break;}

            if(lists[i]->next == NULL)
			{
				mset.insert(lists[i]->val);
			}
			else
			{
				flag = true;
				break;
			}			
		}
		
		if(false == flag)
		{
			struct ListNode* combined = createLL_from_set(mset);
			return combined;
		}
		
		for(int i = 1;i < lists.size();i++)
		{
			
			lists[i] = mergeTwoLists(lists[i-1], lists[i]);
			
		}		
			
		return 	lists[lists.size()-1];
	}

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(NULL == list1 && NULL == list2)
            return NULL;

        std::multiset<int> listOne = list_to_set(list1);
        std::multiset<int> listTwo = list_to_set(list2);
        
        listTwo.merge(listOne);

        ListNode* merged = createLL_from_set(listTwo);

        return merged;

    }


std::multiset<int> list_to_set(struct ListNode *first)
{
	std::multiset<int> set;
    //struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *p  = new ListNode();
    p = first;
    while(p != NULL)
    {
        //std::cout << p->val << '\n';
		set.insert(p->val);
        p = p->next;
    }
	
	return set;	
}

struct ListNode* createLL_from_set(std::multiset<int>& A)
{
    struct ListNode *temp , *last;
    struct ListNode *one;
    //one = (struct ListNode *)malloc(sizeof(struct ListNode));
    one = new ListNode();
	auto it = A.begin();
    one->val = *it;
    one->next = NULL;
    last = one;
    //std::cout << one->val << '\n';
    for (it = std::next(A.begin());it != A.end();it++)
    {
        //temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = new ListNode();
        temp->val = *it;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        //std::cout << last->val << '\n';
    }

    return one;
}

};
