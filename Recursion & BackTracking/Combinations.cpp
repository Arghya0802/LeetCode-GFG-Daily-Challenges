// Link:  https://leetcode.com/problems/combinations/description/

class Solution {
private:
vector<vector<int>> ans ;

void allCombinations(int ind , int n , int k , vector<int> &subset)
{
    if(k == 0)
    {
        ans.push_back(subset) ;  return ;
    }

    for(int i = ind ; i <= n ; i++)
    {
        subset.push_back(i) ;

        allCombinations(i + 1 , n , k - 1 , subset) ;

        subset.pop_back() ;
    }

    return ;
}

public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> subset ;

        allCombinations(1 , n , k , subset) ;

        return ans ;        
    }
};

// Time Complexity:  O(n C k)  [ All possible combinations of length K out of N ]
// Space Complexity: O(n C K)
