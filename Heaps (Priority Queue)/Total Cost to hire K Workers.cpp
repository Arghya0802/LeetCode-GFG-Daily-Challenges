// Link:  https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

using ll = long long int ;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        int n = costs.size() ;
        priority_queue<int , vector<int> , greater<int>> minQA , minQB ;

        int indA = 0 ; int indB = n - 1 ;  ll cnt = 0 ;

        for(; indA < candidates ; indA++)  minQA.push(costs[indA]) ;

        while(candidates--)
        {
            if(indA > indB)  break ;

            minQB.push(costs[indB]) ;  indB-- ;
        }    

        while(k--)
        {
            int valA = minQA.empty() ? INT_MAX : minQA.top() ;
            int valB = minQB.empty() ? INT_MAX : minQB.top() ;
            
            if(valA == INT_MAX && valB == INT_MAX)  return cnt ;

            if(valA <= valB)
            {
                cnt += valA ; minQA.pop() ;

                if(indA <= indB)
                {
                    minQA.push(costs[indA]) ; indA++ ;
                }
            }

            else
            {
                cnt += valB ; minQB.pop() ;

                if(indA <= indB)
                {
                    minQB.push(costs[indB]) ;  indB-- ;
                }
            }
        }

        return cnt ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(Candidates)
