class Solution {
public:
    long long maxScore(vector<int>& A , vector<int>& B , int k) 
    {
        int n = A.size() ;

        vector<pair<int , int>> nums ;

        for(int i = 0 ; i < n ; i++)
            nums.push_back( {B[i] , A[i]} ) ;

        sort(nums.begin() , nums.end() ) ;
        reverse(nums.begin() , nums.end() ) ;

        priority_queue<int , vector<int> , greater<int>> pq ;

        long long int sum = 0 ;
        long long int ans = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            sum += nums[i].second ;
            pq.push(nums[i].second) ;

            if(pq.size() > k)
            {
                sum -= pq.top() ;
                pq.pop() ;
            }

            if(pq.size() == k)
            {
                long long int minVal = nums[i].first ;
                long long int currSum = minVal * sum ;

                ans = max(ans , currSum) ;
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(N Log N)
// Space Complexity: O(N)
