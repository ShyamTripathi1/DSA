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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        return {};
        vector<vector<int>> res;
        
        queue<TreeNode*> q1;
        q1.push(root);
        bool left_right = true;
        while (!q1.empty()){
            int n = q1.size();
            vector<int> arr;
            for(int i=0;i<n;i++){
                TreeNode* temp = q1.front();
                q1.pop();
                arr.push_back(temp->val);
                if(temp->left){
                    q1.push(temp->left);
                }
                if(temp->right){
                    q1.push(temp->right);

                }
            }
                if(!left_right){
                    reverse(arr.begin(),arr.end());
                }
                res.push_back(arr);
                left_right = !left_right;
                

            }

        
        
        return res;
        



        
    }
};
