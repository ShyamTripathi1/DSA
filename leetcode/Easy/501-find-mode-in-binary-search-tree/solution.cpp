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
        vector<int> mode;
        int prev;
        int cnt;
        int max_cnt = 0;
        bool hasprev = false;
        void inorder(TreeNode* root){
            if(!root) return;
            inorder(root->left);
            if (hasprev && prev == root->val){
                cnt = cnt+1;
            }
            else{
                cnt = 1;

            }
            if(cnt > max_cnt ){
                max_cnt = cnt;
                mode.clear();
                mode.push_back(root->val);
            }
            else if(cnt == max_cnt){
                mode.push_back(root->val);
            }
            prev = root->val;
            hasprev = true;
            inorder(root->right);
        }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return mode;
    }
};
