class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummynode = new ListNode(0);
        ListNode* current = dummynode;
        int carry = 0;
        
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
              // checking the l1 or l2 is null or  empty then we took  zero ,otherwise  
            //  we  took the next element 
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            // creating node for storing ther digit 
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
          //    answer starting from next of dummy node 
        ListNode* ans = dummynode->next;
        delete dummynode;
        return ans;
    }
};