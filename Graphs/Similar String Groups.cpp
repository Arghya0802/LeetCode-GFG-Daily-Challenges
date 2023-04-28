// Link: https://leetcode.com/problems/similar-string-groups/description/

class Solution {
private:

bool is_Similar(string &a , string &b)
{
    int cnt = 0 ;

    for(int i = 0  ; i < a.size() ; i++)
    {
        if(a[i] != b[i])  cnt += 1 ;
    }

    return cnt == 0 || cnt == 2 ;
}

void dfs(int currIndex , int n , string &s , vector<int> &visited , vector<string> &str)
{
    visited[currIndex] = 1 ;

    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == 1)  continue ;

        if(is_Similar(s , str[i]) == true)  dfs(i , n , str[i] , visited , str) ;
    }
    
    return ;
}

public:
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size() ;
        vector<int>visited(n , 0) ;

        int maxGrps = 0 ;

        for(int ind = 0 ; ind < n ; ind++)
        {
            if(!visited[ind])
            {
                dfs(ind , n , strs[ind] , visited , strs) ;
                
                maxGrps += 1 ;
            }
        }

        return maxGrps ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
