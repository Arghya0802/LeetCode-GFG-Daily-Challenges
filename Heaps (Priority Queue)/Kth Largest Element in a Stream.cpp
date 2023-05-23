// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
private:
priority_queue<int , vector<int> , greater<int>> minHeap ;
int K ;

public:
    KthLargest(int k, vector<int>& nums) 
    {
        int cnt = 0 ;  K = k ;

        for(int val : nums)
        {
            if(cnt < k) 
            {
                minHeap.push(val) ;  cnt++ ;
            }

            else if(minHeap.top() < val)
            {
                minHeap.pop() ;  minHeap.push(val) ;
            }
        }    
    }
    
    int add(int val) 
    {
        if(minHeap.empty() || minHeap.size() < K) minHeap.push(val) ;

        else if(val > minHeap.top() )
        {
            minHeap.pop() ;  minHeap.push(val) ;
        }    

        return minHeap.top() ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
 // Time Complexity:  O(N Log K)
 // Space Complexity: O(K)
