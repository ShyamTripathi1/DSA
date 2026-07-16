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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }

    bool inorder(TreeNode* node, TreeNode*& prev) {
        if (!node) return true;

        // Traverse left subtree
        if (!inorder(node->left, prev)) return false;

        // Check current node with the previous node
        if (prev != nullptr && node->val <= prev->val)
            return false;

        // Update prev
        prev = node;

        // Traverse right subtree
        return inorder(node->right, prev);
    }
};
