class LRUCache {
public:
    class Node{
    public:    
        int key,val;
        Node*prev,*next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    Node *head, *tail;
    int cap;unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void addnew(Node*temp){
        temp->prev=head;
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
    }
    void delnode(Node* temp){
        Node* temppre=temp->prev;
        Node* tempnext=temp->next;
        temppre->next=tempnext;
        tempnext->prev=temppre;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode=mp[key];
            int res=resNode->val;
            delnode(resNode);
            addnew(resNode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* resNode=mp[key];
            resNode->val=value;
            delnode(resNode);
            addnew(resNode);
            return;
        }
        if(mp.size()==cap){
            Node* resNode=tail->prev;
            mp.erase(resNode->key);
            resNode->val=value;
            resNode->key=key;
            delnode(resNode);
            addnew(resNode);
            mp[key]=resNode;
            return;
        }
        Node* res=new Node(key,value);
        addnew(res);
        mp[key]=res;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */