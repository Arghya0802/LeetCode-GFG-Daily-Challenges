// Link: https://leetcode.com/problems/last-stone-weight/description/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> maxHeap ;

        for(int stone : stones)  maxHeap.push(stone) ;

        while(!maxHeap.empty() )
        {
            if(maxHeap.size() == 1)  break ;

            int x = maxHeap.top() ; maxHeap.pop() ;
            int y = maxHeap.top() ; maxHeap.pop() ;

            if(x != y)  maxHeap.push(x - y) ;
        }    

        return maxHeap.empty() ? 0 : maxHeap.top() ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
