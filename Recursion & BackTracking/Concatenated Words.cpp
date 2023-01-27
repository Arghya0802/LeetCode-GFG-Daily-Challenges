// Link: https://leetcode.com/problems/concatenated-words/description/

// The question appears tricky and the Hard tag is definetly misleading
// To save Time Complexity, we will iterate over all the words and check if can be created with 2 or more words
// We design our Recursive Function such that we have two cases:-
// We have both the prefix and suffix present inside our HashSet. In this case, we directly return true
// Another possibility is that we don't have suffix so we ask recursion or dfs() function to check if our suffix can be made or not
// If it return true, we directly return true. Otherwise we keep on iterating in the same manner

class Solution {
private:

// dfs() function checks if we can make String S using 2 or more shorter words from our HashSet
bool dfs(string &s , unordered_set<string> &set)
{
    int n = s.size() ;
    
    // We start our loop from i = 1 till N because if we start from i = 0 , our prefix will be empty and our suffix will be the entire string S. And it will return true
    // So to avoid the EdgeCase, we start from i = 1 and loop till N
  
    for(int i = 1 ; i < n ; i++) 
    {
        string prefix = s.substr(0 , i) ; // Prefix will be from i = 0 till i
        string suffix = s.substr(i) ; // Suffix will be from i = 1 till N

        if(set.find(prefix) != set.end() ) // If prefix is present in our HashSet
        {
            if(set.find(suffix) != set.end() ) // We check if our suffix is present in our HashSet
                return true ; // If true, we directly return true

            if(dfs(suffix , set) == true) // Otherwise, we ask recursion function dfs() to check if the suffix is present or not
                return true ; // If dfs() returns true, we directly return true
        }
    }

    return false ; // At the end, we return false indicating S cannot be made from 2 or more shorter words
}

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> set ;

        for(string &wd : words)
            set.insert(wd) ;

        vector<string> ans ;

        for(string &currString : words)
        {
            bool isPresent = dfs(currString , set) ;

            if(isPresent == true) // If dfs(str) returns true, we include that word into our ans[] vector of string 
                ans.push_back(currString) ;
        }

        return ans ;    
    }
};

// Time Complexity:  O(N * K ^ 2) [N is the length of words[] and K is the average length of each word and we need to calculate prefix and suffix seperately]
// Space Complexity: O(N)
