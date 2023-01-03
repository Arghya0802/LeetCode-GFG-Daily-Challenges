// Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

// We just need to use a simple observation - everytime we are deducting the Highest or Max Element from piles[] array
// That's when we should get the intuiton of using Priority-Queue [Max-Heap] to help our cause

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int n = piles.size() ;

        priority_queue<int> pq ; // Max-Heap is required as we require to find the Max-Element from piles[] array everytime after deduction 

        for(int nums : piles)
            pq.push(nums) ;

        int cnt = 0 ;
        
        // We push all the elements into Priority-Queue for K times
        while(cnt < k)
        {
            int top = pq.top() ;
            pq.pop() ;

            top -= (top / 2) ; // We deduct the top element by top - (top / 2)

            pq.push(top) ; // We again insert it into our Priority-Queue for the next iteration

            cnt += 1 ;
        }

        int ans = 0 ; // Our ans will store the sum of all the elements present in our Priority-Queue after all deductions

        while(pq.empty() == false)
        {
            ans += pq.top() ;
            pq.pop() ;
        }

        return ans ;
    }
};

// Time Complexity:  O(K * Log N)
// Space Complexity: O(K)
