// Link:  https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

class Solution {
private:

bool isPossible(int maxSpeed , vector<int> &dist , double hour)
{
    double total = 0 ;

    for(int i = 0 ; i < dist.size() ; i++)
    {
        if(i == dist.size() - 1)  total += (dist[i] * 1.0 / maxSpeed * 1.0) ;
        
        else total += ceil(dist[i] * 1.0 / maxSpeed * 1.0) ;
    }

    return total <= hour ;
}

public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int low = 1 ;  int high = 1e7 ;
        int ans = -1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(isPossible(mid , dist , hour) )
            {
                ans = mid ;  high = mid - 1 ;
            }

            else low = mid + 1 ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
