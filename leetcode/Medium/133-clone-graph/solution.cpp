/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
       if(!node) {
        return NULL;
       }
       unordered_map<Node*,Node*>mp;
       queue<Node*>qt;
       qt.push(node);
       mp[node]= new Node(node->val);
       while(!qt.empty()){
        Node* x = qt.front();
        qt.pop();
        for(auto k : x->neighbors ){
            if(mp.find(k) == mp.end()){
                mp[k] = new Node(k->val);
                qt.push(k);
            }
                mp[x]->neighbors.push_back(mp[k]);
            
        }
       }
       return mp[node];
    }
};
