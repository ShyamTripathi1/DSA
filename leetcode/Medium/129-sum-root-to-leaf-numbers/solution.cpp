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
    int result(TreeNode* root,string ans){
        if(!root) return 0;
        ans += to_string(root->val);
        if(!root->left && !root->right)
        return stoi(ans);
       return result(root->left, ans)+ result(root->right,ans);

    }

    int sumNumbers(TreeNode* root) {
        return result(root,"");

        
    }
};
