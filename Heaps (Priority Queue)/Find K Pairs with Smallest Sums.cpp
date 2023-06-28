// Link:  https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

using pp = pair<int , pair<int , int>> ;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &A , vector<int> &B , int k) 
    {
        int m = A.size() ;  int n = B.size() ;

        vector<vector<int>> ans ;

        priority_queue<pp , vector<pp> , greater<pp>> minQ ;
        set<pair<int , int>> set ;

        minQ.push({A[0] + B[0] , make_pair(0 , 0) } ) ; 
        set.insert(make_pair(0 , 0)) ;

        while(k-- && !minQ.empty() )
        {
            int i = minQ.top().second.first ;  int j = minQ.top().second.second ;
            minQ.pop() ;

            // if(i + 1 == m || j + 1 == n)   return ans ;
            
            ans.push_back( { A[i] , B[j] } ) ;

            if(i + 1 < m && set.find({i + 1, j}) == set.end())
            {
                set.insert(make_pair(i+1, j)) ;

                int sumA = A[i+1] + B[j] ;  
                 minQ.push({sumA , make_pair(i+1 , j) } ) ; 
        
            }

            if(j + 1 < n && set.find({i , j + 1}) == set.end())
            {
                set.insert(make_pair(i , j + 1)) ;

                int sumA = A[i] + B[j+1] ;   
                minQ.push({sumA , make_pair(i , j+1) } ) ; 
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(K * Log N)
// Time Complexity:  O(N)
