// Link:  https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

class Solution {
private:
vector<vector<int>> dp ;

int maxLongestSubseq(int ind , int n , int prevIndex , int diff , vector<int> &nums)
{
    if(ind >= n)  return 0 ;

    if(dp[ind][prevIndex + 1] != -1)  return dp[ind][prevIndex + 1] ;

    int skip = maxLongestSubseq(ind + 1 , n , prevIndex , diff , nums) ;
    
    int pick = 0 ;

    if(prevIndex == -1 || nums[ind] - diff == nums[prevIndex]) 
        pick = 1 + maxLongestSubseq(ind + 1 , n , ind , diff , nums) ;

    // else  newSeq = maxLongestSubseq(ind + 1 , n , nums[ind] , diff , nums) ;
    
    return dp[ind][prevIndex + 1] = max(pick , skip) ;
}

public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        int n = arr.size() ;

        // dp.resize(n + 1 , vector<int> (n + 10 , -1) ) ;
        
        // return maxLongestSubseq(0 , n , -1 , difference , arr) ;    

        unordered_map<int , int> map ;  int maxSeq = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            int val = arr[i] ;

            if(map.find(val - difference) != map.end() ) 
            {
                int freq = map[val - difference] ; 

                map[val] = freq + 1 ;
            }

            else  map[val] = 1 ;
        }

        for(auto &x : map)  maxSeq = max(maxSeq , x.second) ;

        return maxSeq ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
