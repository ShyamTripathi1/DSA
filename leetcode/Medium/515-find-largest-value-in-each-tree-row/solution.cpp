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
        void fnc(TreeNode* root, int depth,vector<int> &ans){
        if(!root) return;
            if(depth == ans.size()){
                    ans.push_back(root->val);
                }
                else{
                    ans[depth] = max(ans[depth],root->val);
                }
                fnc(root->left,depth+1,ans);
                fnc(root->right,depth+1,ans);
            }
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>ans;
        fnc(root,0,ans);
        return ans;
    }
};
