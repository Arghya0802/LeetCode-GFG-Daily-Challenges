// Link: https://leetcode.com/problems/find-the-highest-altitude/description/

class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = gain.size() ;
        
        int maxGain = 0 ;
        int sum = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            sum += gain[i] ;

            maxGain = max(maxGain , sum) ;
        }    

        return maxGain ;
    }
};

// Time Complextiy:  O(N)
// Space Complexity: O(1)
