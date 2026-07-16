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
    int findBottomLeftValue(TreeNode* root) {
        int ans =0;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* node = qt.front();
            qt.pop();
            ans = node->val;
            if(node->right){
                qt.push(node->right);
            }
            if(node->left){
                qt.push(node->left);
            }
            
        }
        return ans;
    }
};
