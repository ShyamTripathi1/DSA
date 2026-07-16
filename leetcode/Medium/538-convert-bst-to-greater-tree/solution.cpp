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
    TreeNode* convertBST(TreeNode* root) {
        int total =0;
        rev_inorder(root,total);
        return root;
    }
        private:
        void rev_inorder(TreeNode* root ,int &total){
            if(!root) return;
            rev_inorder(root->right ,total);
            total += root->val;
            root->val = total;
            rev_inorder(root->left,total);
           

     
    }
};
