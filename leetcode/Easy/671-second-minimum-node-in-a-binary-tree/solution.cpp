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
 void inorder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    inorder(root->right,ans);
    ans.push_back(root->val);
    inorder(root->left,ans);
    

}
    int findSecondMinimumValue(TreeNode* root) {
      if (!root) return -1;
      vector<int>ans;
      inorder(root,ans);
       int firstMin = root->val;
        long secondMin = LONG_MAX;

        for (int val : ans) {
            if (val > firstMin && val < secondMin) {
                secondMin = val;
            }
        }
        return (secondMin == LONG_MAX) ? -1 : (int)secondMin;

        
    }
};
