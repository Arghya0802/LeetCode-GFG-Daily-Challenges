// https://leetcode.com/problems/guess-number-higher-or-lower/description/

// This is a classic question of Binary-Search
class Solution {
public:
    int guessNumber(int n) 
    {
        // Our Search Space is between [1...N] (both incluisve)
        int low = 1 ; 
        int high = n ;

        while(low <= high) // We do the normal BinarySearch
        {
            int mid = low + (high - low) / 2 ; // We calculate Mid

            int guessVal = guess(mid) ; // We check if our Mid value is equal to Pick(Guessed) Value or not
            
            // If they are same, we return Mid
            if(guessVal == 0) // Target == Mid
                return mid ;
            
            // If Guessed Number is greater than Mid, we increment our search space to [Mid + 1 ..... High]
            else if(guessVal == 1) // Target > Mid
                low = mid + 1 ;
            
            // Similarly, if Guessed Number is lower than our Mid, we decrement our search space to [Low ...... Mid - 1]
            else    
                high = mid - 1 ;

        }

        return -1 ;    
    }
};

// Time Complexity:  O(LogN)
// Space Complexity: O(1)
