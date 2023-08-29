// Link:  https://leetcode.com/problems/minimum-penalty-for-a-shop/description/

class Solution {
public:
    int bestClosingTime(string &customers) 
    {
        customers.push_back('N') ;

        int n = customers.size() ;

        int totalA = 0 ; 

        for(int i = 1 ; i < n ; i++)
        {
            if(customers[i] == 'Y')  totalA++ ;
        }

        int sumA = 0 ; int sumB = 0 ;  int minPenalty = INT_MAX ; int ind = -1 ;

        for(int i = 0 ; i < n ; i++)
        {
            int penalty = totalA - sumA + sumB ;

            if(minPenalty > penalty)
            {
                minPenalty = penalty ;  ind = i ;
            }

            if(customers[i] == 'Y')  sumA++ ;

            else sumB++ ;
        }
        
        return ind ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
