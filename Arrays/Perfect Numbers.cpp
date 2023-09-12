// Link:  https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1

class Solution {
  public:
    int isPerfectNumber(long long N) 
    {
        if(N == 1)  return 0 ;
        
        long long int sumOfFacts = 1 ;
        
        for(long long i = 2 ; i * i <= N ; i++)
        {
            if(N % i == 0)  
            {
                sumOfFacts += i ;  sumOfFacts += N / i ;
            }
        }
        
        return sumOfFacts == N ;
    }
}

// Time Complexity:  O(Sqrt N)
// Space Complexity: O(1)
