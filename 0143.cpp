//143. Reorder List
/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(std::vector<int> v)
{
	for(int x : v)
		std::cout << x << ' ';
	
	std::cout << '\n';
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


int main()
{	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	
		std::vector<int> vec = ll2vec(head);
        std::vector<int> ev{};
        std::vector<int> ov{};
        int j = 0;
        for(int i = 0;i < vec.size()-1;i = i + 2)
        {
            ev.push_back(vec[i]);
            ov.push_back(vec[i+1]);            

        }

        int size = vec.size();

        if(size % 2 != 0)
            ev.push_back(vec[vec.size()-1]);

        std::reverse(ov.begin(),ov.end());
		
		std::cout << "Even ";
        print(ev);
		std::cout << "Odd ";
		print(ov);

        vec.clear();

        for(int i = 0;i < ov.size();i++)
        {
            vec.push_back(ev[i]);
            vec.push_back(ov[i]);
        }

        if(size % 2 != 0)
            vec.push_back(ev[ev.size()-1]);

       
		
		print(vec);
		
        head = vec2ll(vec);
	
	return 0;
}
