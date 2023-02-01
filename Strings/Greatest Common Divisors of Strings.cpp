// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

// The question is not as easy as it seems. We need to look for the Greatest Common Prefix between S1 and S2
// This can only be possible if we look for all the SubStrings of S1 and S2 [whichever is greater] and check if it's part of the Smaller one
// We have only used Brute Force in this case

class Solution {
private:

bool isStringDivisible(string &prefix ,  string &s) // Checks if we can divide S into substrings equal to Prefix 
{
    int n = s.size() ; 
    int k = prefix.size() ;

    if(n % k != 0) // If we can divide S into no of substrings equal to prefix, then N % K should be equal to 0
        return false ;

    string curr = "" ;
    int cnt = 0 ;

    for(int i = 0 ; i < n ; i++) // This for loop checks if every possible substring of length K is equal to given prefix or not
    {
        curr += s[i] ;
        cnt++ ;

        if(cnt == k)
        {
            if(curr != prefix)
                return false ;

            cnt = 0 ;
            curr = "" ;
        }
    }

    return true ;
}

public:
    string gcdOfStrings(string &s1, string &s2) 
    {
        if(s1 == s2) // If both S1 and S2 are equal, we can return either of them
            return s1 ;

        if(s1.size() > s2.size() ) // We always traverse over the longer of the two strings
            swap(s1 , s2) ;

        int n = s1.size() ;
        int m = s2.size() ;

        string prefix = "" ; // Used to calculate all the prefixes of S1
        int len = 0 ; // Stores its corresponding Length

        string ans = "" ;    


        for(int i = 0 ; i < n ; i++)
        {
            prefix += s1[i] ;
            len++ ;

            bool checkStr1 = isStringDivisible(prefix , s1) ; // We first need to check if Current Prefix divides S1 completely or not

            if(checkStr1 == false) // If not, we directly continue
                continue ;

            if(len > m) // If the length of our prefix string becomes greater than m, it means we have found our substring
                return ans ; // So we directly return ans

            bool checkStr2 = isStringDivisible(prefix , s2) ; // Next we need to check if the Current Prefix divides S2 completely or not

            if(checkStr2 == true) // If true, we update our ans string with the Current Prefix
                ans = prefix ;
        }

        return ans ; 
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
