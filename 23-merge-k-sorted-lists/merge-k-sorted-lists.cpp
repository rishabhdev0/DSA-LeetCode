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
    ListNode* mergetwo(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val) {
            l1->next = mergetwo(l1->next, l2);
            return l1;
        } else {
            l2->next = mergetwo(l1, l2->next);
            return l2;
        }
    }

    ListNode* partitionandmerge(int start, int end, vector<ListNode*>& lists) {
        if(start > end) {
            return nullptr;
        }
        if(start == end) {
            return lists[start];
        }
        int mid = start + (end - start)/2;
        ListNode* L1 = partitionandmerge(start, mid, lists);
        ListNode* L2 = partitionandmerge(mid+1, end, lists);
        return mergetwo(L1, L2);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return nullptr;
        return partitionandmerge(0, k-1, lists);
    }
};