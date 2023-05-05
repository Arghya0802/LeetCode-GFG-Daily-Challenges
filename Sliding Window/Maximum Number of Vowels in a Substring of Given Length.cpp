// Link:  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
private:

int isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true ;

    return false ;
}

public:
    int maxVowels(string &s , int k) 
    {
        int n = s.size() ;

        int ans = 0 ;
        int cnt = 0 ;

        int start = 0 ;
        int end = 0 ;

        while(start < k)
        {
            if(isVowel(s[start]) == true)
                cnt++ ;

            start++ ;
        }

        ans = max(ans , cnt) ;

        for(; start < n ; start++)
        {
            if(isVowel(s[end]) == true)
                cnt-- ;

            end++ ;

            if(isVowel(s[start]) == true)
                cnt++ ;

            ans = max(ans , cnt) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
