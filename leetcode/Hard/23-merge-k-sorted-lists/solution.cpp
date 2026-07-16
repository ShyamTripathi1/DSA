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
/*#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-heap
    }
};*/

class Solution {
public:
class compare
{
    public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*> &listArray){
    int k = listArray.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> p;
        for (int i = 0; i < k; i++) {
            if (listArray[i]) p.push(listArray[i]);
        }
        ListNode *root = new ListNode(0);
        ListNode *tail = root;
        ListNode *temp;
        while(!p.empty())
        {
            temp = p.top();
            p.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next)
            p.push(temp->next);
        }
        // code here
        return root->next;
   
}
};
