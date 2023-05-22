// Link:  https://leetcode.com/problems/top-k-frequent-elements/description/

using pp = pair<int , int> ;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int , int> map ;

        for(int val : nums)  map[val] += 1 ;

        priority_queue<pp , vector<pp> , greater<pp>> minHeap ;

        for(auto &x : map)
        {
            if(k > 0)  minHeap.push({x.second , x.first}) , k-- ;

            else if(minHeap.top().first < x.second)
            {
                minHeap.pop() ; minHeap.push({x.second , x.first}) ;
            }
              
        }    

        vector<int> ans ;

        while(!minHeap.empty() ) 
        {
            ans.push_back(minHeap.top().second) ;  minHeap.pop() ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N Log K)
// Space Complexity: O(N)
