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
    ListNode* sortList(ListNode* head) {
        vector<ListNode*>ans;
        ListNode* curr= head;
        while(curr){
            ans.push_back(curr);
            curr = curr->next;
        }
               sort(ans.begin(), ans.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });

        ListNode* nw = new ListNode(0);
        ListNode* node1 = nw;
        int i=0;
        while(i<ans.size()){
            node1->next = ans[i];
            node1= node1->next;
            i++;
        }
        node1->next = NULL;
        return nw->next;
    }
};
