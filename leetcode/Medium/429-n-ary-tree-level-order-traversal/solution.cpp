/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> qt;
        qt.push(root);
        while(!qt.empty()){
            vector<int>level;
            int n = qt.size();
            for(int i =0;i<n;i++){
            Node* node = qt.front();
            qt.pop();
            level.push_back(node->val);
           for(Node* child:node->children){
            qt.push(child);
           }
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};
