// Link: https://leetcode.com/problems/predict-the-winner/description/

// Even though its solved using DP, the recursive code will also get accepted

class Solution {
private:
vector<vector<vector<int>>> dp ;

int maxScore(int start , int end , bool myChance , vector<int> &nums)
{
    if(start > end)  return 0 ;
    
    if(dp[start][end][myChance] != INT_MAX)  return dp[start][end][myChance] ;

    int startScore = myChance ? nums[start] : -nums[start] ;
    int endScore   = myChance  ? nums[end] : -nums[end] ;

    int opS = maxScore(start + 1 , end , !myChance , nums) + startScore ;
    int opE = maxScore(start , end - 1 , !myChance , nums) + endScore ;

    return dp[start][end][myChance] = myChance ? max(opS , opE) : min(opS , opE) ;
}

public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size() ;

        dp.resize(n + 1 , vector<vector<int>> (n + 1 , vector<int> (2 , INT_MAX) ) ) ;

        int player1 = maxScore(0 , n - 1 , true , nums) ;
        
        return player1 >= 0 ;
    }
};

// Time Complexity:  O(N * N * 2)
// Space Complexity: O(N * N * 2)
