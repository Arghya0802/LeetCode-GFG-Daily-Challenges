// Link:  https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int , vector<int> , greater<int>> minQ ;

        for(int val : nums)
        {
            if(minQ.size() < k)  minQ.push(val) ;

            else if(minQ.top() < val)
            {
                minQ.pop() ;  minQ.push(val) ;
            }
        }    

        return minQ.top() ;
    }
};

// Time Complexity:  O(N * Log K)
// Space Complexity: O(K)
