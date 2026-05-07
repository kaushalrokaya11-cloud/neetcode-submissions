class LRUCache {
public:
struct Node{
    int val;
    int key;
    Node* prev;
    Node* next;
};
Node *head=new Node();
Node* tail= new Node();

void nodeRemoval(Node* node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
}
void addNodeAtTail(Node* node){
   tail->prev->next=node;
   node->prev=tail->prev;
   node->next=tail;
   tail->prev=node;
}

int capacity;
unordered_map<int,Node*> hmap; 

    LRUCache(int capacity) {
    this->capacity=capacity;
    head->prev=nullptr;
    tail->next=nullptr;
    head->next=tail;
    tail->prev=head;

        
    }
    
    int get(int key) {
        if(hmap.count(key)){
            nodeRemoval(hmap[key]);
            addNodeAtTail(hmap[key]);
            return hmap[key]->val;
            
        }
        else{return -1;}
        
    }
    
    void put(int key, int value) {
        if(hmap.count(key)){
            hmap[key]->val=value;
            nodeRemoval(hmap[key]);
            addNodeAtTail(hmap[key]);
        }
        else{if(hmap.size()>=capacity){
            Node* node=head->next;
            nodeRemoval(head->next);
            hmap.erase(node->key);
            delete node;}


            Node* newNode=new Node();
            newNode->val=value;
            newNode->key=key;
            hmap[key]=newNode;
            addNodeAtTail(newNode);}
            
        
        
    }
};
