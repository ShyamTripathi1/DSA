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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int sum =0;
        queue<pair<TreeNode*,int>> qt;
        qt.push({root,root->val});
        while(!qt.empty()){
             auto p = qt.front();
            qt.pop();
                TreeNode* node = p.first;
                int maxi = p.second;
                if(node->val >= maxi) sum++;
                maxi = max(maxi,node->val);
                if(node->left){
                    qt.push({node->left,maxi});
                }
                if(node->right){
                    qt.push({node->right,maxi});
                }
        }
        return sum;
        
    }
};
