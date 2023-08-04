// Link:  https://leetcode.com/problems/word-break/description/

class Solution {

private:
unordered_set<string> dict ;
vector<int> dp ;

bool wordBreak(int ind , string &s)
{
    if(ind >= s.size() )   return true ;
    
    if(dp[ind] != -1)  return dp[ind] ;

    string prefix = "" ;

    for(int i = ind ; i < s.size() ; i++)
    {
        prefix += s[i] ;

        if(dict.find(prefix) != dict.end() )
        {
            if(wordBreak(i + 1 , s) )   return dp[ind] = true ;
        }
    }

    return dp[ind] = false ;
}

public:
    bool wordBreak(string &s , vector<string>& wordDict) 
    {
        for(auto it : wordDict)  dict.insert(it) ;

        dp.resize(s.size() + 1 , -1) ;

        return wordBreak(0 , s) ;        
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
