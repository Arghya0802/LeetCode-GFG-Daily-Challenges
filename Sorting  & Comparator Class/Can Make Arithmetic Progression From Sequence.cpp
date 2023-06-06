// Link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        int n = arr.size() ;
        
        if(n <= 2)  return true ;

        sort(arr.begin() , arr.end() ) ;

        int diff = arr[1] - arr[0] ;

        for(int i = 1 ; i < n - 1 ; i++)
        {
            if(diff != arr[i + 1] - arr[i])  return false ;
        }

        return true ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
