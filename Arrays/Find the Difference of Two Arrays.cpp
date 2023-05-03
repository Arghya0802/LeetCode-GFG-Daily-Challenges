// Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans(2) ;

        int freq[2001] = {0} , commonNums[2001] = {0} ;

        for(int nums : nums1)  freq[nums + 1000] += 1 ;

        for(int nums : nums2)
        {
            if(freq[nums + 1000] > 0)  commonNums[nums + 1000] += 1 ;
        }    

        int setA[2001] = {0} , setB[2001] = {0} ;

        for(int nums : nums1)
        {
            if(commonNums[nums + 1000] == 0 && setA[nums + 1000] == 0)
            {
                ans[0].push_back(nums) ;
                setA[nums + 1000] += 1 ;
            }
        }

        for(int nums : nums2)
        {
            if(commonNums[nums + 1000] == 0 && setB[nums + 1000] == 0)
            {
                ans[1].push_back(nums) ;
                setB[nums + 1000] += 1 ;
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(M + N)
// Space Complexity: O(1)
