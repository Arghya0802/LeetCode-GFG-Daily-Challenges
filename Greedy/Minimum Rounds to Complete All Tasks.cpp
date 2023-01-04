// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

// The main appraoch of the question is to use Greedy approach
class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int , int> map ; 

        for(int nums: tasks)    
            map[nums] += 1 ;

        int ans = 0 ;

        for(auto &x : map)
        {
            int freq = x.second ;
            
            if(freq % 3 == 0)
                ans += freq / 3 ;

            else
                ans += (freq / 3) + 1 ;
        }

        
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
