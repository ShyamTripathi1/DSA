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
int c =0;
    int postOrder(TreeNode* root){
        if(!root)
        return -1;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
    
        if (left ==0 || right ==0){
        c = c+1;
        return 1;
        }
        if (left == 1 || right == 1){
        return -1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        
      if (postOrder(root) == 0) c= c+1;
      return c;
        
    }
};
