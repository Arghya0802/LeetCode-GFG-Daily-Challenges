// LeetCode: https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int n = letters.size() ;

        int low = 0 ;  int high = n - 1 ;
        int ans = -1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(letters[mid] > target)
            {
                ans = mid ; high = mid - 1 ;
            }

            else  low = mid + 1 ;
        }    

        return ans == -1 ? letters[0] : letters[ans] ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
