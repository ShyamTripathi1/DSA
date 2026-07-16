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
    vector<int>ans1;
    vector<int>ans2;
    void inorder(TreeNode* root,vector<int> &ans){
        if(!root)
        return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    inorder(root1,ans1);
    inorder(root2,ans2);
       int i=0;
       int j=0;
       vector<int>result;
       while(i<ans1.size() && j<ans2.size()){
        if(ans1[i]<ans2[j]){
            result.push_back(ans1[i]);
            i++;
        }
        else{
            result.push_back(ans2[j]);
            j++;
        }
       } 
       result.insert(result.end(),ans1.begin()+i,ans1.end());
       result.insert(result.end(),ans2.begin()+j,ans2.end());
       return result;
    }
};
