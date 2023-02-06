// Link: https://leetcode.com/problems/shuffle-the-array/description/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> ans ;

        bool choiceX = true ;
        int i = 0 ;
        int j = n ;

        while(i < n || j < (2 * n) )
        {
            if(choiceX == true)
                ans.push_back(nums[i++]) ;

            else
                ans.push_back(nums[j++]) ;

            choiceX = !choiceX ;
        }    

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
