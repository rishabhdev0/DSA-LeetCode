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
    ListNode* removeElements(ListNode* head, int val) {
        //edge case all elment are same
         if (head == nullptr) {
            return nullptr;
        }

        // what if 1st elemnt is equal to val
        while(head !=nullptr && head->val== val){
            ListNode* deleted = head;
            head = head->next;
            delete deleted;
        }

        ListNode* curr = head;
        while(curr != nullptr && curr->next !=nullptr){
            if(curr->next->val == val){
                ListNode* deleted = curr->next;
                curr->next = curr->next->next;
                delete deleted;
            }else{
                curr=curr->next;
            }
        }
        return head;
    }
};