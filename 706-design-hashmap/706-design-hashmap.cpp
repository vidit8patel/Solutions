class MyHashMap {
public:
    vector<list<pair<int, int>>> map;
    int size;
    MyHashMap() {
        size = 100;       
        map.resize(size);
    }
    int hash(int key)
    {
        return key%size;
    }
    list<pair<int, int>> :: iterator search(int key)
    {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = map[i].begin();
        while(it != map[i].end())
        {
            if(key == it->first)
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        map[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it != map[i].end())
            return it->second;
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it != map[i].end())
            map[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */