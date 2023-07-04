// Link:  https://leetcode.com/problems/buddy-strings/description/

class Solution {
private:

bool containSameLetters(string &s , string &goal)
{
    int freqA[26] = {0} ; int freqB[26] = {0}  ;
    
    for(char ch : s)  freqA[ch - 'a'] += 1 ; 

    for(char ch : goal)  freqB[ch - 'a'] += 1 ;

    bool isOkay = false ;

    for(int i = 0 ; i < 26 ; i++)
    {
        if(freqA[i] != freqB[i] )  return false ;

        if(freqA[i] > 1)  isOkay = true ;
    }
    
    return isOkay ;
}

public:
    bool buddyStrings(string &s, string &goal) 
    {
        int n = s.size() ;    

        if(n != goal.size() )  return false ;

        if(s == goal && containSameLetters(s , goal) )  return true ;

        int indA = -1 ; int indB = -1 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] != goal[i] )  
            {
                if(indA == -1)  indA = i ;

                else if(indB == -1)  indB = i ;

                else return false ;
            }
        }

        if(indA == -1 || indB == -1)  return false ;

        swap(s[indA] , s[indB] ) ;

        return s == goal ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
