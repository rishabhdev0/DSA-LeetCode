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
    private:
    ListNode* middle(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
      }
      return slow;
}

ListNode* reverse(ListNode*head){
    ListNode*prev=nullptr;
    ListNode*curr=head;
    while(curr!=nullptr){
        ListNode*forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
public:
    bool isPalindrome(ListNode* head) {
       if(head==nullptr || head->next==nullptr){
        return true;
       } 
    ListNode*mid = middle(head);
    ListNode*head1 = head;
    ListNode*head2 = reverse(mid);
    while(head1!=nullptr && head2!=nullptr){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
       
    }
       return true;
    }
};