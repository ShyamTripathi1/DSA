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
    void find(TreeNode *root, int pos, int &l, int &r) {
        if (!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<tuple<int,int,int>> nodes; 
        stack<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode *temp = q.top().first;
            int col = q.top().second.first;
            int row = q.top().second.second;
            q.pop();

            nodes.push_back({col, row, temp->val});
            if (temp->right)
                q.push({temp->right, {col + 1, row + 1}});
                if (temp->left)
                q.push({temp->left, {col - 1, row + 1}});
        }
        sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        });

        vector<vector<int>> ans;
        int prevCol = INT_MIN;
        for (auto &[col, row, val] : nodes) {
            if (col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }

        return ans;
    }
};




