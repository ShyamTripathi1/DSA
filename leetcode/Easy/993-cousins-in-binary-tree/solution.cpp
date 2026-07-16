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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
        return 0;
        queue<pair<TreeNode*,TreeNode*>> qt;
        qt.push({root,NULL});
        while(!qt.empty()){
            int n = qt.size();
            TreeNode* px = NULL;
            TreeNode* py = NULL;
            for(int i =0;i<n;i++){
                auto[root,parent] = qt.front();
                qt.pop();
                if(root->val == x)  px = parent;
                if(root->val == y)  py = parent;
                if(root->left) qt.push({root->left,root});
                if(root->right) qt.push({root->right,root});
            }
                if(px && py) return px != py;
                if(px || py) return false;
            
        }
        return false;
    }
};
