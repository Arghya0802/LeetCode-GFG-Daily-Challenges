// Link:  https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size() ;  deque<int> dq ;

        vector<int> ans ;

        for(int i = 0 ; i < n ; i++)
        {
            if(!dq.empty() && i - dq.front() >= k)  dq.pop_front() ;

            while(!dq.empty() && nums[dq.back()] <= nums[i] )  dq.pop_back() ;

            dq.push_back(i) ;

            if(i >= k - 1)  ans.push_back(nums[dq.front()] ) ;
        }    

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
