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
void inorder(TreeNode* root, vector<TreeNode*> &ans){
    if(root== NULL){
    return;
    }
    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}
void recoverTree(TreeNode* root){
    vector<TreeNode*> ans;
    inorder(root,ans);
    TreeNode* f= nullptr;
    TreeNode* s = nullptr;
    for(int i =0;i<ans.size()-1;i++){
        if(ans[i]->val>ans[i+1]->val){
            if (f==nullptr) f= ans[i];
        s= ans[i+1];
    }
}
if(f != nullptr && s != nullptr)
swap(f->val,s->val);
 
    }
};
