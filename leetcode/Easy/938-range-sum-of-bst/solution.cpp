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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
        return 0;
        queue<TreeNode*> st;
        st.push(root);
        int sum =0;
        TreeNode* curr = root;
        while(!st.empty()){
            curr = st.front();
            st.pop();
            if(!curr) continue;
        if(curr->val >= low && curr->val <= high){
            sum += curr->val;
        }
        if(curr->val >low){
            st.push(curr->left);
        }
        if(curr->val < high){
            st.push(curr->right);
        }
        }
        return sum;
    }
};
