// Link: https://leetcode.com/problems/gas-station/description/

class Solution {
public:
  
    // This question is very tricky as is the case with most Greedy Problems
    // We need to keep in mind before understanding the approach
    // 1. The Sum of Gas[] array should always be greater than Cost[] array. If not, it's not possible so return -1
    // 2. If true, then we are very sure an Unique Solution is present in the array 
    // 3. We can find the StartIndex by simply checking if the gas accquired is greater than or equal to cost it takes to travel to the next index
    // 4. This is the kind of intuition we need to work with.
    // 5. Our ans will be that index from where on we will always get net positive outcome till we move out of the array 
  
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size() ;

        int totalGas  = 0 ;
        int totalCost = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            totalGas  += gas[i] ;

            totalCost += cost[i] ;
        }

        if(totalCost > totalGas) // If Total Available Gas is less than Cost it takes to travel, we won't have an answer so we return -1
            return -1 ;

        int total = 0 ; // Total keeps track of the Gas accquired and Fuel wasted
        int ans = 0 ; // Stores the startIndex, initially with 0 because our startIndex might be 0 as well 

        for(int i = 0 ; i < n ; i++)
        {
            total += gas[i] - cost[i] ; // We take Gas[i] and deduct Cost[i]

            if(total < 0) // If Total becomes negative, we are pretty sure Our ans will never be any index from [0 till i]
            {
                ans = i + 1 ; // Thus we update ans to the next possible index

                total = 0 ; // We reset Total to zero
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
