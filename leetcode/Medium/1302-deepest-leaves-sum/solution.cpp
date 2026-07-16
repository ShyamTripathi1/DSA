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
    int deepestLeavesSum(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) return 0;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int n = qt.size();
            int sum = 0;
            for(int i =0;i<n;i++){
                TreeNode* node = qt.front();
                qt.pop();
                 sum += node->val;
                 if(node->left) qt.push(node->left);
                 if(node->right) qt.push(node->right);
            }
            ans.push_back(sum);
            

        }
       return ans.back(); 
    }
};
