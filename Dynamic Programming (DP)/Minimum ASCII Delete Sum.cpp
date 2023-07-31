// Link:  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

class Solution {
private:
vector<vector<int>> dp ;

int calculate(int ind , string &A)
{
    int n = A.size() ; int sum = 0 ;

    for(; ind < n ; ind++)  sum += A[ind] ;

    return sum ;
}

int minDeleteSum(int i , int j , string &s , string &t)
{
    if(i >= s.size() && j >= t.size() )  return 0 ;

    if(i >= s.size() )  return calculate(j , t) ;

    if(j >= t.size() )  return calculate(i , s) ;

    if(dp[i][j] != -1)  return dp[i][j] ;
    
    int ans = INT_MAX ;

    if(s[i] == t[j] )  ans = minDeleteSum(i + 1 , j + 1 , s , t) ;

    else
    {
        int delS = minDeleteSum(i + 1 , j , s , t) + s[i] ;
        int delT = minDeleteSum(i , j + 1 , s , t) + t[j] ;

        ans = min(delS , delT) ;
    }  

    return dp[i][j] = ans ;
}

public:
    int minimumDeleteSum(string s1, string s2) 
    {
        dp.resize(s1.size() + 1 , vector<int> (s2.size() + 1 , -1) ) ;

        return minDeleteSum(0 , 0 , s1 , s2) ;    
    }
};

// Time Complexity:  O(M * N) 
// Space Complexity: O(M * N)
