// Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

class Solution {
private:

int binarySearch(int searchDay , int n , vector<int> &days)
{
    int low = 0 ;
    int high = n - 1 ;

    int ans = -1 ;

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        if(days[mid] == searchDay)
            return mid ;

        else if(days[mid] > searchDay)
        {
            ans = mid ;
            high = mid - 1 ;
        }

        else
            low = mid + 1 ;
    }
    

    return ans ;
}

int dfs(int currIndex , int n , vector<int> &days , vector<int> &costs , vector<int> &dp)
{
    if(currIndex >= n)
        return 0 ;

    if(dp[currIndex] != -1)
        return dp[currIndex] ;
    
    int cost_1 = costs[0] , cost_7 = costs[1] , cost_30 = costs[2] ;

    int currDay = days[currIndex] ;

    int nextDay = binarySearch(currDay + 1 , n , days) ;
    
    if(nextDay != -1)
        cost_1 += dfs(nextDay , n , days , costs , dp) ;

    nextDay = binarySearch(currDay + 7 , n , days) ;

    if(nextDay != -1)
        cost_7 += dfs(nextDay , n , days , costs , dp)  ;

    nextDay = binarySearch(currDay + 30 , n , days) ;

    if(nextDay != -1)
        cost_30 += dfs(nextDay , n , days ,costs , dp)  ;

    return dp[currIndex] = min(cost_1 , min(cost_7 , cost_30) ) ;
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n = days.size() ;

        vector<int> dp(n + 1 , -1) ;

        int ans = dfs(0 , n , days , costs , dp) ; 

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
