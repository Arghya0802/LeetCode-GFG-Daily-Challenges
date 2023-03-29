// Link:

using ll = long long int ;

class Solution {
private:

ll calculate_Time(int ind , int n , vector<int> &nums)
{
    ll cnt = 1 ;
    ll ans = 0 ;

    for(int i = ind ; i < n ; i++)
    {
        ans += (cnt * nums[i]) ;
        cnt++ ;
    }

    return ans ;
}

public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int n = satisfaction.size() ;

        sort(satisfaction.begin() , satisfaction.end() ) ;

        ll total = 0 ; 

        for(int val : satisfaction)
            total += val ;

        if(total >= 0)
            return (int) calculate_Time(0 , n , satisfaction)  ;

        int ind = -1 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(total >= 0)
            {
                ind = i ;
                break ;
            }

            else 
                total -= satisfaction[i] ;
        }

        if(ind == -1)
            return 0 ;

        return (int) calculate_Time(ind , n , satisfaction) ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
