// Link: https://leetcode.com/problems/sort-an-array/description/

class Solution {
private:

vector<int> merge(vector<int> &A , vector<int> &B)
{
    int m = A.size() ;
    int n = B.size() ;

    vector<int> ans ;

    int i = 0 ;
    int j = 0 ;

    while(i < m && j < n)
    {
        if(A[i] < B[j])
            ans.push_back(A[i++]) ;

        else
            ans.push_back(B[j++]) ;
    }

    for(; i < m ; i++)
        ans.push_back(A[i]) ;

    for(; j < n ; j++)
        ans.push_back(B[j]) ;

    return ans ;
}

vector<int> mergeSort(int low , int high , vector<int> &nums)
{
    if(low == high)
        return {nums[low]} ;

    if(low > high)
        return {} ;

    int mid = low + (high - low) / 2 ;

    vector<int> A = mergeSort(low , mid , nums) ;
    vector<int> B = mergeSort(mid + 1 , high , nums) ;

    vector<int> merged = merge(A , B) ;

    return merged ;
}

public:
    vector<int> sortArray(vector<int>& nums) 
    {
        vector<int> ans = mergeSort(0 , nums.size() - 1 , nums) ;

        return ans ;    
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
