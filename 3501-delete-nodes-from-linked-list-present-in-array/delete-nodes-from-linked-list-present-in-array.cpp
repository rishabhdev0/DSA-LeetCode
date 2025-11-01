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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>seen(nums.begin() , nums.end());
        ListNode* dummy_node = new ListNode(-1);
        dummy_node -> next = head;
        ListNode* prev = dummy_node ;
        ListNode*  curr = head;
        while(curr != nullptr){
            if(seen.count(curr->val)){
               prev->next = curr->next;
            }else prev = curr;
            curr = curr->next;
        }
        return dummy_node->next;
    }
};