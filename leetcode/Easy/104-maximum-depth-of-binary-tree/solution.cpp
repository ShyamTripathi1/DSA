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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        queue<pair<TreeNode*,int>> st;
        st.push({root,1});
        int maxd = 0;
        while(!st.empty()){
           auto[temp,d] = st.front();
            st.pop();
            if(!temp->left && !temp->right){
                maxd = max(maxd,d);
            }
            if(temp->left){
                st.push({temp->left,d+1});
            }
            if(temp->right){
                st.push({temp->right,d+1});
            }
        }
        return maxd;
    }
};
