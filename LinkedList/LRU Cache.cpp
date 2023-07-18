// Link:  

struct LinkedNode 
{
    int key ; int value ;
    
    LinkedNode *next ; LinkedNode  *prev ;

    LinkedNode(int x , int y) 
    {
        key = x ;  value = y ; 
        prev = NULL ;  next = NULL ;
    }

};

class LRUCache {
private:

LinkedNode *head ;
LinkedNode  *last ;  LinkedNode *tail ;

unordered_map<int, LinkedNode* >map ;
int cap ;

public:
    LRUCache(int capacity) 
    {
        head = new LinkedNode (-1 , -1) ; last = new LinkedNode (-1 , -1) ;

        head -> next = last ;  last -> prev = head ; tail = last ;
        
        cap = capacity ;
    }
    
    void deleteNode(LinkedNode *node)
    {
        LinkedNode *prevNode = node -> prev ;  
        LinkedNode *nextNode = node -> next ;

        prevNode -> next = nextNode ; nextNode -> prev = prevNode ;

        return ;
    }

    void insertAfterHead(LinkedNode *node)
    {
        LinkedNode *tempNode = head -> next ;

        head -> next = node ;  node -> next = tempNode ;
        
        node -> prev = head ;  tempNode -> prev = node ;

        return ;
    }

    int get(int key) 
    {
        if(map.find(key) == map.end() )  return -1 ;

        deleteNode(map[key]) ;  insertAfterHead(map[key]) ;

        return map[key] -> value ;
    }
    
    void put(int key, int value) 
    {
        if(map.find(key) != map.end() ) 
        {
            map[key] -> value = value ;
            
            deleteNode(map[key]) ;  insertAfterHead(map[key]) ;

            return ;
        }
        
        if(map.size() < cap)
        {
            LinkedNode *cache = new LinkedNode(key , value) ;

            map[key] = cache ;  insertAfterHead(cache) ;
        }

        else
        {
            LinkedNode *LRU = last -> prev ;

            deleteNode(LRU) ; map.erase(LRU -> key) ; 

            LRU -> key = key ;  LRU -> value = value ;

            insertAfterHead(LRU) ;  map[key] = LRU ;
        }

        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Time Compelexity: O(1) [For both get() and put() function ]
// Space Complexity: O(N) [For using a Map and building a doubly linkedList ]
