/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int prev = -1;
        int result = INT_MAX;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr= curr->left;
            }
                curr = st.top();
                st.pop();
                if( prev != -1){
                    result = min(result,curr->val-prev);
                }
                    prev = curr->val;
                    curr = curr->right;
        }
       return result; 
    }
};
