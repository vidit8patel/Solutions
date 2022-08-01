class LRUCache {
public:
    class node {
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    unordered_map<int, node*> map;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newNode)
    {
        node* temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(map.find(key) != map.end())
        {
            node* resnode = map[key];
            int res = resnode->val;
            map.erase(key);
            deletenode(resnode);
            addnode(resnode);
            map[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end())
        {
            node* existingnode = map[key];
            map.erase(key);
            deletenode(existingnode);   
        }
        if(cap == map.size())
        {
            map.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */