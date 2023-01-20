// Link: https://leetcode.com/problems/non-decreasing-subsequences/description/

// The question is pretty straightforward - we need to generate All Possible Subsequences 
// Then, those subsequences which are Increasing in nature (<=) we consider them as valid and put inside our ans[][]
// However, we need to maintain a Set<vector<int>> to keep a check whether we are including any duplicate subsequence again or not
// The duplicacy will occurr because of NotTake condition and for repetition of same numbers, the result for which we keep getting same subsequences again and again

class Solution {
private:

// This function checks if our Current-SubSequence is Increasing or not (== is also considered)
bool isIncreasing(vector<int> &arr)
{
    int n = arr.size() ;

    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(arr[i] > arr[i + 1]) // If we find any discrepancy, we straightaway return false
            return false ;
    }

    return true ; // Otherwise we return true 
}

// This is a recursive function which generates all the subsequences and among them we include those unique subsequences which are Increasing and has a size >= 2
void generateSubsequences(int currIndex , int n , vector<int> &currSubSeq , vector<int> &nums , set<vector<int>> &set , vector<vector<int>> &ans)
{
    if(currSubSeq.size() >= 2) // If our Subsequence has a size >= 2
    {
        if(isIncreasing(currSubSeq) == true) // And if it's Increasing as well
        {
            if(set.find(currSubSeq) == set.end() ) // And we haven't yet encountered it 
            {
                ans.push_back(currSubSeq) ; // We include it into our ans[][]

                set.insert(currSubSeq) ; // We also include it into our Set Data Structure so that we don't again include it
            }
        }
    }
    
    // Base Case 
    if(currIndex >= n) // If we have traversed till the end of the array, we simply return back
        return ;
    
    // To generate all SubSequences, we always have 2 options: a)Take Current Element ; b) Don't Take Current Element 
  
    // Option 1: We include the Current Element into our SubSequence
    
    currSubSeq.push_back(nums[currIndex]) ; // We include it inside our curr-SubSequence

    generateSubsequences(currIndex + 1 , n , currSubSeq , nums , set , ans) ; // We ask recursion to do the rest of the task
    
    // We backtrack and undo the change
    currSubSeq.pop_back() ;
    
    // Option 2: We don't include the Current Element into our SubSequence
  
    generateSubsequences(currIndex + 1 , n , currSubSeq , nums , set , ans) ; // We ask recursion to do rest of the task

    return ;
}

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> ans ; // Stores all the Increasing Subsequences 

        vector<int> currSubSeq ; // Used to generate the Current SubSequences

        set<vector<int>> set ; // Used to check if we have already encountered the same subsequence previously or not

        generateSubsequences(0 , nums.size() , currSubSeq , nums , set , ans) ;

        return ans ;
    }
};

// Time Complexity:  O(2 ^ N) [We exclude the O(N) for IsIncreasing() function as well as O(Log N) required to insert a vector into our Set]
// Space Complexity: O(K) [We include the space taken by Set and ans[][] ]
