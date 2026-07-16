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
    void reorderList(ListNode* head) {
         if(!head || !head->next) return;
        ListNode* temp = head;
        vector<ListNode*>ans;
        while(temp){
            ans.push_back(temp);
            temp = temp->next; 
        }
         int i = 0;
        int j = ans.size() - 1;
         while (i < j) {
            ans[i]->next = ans[j];
            i++;
            if (i == j) break;
            ans[j]->next = ans[i];
            j--;
        }
        ans[i]->next = nullptr;
    }
};

