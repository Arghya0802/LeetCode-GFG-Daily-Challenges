// Link:

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int n = people.size() ;
        sort(people.begin() , people.end() ) ;

        int start = 0 , end = n - 1 ;    
        int cnt = 0 ;

        while(start <= end)
        {
            int weight = people[start] + people[end] ;

            if(start == end)
                weight -= people[end] ;

            if(weight <= limit)
            {
                start++ ;
                end-- ;
            }

            else
                end-- ;

            cnt++ ;
        }

        return cnt ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
