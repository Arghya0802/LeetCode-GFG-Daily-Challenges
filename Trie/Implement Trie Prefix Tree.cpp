// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

struct Node 
{
    Node *links[26] ;

    bool flag = false ;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL) ;
    }

    void put(char ch , Node *newNode)
    {
        links[ch - 'a'] = newNode ;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'] ;
    }

    void setEnd()
    {
        flag = true ;
    }

    bool isEnd()
    {
        return flag ;
    }
};

class Trie {
private:
Node *root ;

public:
    Trie() 
    {
        root = new Node() ;            
    }
    
    void insert(string word) 
    {
        Node *node = root ;

        for(int i = 0 ; i < word.size() ; i++)
        {
            char ch = word[i] ;

            if(!node -> containsKey(ch) )
            {
                node -> put(ch , new Node() ) ;
            }

            node = node -> get(ch) ;
        }

        node -> setEnd() ;
    }
    
    bool search(string word) 
    {
        Node *node = root ;

        for(int i = 0 ; i < word.size() ; i++)
        {
            char ch = word[i] ;

            if(!node -> containsKey(ch) )
                return false ;

            node = node -> get(ch) ;
        }

        return node -> isEnd() ;
    }
    
    bool startsWith(string prefix) 
    {
        Node *node = root ;

        for(int i = 0 ; i < prefix.size() ; i++)
        {
            char ch = prefix[i] ;

            if(!node -> containsKey(ch) )
                return false ;

            node = node -> get(ch) ;
        }

        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Time Complexity:  O(N)
// Space Complexity: O(N)
