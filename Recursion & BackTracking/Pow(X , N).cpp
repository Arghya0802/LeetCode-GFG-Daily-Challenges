// Link:  https://leetcode.com/problems/powx-n/description/

class Solution {
private:

double myPower(double x , int n)
{
    if(n == 0)  return 1 ; 

    if(n == 1)  return x ;

    double sq = myPower(x , n / 2) ;

    return n % 2 == 0 ? sq * sq : sq * sq * x ;
}

public:
    double myPow(double x, int n) 
    {
        double ans = myPower(x ,abs(n) ) ;
        
        return n < 0 ? 1 / ans : ans ;
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(Log N) [Recursive Stack Space]
