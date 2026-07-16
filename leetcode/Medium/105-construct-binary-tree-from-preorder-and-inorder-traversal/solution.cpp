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
    int find(int in[], int target, int start, int end){
        for(int i = start;i<=end;i++){
            if(in[i]==target) return i;
        }
        return -1;
    }
    
    TreeNode* Tree(int in[], int pre[], int InStart, int InEnd, int &index){
        if(InStart>InEnd) return NULL;
        TreeNode* root = new TreeNode(pre[index]);
        int pos = find(in, pre[index],InStart,InEnd);
        index++;
         root->left = Tree(in, pre, InStart, pos - 1, index);
        root->right = Tree(in, pre, pos + 1, InEnd, index);
        return root;
        
    }
   
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
         int n = inorder.size();
        int index = 0;
        return Tree(&inorder[0], &preorder[0], 0, n - 1, index);
        
        
    }
};
