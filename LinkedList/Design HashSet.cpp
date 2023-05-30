// Link:  https://leetcode.com/problems/design-hashset/description/

class MyHashSet {
private:
list<int> hashSet ;

public:
    MyHashSet() {}
    
    void add(int key) 
    {
        auto it = hashSet.begin() ;

        while(it != hashSet.end() )
        {
            if(*it == key)  break ;

            it++ ;
        }

        if(it == hashSet.end() ) hashSet.push_front(key) ;
    }
    
    void remove(int key) 
    {
        list<int> :: iterator it = hashSet.begin() ;

        while(it != hashSet.end() )
        {
            if(*it == key)  
            {
                hashSet.erase(it) ;
                break ;
            }

            it++ ;
        }

        return ;
    }
    
    bool contains(int key) 
    {
        list<int> :: iterator it = hashSet.begin() ;

        while(it != hashSet.end() )
        {
            if(*it == key)  return true ;

            it++ ;
        }

        return false ;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// Time Complexity:  O(N) 
// Space Complexity: O(N)
