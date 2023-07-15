// Link:  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

class Solution {
private:
vector<vector<vector<int>>> dp ;
unordered_map<string , int> map ;

int solve(int ind , int lastMeetIndex , int k , vector<vector<int>> &events)
{
    if(k == 0)  return 0 ;

    if(ind >= events.size() )  return 0 ;

    // if(dp[ind][lastMeetIndex + 1][k] != -1)  return dp[ind][lastMeetIndex + 1][k] ;

    string key = to_string(ind) + "-" + to_string(lastMeetIndex + 1) + "-" + to_string(k) ;

    if(map.find(key) != map.end() )  return map[key] ;

    int skip = solve(ind + 1 , lastMeetIndex , k , events) ;  int pick = 0 ;

    if(lastMeetIndex == -1 || events[ind][0] > events[lastMeetIndex][1] )  
        pick = events[ind][2] + solve(ind + 1 , ind , k - 1 , events) ;

    // return dp[ind][lastMeetIndex + 1][k] = max(pick , skip) ;

    return map[key] = max(pick , skip) ;
}

public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        int n = events.size() ;

        // dp.resize(n + 1 , vector<vector<int>> (k + 1 , vector<int> (k + 1 , -1) ) ) ;

        sort(events.begin() , events.end() ) ;

        return solve(0 , -1 , k , events) ;
    }
};

// Time Complexity:  O(N * N * K)
// Space Complexity: O(N * N * K)
