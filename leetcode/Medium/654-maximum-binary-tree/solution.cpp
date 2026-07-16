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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        vector<TreeNode*> nodeMap(n);

        // decreasing monotonic stack
        stack<int> st;

        for(int i=0;i<n;i++)
        {
            nodeMap[i] = new TreeNode(nums[i]);

            int lastPopped = -1;

            while(!st.empty() && nums[st.top()] < nums[i])
            {
                lastPopped = st.top();
                st.pop();
            }

            // we did some popping
            if(lastPopped != -1)
            {
                nodeMap[i]->left = nodeMap[lastPopped];
            }

            // if it is non empty then the top element is certainly greater than nums[i]
            if(!st.empty())
            {
                nodeMap[st.top()]->right = nodeMap[i];
            }

            st.push(i);
        }

        int lastPopped = -1;
        
        // the last element in the stack in the largest one
        // since it is a decreasing monotonic stack
        while(!st.empty())
        {
            lastPopped = st.top();
            st.pop();
        }

        return nodeMap[lastPopped];
        
    }
};
