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
    TreeNode* inorder(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            curr->right = root;
            root->left = NULL;
            curr = root;
            root = root->right;
           

        }

         return dummy->right;
       

    }
    TreeNode* increasingBST(TreeNode* root) {
        return inorder(root);
        
    }
};
