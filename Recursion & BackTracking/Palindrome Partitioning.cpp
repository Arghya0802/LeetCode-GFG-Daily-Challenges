// Link: https://leetcode.com/problems/palindrome-partitioning/description/

// The idea is very simple - We will make only Intelligent Cuts
// An Intelligent Cut is a cut which ensures that the string made is a Palindrome
// As we need to generate all possible Palindrome Partionining, we have to use Backtracking

class Solution {
private:

// Checks if string str is a Palindrome or not and returns true or false accordingly
bool isPalindrome(string &str)
{
    int low = 0 ;
    int high = str.size() - 1 ;

    while(low <= high)
    {
        if(str[low] != str[high])
            return false ;

        low += 1 ;
        high -= 1 ;
    }

    return true ;
}

void palindromePartitioning(int currIndex , int n , string &s , vector<string> &currPalin , vector<vector<string>> &ans)
{
    if(currIndex >= n) // As we need to partioned the entire string, we need to check when we have traversed the entire string S
    {
        ans.push_back(currPalin) ; // Whatever our currPalin[] vector has we push it inside our ans[] vector

        return ; // And from base case we return back
    }

    string subString = "" ; // Helps to generate the SubString from i = currIndex till i < n

    for(int ind = currIndex ; ind < n ; ind++)
    {
        subString += s[ind] ;

        if(isPalindrome(subString) == true) // If subString is a Palindrome, we have got one possible string
        {
            currPalin.push_back(subString) ; // We push it into currPalin[] vectors which contains all such Palindrome Partioning 

            palindromePartitioning(ind + 1 , n , s , currPalin , ans) ; // We ask recursion to do rest of the task

            currPalin.pop_back() ; // After we return, we have to backtrack and undo the change
        }
    }

    return ;
}

public:
    vector<vector<string>> partition(string &s) 
    {
        vector<string> currPalin ;

        vector<vector<string>> ans ;

        palindromePartitioning(0 , s.size() , s , currPalin , ans) ;

        return ans ;
    }
};

// Time Complexity:  O(Exponential)
// Space Complexity: O(N) [Our ans[] vector contains all such possible Palindrome Partitions ]
