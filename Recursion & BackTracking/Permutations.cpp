// Link:  https://leetcode.com/problems/permutations/description/

class Solution {
private:
vector<vector<int>> ans ;

void permutations(int ind , vector<int> &nums)
{
    if(ind >= nums.size() ) 
    {
        ans.push_back(nums) ;  return ;
    }

    for(int i = ind ; i < nums.size() ; i++)
    {
        swap(nums[ind] , nums[i] ) ;

        permutations(ind + 1 , nums) ;

        swap(nums[ind] , nums[i] ) ;
    }

    return ;
}

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        permutations(0 , nums) ;

        return ans ;
    }
};

// Time Complexity:  O(N!)
// Space Complexity: O(N!) [ To store all the Permutations of the given array]
