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
unordered_set<Node*> visited;
    Node* cloneGraph(Node* node) 
    {
    if(!node){return nullptr;}
     Node * node1= new Node(node->val);
     hmap[node]=node1;
     visited.insert(node);
     dfs( node1->neighbors,node->neighbors);

     return node1;   
    }
    void dfs( vector<Node*> &newNodeList,vector<Node*> &orgNodeList){

        for(int i=0;i<orgNodeList.size();i++)
        {
            if( hmap.count(orgNodeList[i])){
                newNodeList.push_back(hmap[orgNodeList[i]]);
            }
            else{
                Node* newNode= new Node( orgNodeList[i]->val);
                newNodeList.push_back(newNode);
                hmap[orgNodeList[i]]= newNode;
            }


        }
        for(int i=0;i<orgNodeList.size();i++){
            if(visited.count(orgNodeList[i])){continue;}
            visited.insert(orgNodeList[i]);
            dfs(newNodeList[i]->neighbors, orgNodeList[i]->neighbors);
        }
            
    }

};
