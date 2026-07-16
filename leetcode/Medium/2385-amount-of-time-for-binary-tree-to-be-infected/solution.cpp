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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
    if(root == NULL) return;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    markParent(root->left,parent);
    markParent(root->right,parent);
}
TreeNode* find(TreeNode* root, int start){
    if(root == NULL) return NULL;
    if(root->val == start) return root;
    TreeNode* left = find(root->left, start);
    if(left) return left;
    return find(root->right, start);
}

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* first = find(root,start);
        unordered_map<TreeNode* , TreeNode*> parent;
        markParent(root, parent);
        int maxLevel = 0;
unordered_set<TreeNode*> s;
s.insert(first);
queue<pair<TreeNode*, int>> q;
q.push({first, 0});

while(!q.empty()){
    auto [temp, level] = q.front();
    q.pop();
    
    maxLevel = max(maxLevel, level);
    
    if(temp->left && s.find(temp->left) == s.end()){
        q.push({temp->left, level + 1});
        s.insert(temp->left);
    }
    if(temp->right && s.find(temp->right) == s.end()){
        q.push({temp->right, level + 1});
        s.insert(temp->right);
    }
    if(parent[temp] && s.find(parent[temp]) == s.end()){
        q.push({parent[temp], level + 1});
        s.insert(parent[temp]);
    }
}

        return maxLevel;  
    }
};
