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
    int getDecimalValue(ListNode* head) {
        std::vector<int> bits;
        
        while (head != nullptr) {
            bits.push_back(head->val);
            head = head->next;
        }

        int base2 = 0;
        int base = 1;
        for (int i = bits.size() - 1; i >= 0; i--) { 
            base2 += bits[i] * base;                 
            base *= 2;
        }

        return base2;
    }
};
