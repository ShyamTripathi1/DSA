/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* x = root;
        while(x){
            Node dummy = Node(0);
            Node* p = &dummy;
            while(x){
                if(x->left){
                    p->next = x->left;
                    p=p->next;
                }
                if(x->right){
                    p->next = x->right;
                    p=p->next;
                }
                x=x->next;
                
            }
            x=dummy.next;

        }
        return root;
        
    }
};
