// Link:  https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

class Solution {
private:

int Count_Nice_Subarrays(string &s , int k , char choice)
{
    int n = s.size() ; int maxCnt = 0 ;

    int end = 0 ; int cnt = 0 ;

    for(int start = 0 ; start < n ; start++)
    {
        char accept = s[start] ;

        if(accept != choice)  cnt++ ;

        while( end <= start && cnt > k )
        {
            char discard = s[end] ;  end++ ;

            if(discard != choice)  cnt-- ;
        }

        maxCnt = max(maxCnt , start - end + 1) ;
    }

    return maxCnt ;
}

public:
    int maxConsecutiveAnswers(string &answerKey, int k) 
    {
        int choiceT = Count_Nice_Subarrays(answerKey , k , 'T') ; // For Max True Answers
        int choiceF = Count_Nice_Subarrays(answerKey , k , 'F')  ; // For Max False Answers

        return max(choiceT , choiceF) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
