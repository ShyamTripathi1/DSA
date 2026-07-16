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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* curr = head;
        while(curr){
           ListNode* previous= dummyNode;
            ListNode* next = curr->next;
        while(previous->next && previous->next->val <= curr->val)
        {
            previous = previous->next;
        }
        curr-> next = previous->next;
            previous->next = curr;
            curr = next;
        }
    return dummyNode->next;

        
    }
};
