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
int minn = INT_MAX;
    int minDepth(TreeNode* root) {
        if (!root)
        return 0;
        TreeNode* temp = root;
        stack<pair<TreeNode*,int>> qt;
        qt.push({root,1});
        while(!qt.empty()){
            auto[temp,d] = qt.top();
            qt.pop();
            if( temp-> left==nullptr && temp->right== nullptr){
                minn = min(minn,d);
            }
            if(temp->left){
                qt.push({temp->left,d+1});
            }
            if(temp->right){
                qt.push({temp->right,d+1});
            }
        }

        return minn;
    }
};
