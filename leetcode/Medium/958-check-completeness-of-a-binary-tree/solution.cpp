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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qt;
        qt.push(root);
        bool found = false;
        while(!qt.empty()){
            TreeNode* temp = qt.front();
            qt.pop();
            if(temp == NULL){
                found = true;
            }
            else {
                if(found){
                 return false;
                }
            qt.push(temp->left);
            qt.push(temp->right);
            } 
        }
        return true;
    }
};
