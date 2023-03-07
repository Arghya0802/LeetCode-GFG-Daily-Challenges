// Link: https://leetcode.com/problems/minimum-time-to-complete-trips/description/

using ll = long long int ;

class Solution {
private:

bool isPossible(ll maxTime , ll totalTrips , vector<int> &times)
{
    ll cnt = 0 ;

    for(int time : times)
    {
        if(cnt >= totalTrips)
            return true ;

        if(time <= maxTime)
            cnt += maxTime / time ;
    }

    return cnt >= totalTrips ;
}

public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        ll low = 1 ;
        ll high = 1e16 ;
        ll ans = -1 ;

        while(low <= high)
        {
            ll mid = low + (high - low) / 2 ;

            if(isPossible(mid , totalTrips , time) == true)
            {
                ans = mid ;

                high = mid - 1 ;
            }

            else
                low = mid + 1 ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
