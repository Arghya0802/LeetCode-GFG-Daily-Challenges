// Link: https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size() ;

        int end = 0 ;
        int ans = 0 ;

        unordered_map<int , int> map ;
        int disCnt = 0 ;

        for(int start = 0 ; start < n ; start++)
        {
            int newAccept = fruits[start] ;

            if(map.find(newAccept) == map.end() )
                disCnt++ ;

            map[newAccept] += 1 ;

            while( (end <= start) && (disCnt > 2) )
            {
                int discard = fruits[end] ;

                map[discard] -= 1 ;

                if(map[discard] == 0)
                {
                    map.erase(discard) ;

                    disCnt-- ;
                }

                end++ ;
            }

            ans = max(ans , start - end + 1) ;

        } 

        return ans ;   
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(2) [As we keep only 2 fruits into the basket all the time]
