// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string &haystack , string &needle) 
    {
        int m = haystack.size() ;
        int n = needle.size() ;

        if(n > m)
            return -1 ;

        vector<int> nums ;

        for(int i = 0 ; i < m ; i++)
        {
            if(haystack[i] == needle[0])
                nums.push_back(i) ;
        }

        if(nums.size() == 0)
            return -1 ;

        int len = nums.size() ;

        for(int i = 0 ; i < len ; i++)
        {
            int cnt = 0 ;

            int index = nums[i] ;

            for(int j = 0 ; j < n ; j++)
            {
                if(index == m)
                    break ;

                if(haystack[index] != needle[j])
                    break ;

                else
                {
                    cnt += 1 ;
                    
                    index += 1 ;
                }
            }

            if(cnt == n)
                return nums[i] ;
        }

        return -1 ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M)
