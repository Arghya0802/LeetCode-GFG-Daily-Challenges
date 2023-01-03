// Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

// The entire trick of the question lies in the fact that we are looking for Subsequence Sum and not the exact Subsequence
// That's why order doesn't matter: [8 , 4] or [4 , 8] both yields us 12 as the sum 
// We thus apply Greedy logic and sort nums[] and do likewise

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = nums.size() ;
        int m = queries.size() ;

        vector<int> ans(m , -1) ; // ans[] will be of length M

        sort(nums.begin() , nums.end() ) ; // We need to maximise the Length that's why we sort nums[]
        
        for(int ind = 0 ; ind < m ; ind++) // We iterate over queries[] vector
        {
            int query = queries[ind] ;
            
            // Sum will store the running sum and Cnt will count the number of elements we have encountered till now
            int sum = 0 ;
            int cnt = 0 ;

            for(int i = 0 ; i < n ; i++)
            {
                sum += nums[i] ;

                if(sum > query) // As soon as the Sum becomes greater than queries[i], we break out
                    break ;

                cnt += 1 ; // Otherwise, We increment Cnt by 1
            }

            ans[ind] = cnt ; // We update our ans[ind] with Cnt
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N * Q + N Log N) = O(N * Q) [ We have to iterate over Q and N every time]
// Space Complexity: O(M) [ Ans[] array is of length M]
