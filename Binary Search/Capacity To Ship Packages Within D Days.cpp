// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
private:

bool isPossible(long long int maxCapacity , int days , vector<int> &weights)
{
    int cnt = 0 ;

    long long int currCapacity = 0 ;

    for(int weight : weights)
    {
        if(currCapacity + weight <= maxCapacity)
            currCapacity += weight ;

        else
        {
            cnt += 1 ;
            
            currCapacity = weight ;
        }
    }

    if(currCapacity <= maxCapacity)
        cnt++ ;

    return cnt <= days ;
}

public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size() ;

        int maxWeight = 0 ;
        long long int totalWeight = 0 ;

        for(int weigh : weights)
        {
            maxWeight = max(maxWeight , weigh) ;

            totalWeight += weigh ;

        }

        long long int low  = maxWeight   ;
        long long int high = totalWeight ;
        
        long long int ans = -1 ;

        while(low <= high)
        {
            long long int mid = low + (high - low) / 2 ;

            if(isPossible(mid , days , weights) == true)
            {
                ans = mid ;

                high = mid - 1 ;
            }

            else
                low = mid + 1 ;
        }

        return (int) ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
