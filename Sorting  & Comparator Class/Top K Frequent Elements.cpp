// Link: https://leetcode.com/problems/top-k-frequent-elements/description/

using pp = pair<int , int> ;

class Solution {
public:

    static bool cmp(pp &A , pp &B)
    {
        return A.first > B.first ;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int , int> map ;

        for(int val : nums)  map[val] += 1 ;

        vector<pp> arr ;   

        for(auto &x : map) arr.push_back({x.second , x.first}) ;

        sort(arr.begin() , arr.end() , cmp) ;

        vector<int> ans ;

        for(int i = 0 ; i < k ; i++)  ans.push_back(arr[i].second) ;

        return ans ; 
    }
};

// Time Complexity:  O(N Log N)
// Space Complexity: O(N)
