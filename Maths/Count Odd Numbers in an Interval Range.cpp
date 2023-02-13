// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

class Solution {
public:
    int countOdds(int low, int high) 
    {
        long long int first = low ;

        if(low % 2 == 0)
            first = low + 1 ;

        long long int last = high ;

        if(high % 2 == 0)
            last = high - 1 ;

        long long int noOfTerms = ( (last - first) / 2 ) + 1 ;

        return (int) noOfTerms ;
    }
};

// Time Complexity:  O(1)
// Space Complexity: O(1)
