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
    ListNode* partition(ListNode* head, int x) {

        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);

        ListNode* small_ptr = small;
        ListNode* big_ptr = big;

        while(head != nullptr){

            if(head->val < x){

                small_ptr->next = head;
                small_ptr = small_ptr->next;

            }
            else{

                big_ptr->next = head;
                big_ptr = big_ptr->next;
            }

            head = head->next;
        }

        // important
        big_ptr->next = nullptr;

        // connect lists
        small_ptr->next = big->next;

        return small->next;
    }
};