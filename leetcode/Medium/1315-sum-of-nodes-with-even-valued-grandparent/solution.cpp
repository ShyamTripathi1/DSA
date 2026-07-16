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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*> qt;
        qt.push(root);
        int sum =0;
        while(!qt.empty()){
            int n = qt.size();
            for(int i =0;i<n;i++){
                TreeNode* node = qt.top();
                qt.pop();
                if(node->left){
                    qt.push(node->left);
                }
                if(node->right){
                    qt.push(node->right);
                }
                if(node->val%2 == 0){
                    if(node->left){
                if(node->left->left) sum += node->left->left->val;
                  if(node->left->right) sum += node->left->right->val;
                    }
                    if(node->right){
                   if(node->right->left) sum+= node->right->left->val;
                    if(node->right->right) sum += node->right->right->val;
                    }
                }
                }
            }
       return sum;
        
    }
};
