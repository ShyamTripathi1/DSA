/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& in) {
        if (!root) {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    int findFloor(vector<int>& in, int x) {
        int floor = -1;
        int l = 0, r = in.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (in[mid] <= x) {
                floor = in[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return floor;
    }

    int findCeil(vector<int>& in, int x) {
        int ceil = -1;
        int l = 0, r = in.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (in[mid] >= x) {
                ceil = in[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ceil;
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        // ans = [floor_i, ceil_i]
        vector<vector<int>> ans;
        vector<int> in;

        inorder(root, in);

        for (int query : queries) {
            int floor = findFloor(in, query);
            int ceil = findCeil(in, query);
            ans.push_back({floor, ceil});
        }
        return ans;
    }
};
