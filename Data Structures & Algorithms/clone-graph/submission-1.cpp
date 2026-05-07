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
unordered_map<Node*, Node*> hmap;
    Node* cloneGraph(Node* node) 
    {
        if(!node){return nullptr;}
        return dfs(node);
    }
    Node* dfs (Node * node){
        // if(node== nullptr){return nullptr;}
        if(hmap.count(node)){return hmap[node];}


        Node *copy= new Node( node->val);
        hmap[node]=copy;

        for(Node* nd: node->neighbors)
        {
           Node * currNode= dfs(nd);
           copy->neighbors.push_back(currNode);
        }
        return copy;
    }
};
