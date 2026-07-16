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
            if(in[i]==target)
            return i;
        }
        return -1;
    }
    
    TreeNode* Tree(int in[], int post[], int InStart, int InEnd, int &index){
        if(InStart>InEnd)
        return NULL;
        TreeNode* root = new TreeNode(post[index]);
        int pos = find(in,post[index],InStart,InEnd);
        index--;
        root->right = Tree(in,post,pos+1,InEnd,index);
        root->left= Tree(in,post,InStart,pos-1,index);
        return root;
        
    }
   
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
         int n = inorder.size();
         int index = n-1;
        return Tree(&inorder[0],&postorder[0],0,n-1,index);
        // code here
        
    }
};
