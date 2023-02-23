// Link: https://leetcode.com/problems/ipo/description/

class Solution {
public:
    int findMaximizedCapital(int k , int totalCapital , vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size() ;

        priority_queue<int> maxProfit ; 

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>> > minCapital ;
        
        for(int i = 0 ; i < n ; i++)
        {
            int caps = capital[i] ;
            int gain = profits[i] ;
          
            minCapital.push( {caps , gain} ) ;
        }

        int ans = 0 ;

        while(k--)
        {
            while(!minCapital.empty() && minCapital.top().first <= totalCapital)
            {
                int profit = minCapital.top().second ;
                maxProfit.push(profit) ;

                minCapital.pop() ;
            }

            if(maxProfit.empty() == true)
                return totalCapital ;
            
            totalCapital += maxProfit.top() ;

            maxProfit.pop() ;
        }   

        return totalCapital ;     
    }
};

// Time Complexity:  O(K * LogN + N * LogN)
// Space Complexity: O(N)
