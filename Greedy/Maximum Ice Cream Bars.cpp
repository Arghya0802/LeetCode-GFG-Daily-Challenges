// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/

// Simple Greedy Implementation is required as we need to maximize our count of number Ice Cream Bars
// Also order doesn't matter that's why we can sort the array in Ascending order

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int n = costs.size() ;

        sort(costs.begin() , costs.end() ) ;

        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++)    
        {
            if(costs[i] <= coins) // We keep on taking Ice-Cream Bars as long as we have Coins left
            {
                cnt += 1 ;

                coins -= costs[i] ;
            }

            else // Once our coins count becomes zero, we can't buy any more ice-creams
                break ;
        }

        return cnt ;
    }
};

// Time Complexity:  O(N * Log N) [As we sort the array to maximise our count]
// Space Complexity: O(1)
