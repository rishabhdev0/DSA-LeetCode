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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* dummy = new ListNode(0);
       dummy->next = head;
       ListNode* prev =  dummy;
       while(head!=nullptr){
        if(head->next != nullptr && head->val==head->next->val){
            while(head->next != nullptr && head->val == head->next->val){
                head = head->next; // skipping nodes if  all equal
            }
            prev->next = head->next;
        }else prev = head;
        head = head->next;
       } 
       return dummy->next;
    }
};