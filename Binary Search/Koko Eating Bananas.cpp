// Link: https://leetcode.com/problems/koko-eating-bananas/description/

using ll = long long int ;

class Solution {
private:

bool isPossible(ll maxSpeed , ll h , vector<int> &piles)
{
    ll cnt = 0 ;

    for(int bananas : piles)
    {
        if(bananas <= maxSpeed)
            cnt += 1 ;

        else if(bananas % maxSpeed == 0)
            cnt += bananas / maxSpeed ;

        else 
            cnt += (bananas / maxSpeed) + 1 ;
    }

    return cnt <= h ;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        ll total = 0 ;

        for(int bananas : piles)
            total += bananas ;
            
        ll low  = 1 ;
        ll high = total ;

        ll ans = -1 ;

        while(low <= high)
        {
            ll mid = low + (high - low) / 2 ;

            if(isPossible(mid , h , piles) == true)
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
