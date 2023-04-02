// Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

using ll = long long int ;

class Solution {
private:

int binarySearch(ll factor , int n , vector<int> &potions , ll target)
{
    int low = 0 ;
    int high = n - 1 ;

    int ans = -1 ;

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        ll value = (potions[mid] * 1ll) * factor ;

        if(value >= target)
        {
            ans = mid ;

            high = mid - 1 ;
        }

        else
            low = mid + 1 ;
    }

    return ans ;
}

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int n = potions.size() ;
        sort(potions.begin() , potions.end() ) ;

        vector<int> ans ;

        for(int spell : spells)
        {
            int ind = binarySearch(spell , n , potions , success) ;

            if(ind == -1)
                ans.push_back(0) ;

            else
            {
                int cnt = n - ind ;

                ans.push_back(cnt) ;
            }
        }    

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
