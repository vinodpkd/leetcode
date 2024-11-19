//Beats 100% in speed for the first attempt
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
    ListNode* reverseList(ListNode* head) {
        if(NULL == head || head->next == NULL)
            return head;
        
        std::vector<int> nums;
        struct ListNode* temp;
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = head;

        nums.push_back(head->val);
        do
        {
                
                head = head->next;
                nums.push_back(head->val);
        }
        while(head->next != NULL);

        std::reverse(nums.begin(),nums.end());

        head = temp;
        temp->val = nums[0];
        int i = 1;
        do
        {
            temp =  temp->next;
            temp->val = nums[i];
            i++;
        }
        while(temp->next != NULL);

        return head;
        
    }
};

//Reverse a linked list
//https://www.interviewbit.com/blog/reverse-a-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
        
    }
};
//Iterative method
ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur=head, *tmp;
        while(cur){
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
   }
