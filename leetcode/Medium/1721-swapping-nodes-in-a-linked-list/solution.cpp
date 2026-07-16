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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        int cnt =1;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        temp=head;
        ListNode* temp2=head;
        for(int i=1;i<k;i++){
        temp=temp->next;

        }
        for(int j=1;j<cnt-k;j++){
        temp2=temp2->next;
        }
      swap(temp->val,temp2->val);
      return head;
       
    }
};
