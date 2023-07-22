// Link:  https://leetcode.com/problems/number-of-longest-increasing-subsequence/

using pp = pair<int , int> ;

class Solution {
private:
vector<vector<pp>> dp ;
// unordered_map<string , pp> dp ;

pp countLIS(int ind , int prevIndex , vector<int> &nums)
{
    if(ind >= nums.size() )  return make_pair(0 , 1) ;

    if(dp[ind][prevIndex + 1].first != -1)  return dp[ind][prevIndex + 1] ;

    // string key = to_string(ind) + "-" + to_string(prevIndex + 1) ;

    // if(dp.find(key) != dp.end() )  return dp[key] ;

    pp skip = countLIS(ind + 1 , prevIndex , nums) ;  pp pick = make_pair(0 , 0) ;

    if(prevIndex == -1 || nums[ind] > nums[prevIndex] )
    {
        auto ans = countLIS(ind + 1 , ind , nums) ;

        pick.first = 1 + ans.first ;  pick.second = ans.second ;
    }

    if(pick.first == skip.first)  
    {
        pick.second += skip.second ;  return dp[ind][prevIndex + 1] = pick ;
    }

    return dp[ind][prevIndex + 1] = pick.first > skip.first ? pick : skip ;
}

public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size() ;

        dp.resize(n + 1) ;

        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= n ; j++)  dp[i].push_back(make_pair(-1,  -1) ) ;
        }

        return countLIS(0 , -1 , nums).second ;
    }
};

// Time Complexity:  O(N * K)
// Space COmplexity: O(N * K)
