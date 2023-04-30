// Link:  https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    int countPrimes(int n) 
    {
        if(n <= 1)  return 0 ;
        
        vector<int> primes(n , 1) ;

        primes[0] = 0 , primes[1] = 0 ;

        for(int i = 2 ; i * i < n ; i++)
        {
            if(primes[i] == 1)
            {
                for(int j = i * i ; j < n ; j += i)  primes[j] = 0 ;
            }
        }

        int maxCnt = 0 ;

        for(int i = 2 ; i < n ; i++)
        {
            if(primes[i] == 1)  maxCnt += 1 ;
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(N * Log(LogN))
// Space Complexity: O(N)
