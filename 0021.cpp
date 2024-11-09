#include <bits/stdc++.h>

struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

std::list<int> vector_to_list(const std::vector<int> n)
{
	std::list<int> list1(n.size());
	
	int i = 0;
	for(std::list<int>::iterator it = list1.begin();it != list1.end();it++)
	{
		*it = n[i];
		i++;
	}
	
	return list1;
}

std::vector<int> list_to_vector(const std::list<int> n)
{
	std::vector<int> vec(n.size());
	
	int i = 0;
	for(auto it = n.begin();it != n.end();it++)
	{
		vec[i] = *it;
		i++;
	}
	
	return vec;
}

std::list<int> create_list(struct ListNode* first)
{
	std::vector<int> vec;
    struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = first;
    while(p != NULL)
    {
        std::cout << p->val << '\n';
		vec.push_back(p->val);
        p = p->next;
    }
	
	std::list<int> list1 = vector_to_list(vec);
	
	return list1;
}

struct ListNode* createLL(std::vector<int>& A)
{
    struct ListNode *temp , *last;
    struct ListNode *one;
    one = (struct ListNode *)malloc(sizeof(struct ListNode));
    one->val = A[0];
    one->next = NULL;
    last = one;
    //std::cout << one->val << '\n';
    for (int i = 1; i < A.size(); i++)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
        //std::cout << last->val << '\n';
    }

    return one;
}

void displayLL(struct ListNode* p)
{
    
    while(p != NULL)
    {
        std::cout << p->val << '\n';
        p = p->next;
    }
}

int main()
{
	std::vector<int> nums {-1,4,6};
	
	std::list<int> list1 = vector_to_list(nums);
	
	std::vector<int> nums2 {1,3,7};
	
	std::list<int> list2 = vector_to_list(nums2);
	
	list2.merge(list1);
	
	std::vector<int> vec2 = list_to_vector(list2);
	
	for(auto& x : vec2)
		std::cout << x << ' ';
	
	struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
	p = createLL(vec2);
	
	std::cout << '\n';
	displayLL(p);
	
	
	return 0;
	
}
/*
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ListNode* createLL(std::vector<int>& A)
{
    struct ListNode *temp , *last;
    struct ListNode *one;
    one = (struct ListNode *)malloc(sizeof(struct ListNode));
    one->val = A[0];
    one->next = NULL;
    last = one;
    //std::cout << one->val << '\n';
    for (int i = 1; i < A.size(); i++)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
        //std::cout << last->val << '\n';
    }

    return one;
}

std::vector<int> create_vector(struct ListNode* first)
{
	std::vector<int> vec;
    struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = first;
    while(p != NULL)
    {
        //std::cout << p->val << '\n';
		vec.push_back(p->val);
        p = p->next;
    }
	
	return vec;
}

void displayLL(struct ListNode* first)
{
    struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = first;
    while(p != NULL)
    {
        std::cout << p->val << '\n';
        p = p->next;
    }
		
}


std::vector<int> merge(const std::vector<int>& first,const std::vector<int>& second)
{
	size_t total_size = first.size() + second.size();
	
	if(first.size() == 0)
		return second;
	if(second.size() == 0)
		return first;	
	
	std::vector<int> combined(first.size() + second.size());
	
	if(first.back() < second.front())
	{
		std::copy(first.begin(),first.end(),combined.begin());
		std::copy(second.begin(),second.end(),combined.begin() + first.size());
		return combined;
	}
	
	size_t count_first = 0;
	size_t count_second = 0;
	
	size_t count_combined = 0;
	
	while((count_first < first.size()) && (count_second < second.size()))	
	{
		/*
		std::cout << "In while loop\n";
		
		std::cout << "When comparing \n";
		
		std::cout << "first count = " << count_first << '\n';
		std::cout << "second count = " << count_second << '\n';
		
		std::cout << " first[count_first] " << first[count_first] << '\n';
		std::cout << " second[count_second] " << second[count_second] << '\n';		
		*/
		
		if(first[count_first] == second[count_second])
		{
			combined[count_combined++] = first[count_first];
			combined[count_combined++] = first[count_first];
			count_second++;
			count_first++;
		}
		else if(first[count_first] > second[count_second])
		{
			combined[count_combined++] = second[count_second];
			count_second++;
		}
		else
		{
			combined[count_combined++] = first[count_first];
			count_first++;
		}
		
		/*
		std::cout << "count = " << count_combined << '\n';
		std::cout << "first count = " << count_first << '\n';
		std::cout << "second count = " << count_second << '\n';
		
		
		for(size_t i = 0;i < count_combined;i++)
			std::cout << combined[i] << '\n';
		
		std::cout << "End while loop\n";
		*/
	}
	
	if(count_first == first.size())
		std::copy(second.begin()+count_first,second.end(),combined.begin() + count_combined);
	
	if(count_second == second.size())
		std::copy(first.begin()+count_second,first.end(),combined.begin() + count_combined);
	
	
	return combined;
	
}


int main()
{
	/*
	std::vector<int> one {-10,9,10,11,100};
	std::vector<int> two {-5,-1,0,10,100,200,205};
	*/
	/*
	std::vector<int> one {1,2};
	std::vector<int> two {3,4};
	*/
	/*
	std::vector<int> one {};
	std::vector<int> two {3,4};
	*/
	/*
	std::vector<int> one {3,4};
	std::vector<int> two {};
	*/
	
	std::vector<int> one {1,2,4};
	std::vector<int> two {1,3,4};
	
	std::vector<int> combined = merge(one,two);
	
	struct ListNode* node = createLL(combined);
	
	displayLL(node);
	
	std::vector<int> vec = create_vector(node);
	
	for(int& x : vec)
		std::cout << x << '\n';
	
	return 0;
}
/*
struct Node
{
   int data;
   struct Node *next;
} *one, *two;

struct Node * createLL(int A[],int n)
{
    struct Node *temp , *last;
    struct Node *one;
    one = (struct Node *)malloc(sizeof(struct Node));
    one->data = A[0];
    one->next = NULL;
    last = one;
    std::cout << one->data << '\n';
    for (int i=1; i<n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
        std::cout << last->data << '\n';
    }

    return one;
}

void displayLL(struct Node* first)
{
    struct Node *p  = (struct Node *)malloc(sizeof(struct Node));
    p = first;
    while(p != NULL)
    {
        std::cout << p->data << '\n';
        p = p->next;
    }
}

struct Node* merge(struct Node* first,struct Node* second)
{
	struct Node* combined;
	combined = (struct Node *)malloc(sizeof(struct Node));
	
	struct Node* combined_head;
	combined_head = (struct Node *)malloc(sizeof(struct Node));
	
	struct Node* p;
	struct Node* q;
	
	p = (struct Node *)malloc(sizeof(struct Node));
	q = (struct Node *)malloc(sizeof(struct Node));
	
	p = first;
	q = second;
	
	//std::cout << p->data << '\n';
	//std::cout << q->data << '\n';
	int i = 0;
	
	while ((p->next != NULL) && (q->next != NULL))
	{
		if (p->data == q->data)
		{
			combined->data = p->data;
			std::cout << "w " << combined->data << '\n';
			struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
			temp->data = q->data;
			struct Node* temp1 = (struct Node *)malloc(sizeof(struct Node));
			temp1->data = q->data;
			temp->next = temp1;
			combined->next = temp;
			combined = temp1;
			std::cout << "w " << combined->data << '\n';
			p = p->next;q = q->next;
		}
		else if(p->data < q->data)
		{
			combined->data = p->data;
			std::cout << "w " << combined->data << '\n';
			combined->next = NULL;
			p = p->next;
		}
		else
		{
			combined->data = q->data;
			std::cout << "w " << combined->data << '\n';
			combined->next = NULL;
			q = q->next;
		}
		
		if(0 == i)
		{
			combined_head = combined;
			i = i + 1;
		}
		
		
			
	}
	
	if(p->next == NULL)
	{
		struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = p->data;
		temp->next = q;
		combined->next = temp;
		std::cout << "outside w " << combined->data << '\n';
	}
	if(q->next == NULL)
	{
		struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = q->data;
		temp->next = p;
		combined->next = temp;
		std::cout << "outside w " << combined->data << '\n';
	}
	
	std::cout << "diplay at the end of merge : \n";
	displayLL(combined_head);
	
	return combined_head;
}

int main()
{
	int arr_one[5] = {-3,-1,0,5,7};	
	int arr_two[7] = {-10,-2,0,4,9,20,21};
	
	one = createLL(arr_one,sizeof(arr_one)/sizeof(arr_one[0]));
	
	two = createLL(arr_two,sizeof(arr_two)/sizeof(arr_two[0]));
	
	struct Node* combined = merge(one,two);
	
	//std::cout << combined->data << '\n';
	
	displayLL(combined);
	
	return 0;
}

/*
#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& first,const std::vector<int>& second)
{
	size_t total_size = first.size() + second.size();
	
	if(first.size() == 0)
		return second;
	if(second.size() == 0)
		return first;
	
	std::vector<int> combined(first.size() + second.size());
	
	size_t count_first = 0;
	size_t count_second = 0;
	
	size_t count_combined = 0;
	
	while((count_first < first.size()) && (count_second < second.size()))	
	{
		std::cout << "In while loop\n";
		
		std::cout << "When comparing \n";
		
		std::cout << "first count = " << count_first << '\n';
		std::cout << "second count = " << count_second << '\n';
		
		std::cout << " first[count_first] " << first[count_first] << '\n';
		std::cout << " second[count_second] " << second[count_second] << '\n';		
		
		if(first[count_first] == second[count_second])
		{
			combined[count_combined++] = first[count_first];
			combined[count_combined++] = first[count_first];
			count_second++;
			count_first++;
		}
		else if(first[count_first] > second[count_second])
		{
			combined[count_combined++] = second[count_second];
			count_second++;
		}
		else
		{
			combined[count_combined++] = first[count_first];
			count_first++;
		}
		
		
		std::cout << "count = " << count_combined << '\n';
		std::cout << "first count = " << count_first << '\n';
		std::cout << "second count = " << count_second << '\n';
		
		for(int i = 0;i < count_combined;i++)
			std::cout << combined[i] << '\n';
		
		std::cout << "End while loop\n";
		
	}
	
	if(count_first == first.size())
		std::copy(second.begin()+count_first,second.end(),combined.begin() + count_combined);
	
	if(count_second == second.size())
		std::copy(first.begin()+count_second,first.end(),combined.begin() + count_combined);
	
	
	return combined;
		
	
	
}


int main()
{
	std::vector<int> one {-10,9,10,11,100};
	std::vector<int> two {-5,-1,0,10,100,200,205};
	
	std::vector<int> combined = merge(one,two);
	
	for(int& x : combined)
		std::cout << x << '\n';
	
	return 0;
}                                                                  
*/
