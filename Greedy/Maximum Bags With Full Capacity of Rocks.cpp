// Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

// This is a Classic Question of Sorting + Greedy
// As we have asked to return the Max Amount of Full Bags we need to return, that's why we need to sort the AdditionalSpace[] vector in Ascending Order

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) 
    {
        int n = rocks.size() ;

        vector<int> additionalSpace(n , 0) ;
        
        // Additional-Space[] vector is stores the Number of Rocks i-th Bag can still hold
        for(int i = 0 ; i < n ; i++)
            additionalSpace[i] = capacity[i] - rocks[i] ; 
        
        // We sort the Additional-Space[] vector such that the Bags with the Least Available Space are at the front
      
        sort(additionalSpace.begin() , additionalSpace.end() ) ;

        for(int i = 0 ; i < n ; i++)
        {
            if(extra == 0) // At any moment, if extra becomes 0, there's no point in moving forward so we break out
                break ;

            int currSpace = additionalSpace[i] ;
            
            // If Extra-Rocks-Available are more than the Additional-Space of i-th bag we full it completely
            if(extra >= currSpace)  
            {
                additionalSpace[i] = 0 ;

                extra -= currSpace ;
            }
            
            // Otherwise, we cannot full i-th rock so we make Extra-Available-Rocks as 0
            else
            {
                additionalSpace[i] = currSpace - extra ;

                extra = 0 ;
            }
        }

        int ans = 0 ;
        
        // Lastly, we count the Number of Bags made full, that is, Additional-Space of that bag is 0
        for(int i = 0 ; i < n ; i++)
        {
            if(additionalSpace[i] > 0)
                break ;

            ans += 1 ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)  [ For the Additional-Space[] vector we have created]
