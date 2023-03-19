// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

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

} ;

class WordDictionary {
private: Node *root ;
public:
    WordDictionary() 
    {
        root = new Node() ;    
    }
    
    void addWord(string word) 
    {
        Node *node = root ;

        for(int i = 0 ; i < word.size() ; i++)
        {
            char ch = word[i] ;

            if(!node -> containsKey(ch) )
                node -> put(ch , new Node() ) ;

            node = node -> get(ch) ;
        }    

        node -> setEnd() ;
    }
    
    bool search(string word) 
    {
        Node *node = root ;
        return dfs(0 , word.size() , word , node) ;    
    }

    bool dfs(int ind , int n , string &s , Node *node)
    {
        if(ind == n)
            return node -> isEnd() ;

        if(s[ind] == '.')
        {
            for(int i = 0 ; i < 26 ; i++)
            {
                char ch = i + 'a' ;

                if(!node -> containsKey(ch) )
                    continue ;

                Node *prev = node ;
                node = node -> get(ch) ;

                if(dfs(ind + 1 , n , s , node) == true)
                    return true ;

                node = prev ;
            }
        }

        else
        {
            char ch = s[ind] ;

            if(!node -> containsKey(ch) )
                return false ;

            node = node -> get(ch) ;

            if(dfs(ind + 1 , n , s , node) == true)
                return true ;
        }

        return false ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// Time Complexity:  O(26 ^ K) [K has a maximum value of 25, which is word.size() ]
// Space Complexity: O(N)
