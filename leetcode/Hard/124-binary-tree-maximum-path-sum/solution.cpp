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
  int PathSum(TreeNode *root, int &sum){
      if(!root)
      return 0;
      if(!root->left && !root->right){
      sum = max(sum, root->val); 
      return root->val;
      }
      int left = max(0,PathSum(root->left,sum));
      int right = max(0,PathSum(root->right,sum));
     
          sum = max(sum,root->val+left+right);
           if(root->left && root->right)
      {
          return root->val+max(left,right);
      }
      if(root->left)
      {
        
         return root->val+left; 
      }
       if(root->right)
      {
        
         return root->val+right; 
      }
  return root->val;
  }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int val = PathSum(root,sum);
        if(root->left && root->right)
        return sum;
        return max(sum,val);
        // code here
    
        
    }
};
