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
    TreeNode* reverseOddLevels(TreeNode* root) {
       int ans  = 0;
       if(!root) return root;
       queue<TreeNode*> qt;
       qt.push(root);
       
       while(!qt.empty()){
        int n = qt.size();
        vector<TreeNode*>levels;
        
        for(int i=0;i<n;i++){
            TreeNode* node = qt.front();
        qt.pop();
            levels.push_back(node);
        
        if(node->left){
            qt.push(node->left);
        }
        if(node->right){
            qt.push(node->right);
        }
       }
        if(ans%2==1){
            int i = 0, j = levels.size() - 1;
                while(i < j){
                    swap(levels[i]->val, levels[j]->val);
                    i++;
                    j--;
                }
        }
            ans++;
        }
       return root;
    }
};
