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
