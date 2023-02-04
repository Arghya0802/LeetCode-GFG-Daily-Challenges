// Link: https://leetcode.com/problems/permutation-in-string/description/

// This question can also be solved using the Brute Force tehcnique
// But the optimal solution will be to actually use Sliding Window of size equals Length of String S1
// As we are checking for permutations, we can use an array of size 26 to check if any substring of length K contains the same letters as S1

class Solution {
private:

bool areVectorsEqual(vector<int> &actual , vector<int> &currCnt) // Checks if both the freq[] vectors are equal or not
{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(actual[i] != currCnt[i])
            return false ;
    }

    return true ;
}

public:
    bool checkInclusion(string &s1 , string &s2) 
    {
        vector<int> freq(26 , 0) ;

        int k = s1.size() ;
        int n = s2.size() ;

        if(k > n) // If K is greater than N, then there's no chance S2 contains S1
            return false ;
        
        // We first store the frequency[] of S1 inside freq[] array
        for(int i = 0 ; i < k ; i++)
        {
            int index = (int) (s1[i] - 'a') ;

            freq[index] += 1 ;
        }    
        
        vector<int> currCnt(26 , 0) ; // currCnt[] vector stores the frequency of every substring of length K in string S2

        int start = 0 ; 

        while(start < k) // We build the build the window of size K
        {
            int index = (int) (s2[start] - 'a') ;    

            currCnt[index] += 1 ;
            
            start++ ;
        }

        if(areVectorsEqual(freq , currCnt) == true) // If the first substring contains our substring, we return true directly
            return true ;

        int end = 0 ;
        
        // We use Sliding Window of fixed size tehcnique as we include one element and exclude another element
        for(; start < n ; start++)
        {
            char discard = s2[end] ;
            end++ ;
            
            int index = (int) (discard - 'a') ;

            currCnt[index] -= 1 ;

            char newAccept = s2[start] ;

            index = (int) (newAccept - 'a') ;

            currCnt[index] += 1 ;

            if(areVectorsEqual(freq , currCnt) == true)
                return true ;
        }

        return false ;
    }
};

// Time Complexity:  O(N * 26)
// Space Complexity: O(1) 
