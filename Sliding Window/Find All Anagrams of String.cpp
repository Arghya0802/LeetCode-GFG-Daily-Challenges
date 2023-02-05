// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// Exactly same solution as yesterday's code
// Only difference is that we need to find all the starting indices of substrings in S which are anagarms or Permutations of P
// Sliding Window of Fixed Size[K = P.size() ]

class Solution {
private:

bool areVectorsSame(vector<int> &freq , vector<int> &currCnt)
{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(freq[i] != currCnt[i])
            return false ;
    }

    return true ;
}

public:
    vector<int> findAnagrams(string &s, string &p) 
    {
        int k = p.size() ;
        int n = s.size() ;

        if(k > n)
            return {} ;

        int index = 0 ;
        vector<int> freq(26 , 0) ;

        for(char ch : p)
        {
            index = (int) (ch - 'a') ;

            freq[index] += 1 ;
        }

        vector<int> ans ;

        int start = 0 ;
        int end = 0 ;

        vector<int> currCnt(26 , 0) ;

        while(start < k)
        {
            index = (int) (s[start] - 'a') ;

            currCnt[index] += 1 ;
            start++ ;
        }

        if(areVectorsSame(freq , currCnt) == true)
            ans.push_back(0) ;

        for(; start < n ; start++)
        {
            index = (int) (s[end] - 'a') ;
            end++ ;
            currCnt[index] -= 1 ;

            index = (int) (s[start] - 'a') ;
            currCnt[index] += 1 ;

            if(areVectorsSame(freq , currCnt) == true)
                ans.push_back(end) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * 26)
// Space Complexity: O(N) [To store the starting indices]
