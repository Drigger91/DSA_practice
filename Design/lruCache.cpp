#include<unordered_map>
#define NULL nullptr;
using namespace std;
class LRUCache {
    class dll{
        public:
            dll* prev;
            dll* next;
            int val;
            int key;
            dll(int k , int v){
                this->prev = NULL;
                this->next = NULL;
                this->key = k;
                this->val = v;
            }
            void updateVal(int val){
                this->val = val;
            }
    };
public:
    dll* start = new dll(0,0);
    dll* end = new dll(0,0);
   
    int size = 0;
    unordered_map<int,dll*> map;
    LRUCache(int c) {
        this->size = c;
        this->start->next = end;
        this->end->prev = start;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        updateLRU(map[key]);
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if((map.size() == size) && map.find(key) == map.end()){
            int lru = deleteLRU();
            map.erase(lru);
        }
        if(map.find(key) == map.end()) {
            map[key] = new dll(key,value);
            insert(map[key]);
        } else{
            map[key]->updateVal(value);
        }
        updateLRU(map[key]);
        // cout<<"Inserted : "<<key<<" "<<map[key]->val<<endl;
    }
    int deleteLRU(){
        dll* lru = end->prev;
        dll* newLru = lru->prev;
        newLru->next = end;
        end->prev = newLru;
        int key = lru->key;
        delete lru;
        return key;
    }
    void insert(dll* node){
        node->prev = start;
        dll* prevNext = start->next;
        prevNext->prev = node;
        node->next = prevNext;
        start->next = node;
    }
    void updateLRU(dll* node){
        dll* prev = node->prev;
        dll* next = node->next;
        prev->next = next;
        next->prev = prev;
        insert(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */