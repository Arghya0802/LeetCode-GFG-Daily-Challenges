// Link: https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int n) 
    {
        // No Ugly Number is present for N <= 0
        if(n <= 0)
            return false ;

        // As Ugly Number consists of factors of 2,3 and 5 only
        // We will use this as part of our logic - checking for Prime Factors of given N    

        // The Smllest Ugly Number is 1, so we will check till our value gets reduced to 1 or not

        while(n != 1)
        {
            if(n % 2 == 0)
                n /= 2 ;

            else if(n % 3 == 0)
                n /= 3 ;

            else if(n % 5 == 0)
                n /= 5 ;

            else
                return false ;
        }

        return true ;

    }
};
