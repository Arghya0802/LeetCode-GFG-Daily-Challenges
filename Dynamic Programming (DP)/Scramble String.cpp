// Link: https://leetcode.com/problems/scramble-string/description/

class Solution {
private:
unordered_map<string , bool> map ;

bool dfs(string s , string t)
{
    if(s.size() != t.size() )
        return false ;

    if(s == t)
        return true ;

    string key = s + "-" + t ;

    if(map.find(key) != map.end() )
        return map[key] ;

    int n = s.size() ;

    int freqS[26] = {0} ;
    int freqT[26] = {0} ;

    for(char ch : s)
        freqS[ch - 'a'] += 1 ;

    for(char ch : t)
        freqT[ch - 'a'] += 1 ;

    for(int i = 0 ; i < 26 ; i++)
    {
        if(freqS[i] != freqT[i])
            return false ;
    }
    
    for(int i = 0 ; i < n - 1 ; i++)
    {
        string a = s.substr(0 , i + 1) ;
        string b = s.substr(i + 1) ;

        string c = t.substr(0 , i + 1) ;
        string d = t.substr(i + 1) ;

        bool withoutSwap = dfs(a , c) && dfs(b , d) ;

        if(withoutSwap == true)
            return true ;

        string e = s.substr(n - i - 1) ;
        string f = s.substr(0 , n - i - 1) ;

        bool withSwap = dfs(e , c) && dfs(f , d) ;

        if(withSwap == true)
            return true ;
    }

    return map[key] = false ;
}

public:
    bool isScramble(string &s1, string &s2) 
    {
        return dfs(s1 , s2) ;
    }
};

// Time Complexity:  O(N ^ 4)
// Space Complexity: O(N ^ 4)
