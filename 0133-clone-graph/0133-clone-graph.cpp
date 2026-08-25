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
    void dfs(Node* node, Node* clone, unordered_map<Node*, Node*> &mpp){
        for(Node* ngbr : node->neighbors){
            if(mpp.find(ngbr) == mpp.end()){
                Node* new_node = new Node(ngbr->val);
                mpp[ngbr] = new_node;

                clone->neighbors.push_back(new_node);
                dfs(ngbr, new_node, mpp);
            }
            else{
                clone->neighbors.push_back(mpp[ngbr]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clone = new Node(node->val);

        unordered_map<Node*, Node*> mpp;
        mpp[node] = clone;

        dfs(node, clone, mpp);

        return clone;
    }
};