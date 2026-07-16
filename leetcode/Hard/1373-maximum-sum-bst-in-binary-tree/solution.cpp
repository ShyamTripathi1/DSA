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
int maxsum = 0;
struct info{
    bool bst;
    int minval;
    int maxval;
    int sum;
};
    info result(TreeNode* root){
       if(!root){
       return {true,INT_MAX,INT_MIN,0};
       }
       info l = result(root->left);
       info r = result(root->right);
       if(l.bst && r.bst && l.maxval<root->val && root->val<r.minval){
        int total = l.sum+r.sum+root->val;
        maxsum = max(maxsum,total);
       return{
         true,
         min(l.minval,root->val),
         max(r.maxval,root->val),
         total
       };
    }
     return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        result(root);
        return maxsum;    
    }
};
