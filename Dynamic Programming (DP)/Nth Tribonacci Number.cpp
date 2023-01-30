// Link: https://leetcode.com/problems/n-th-tribonacci-number/description/

// The question is exactly same to N-th Fibonacci Series question
// We will use this recursive formula to calculate tribo(n) = tribo(n - 1) + tribo(n - 2) + tribo(n - 3) ;
// We need to memoize our code such that we don't encounter TLE
// Tribo(0) = 0 ; Tribo(1) = 1 ; Tribo(2) = 1 are our Base Cases

class Solution {
private:

int tribonacci(int n , vector<int> &dp) // Recursive function to calculate Nth Tribonacci Number
{
    if(n == 0)
        return 0 ;

    if(n == 1)
        return 1 ;

    if(n == 2)
        return 1 ;
    
    if(dp[n] != -1) // Memoizing our Recursive Function
        return dp[n] ;

    int firstTerm  = tribonacci(n - 1 , dp) ;
    int secondTerm = tribonacci(n - 2 , dp) ;
    int thirdTerm  = tribonacci(n - 3 , dp) ;

    return dp[n] = (firstTerm + secondTerm + thirdTerm) ;
}

public:
    int tribonacci(int n) 
    {
        vector<int> dp(n + 1 , -1) ;

        int ans = tribonacci(n , dp) ;

        return ans ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
