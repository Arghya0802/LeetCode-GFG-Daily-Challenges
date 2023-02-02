// Link: https://leetcode.com/problems/verifying-an-alien-dictionary/description/

// The main idea of the problem is that we need to check if the given words in words[] vector are stored in sorted order or not
// But the catch is we are given an Order string based on which we need to say if the strings are sorted or not
// To reduce our Time Complexity, we can store the order in a newOrder[] vector of size 26 as all the characters are in LowerCase only
// After that we just need to check if any alphabet in first string is smaller than it's corrsponding counterpart in second string or not

class Solution {
private:

bool isSorted(string &s1 , string &s2 , vector<int> &newOrder) // Checks if the given strings are sorted or not
{
    int m = s1.size() ;
    int n = s2.size() ;

    int i = 0 ;
    int j = 0 ;

    while(i < m && j < n)
    {
        int index = (int) (s1[i] - 'a') ;
        
        int firstOrder = newOrder[index] ;

        index = (int) (s2[j] - 'a') ;

        int secondOrder = newOrder[index] ;

        if(firstOrder == secondOrder) // If they have the same alphabets, so their order must be same --> So we move to the next set of characters
        {
            i++ ;
            j++ ;
        }

        else if(firstOrder < secondOrder) // If firstCharacter is smaller than secondCharacter according to our newOrder[], we directly return true
            return true ;

        else // If firstCharacter is greater than secondCharacter as per newOrder[], we also directly return false
            return false ;
    }

    return i == m ? true : false ; // Before returning true, we need to ensure that S1[first string] should be completely traversed, otherwise we return false
}

public:
    bool isAlienSorted(vector<string>& words, string &order) 
    {
        int n = words.size() ;

        vector<int> newOrder(26 , -1) ; // We store the newOrder of the alphabets as per order String and stores it in a newOrder[] vector

        for(int i = 0 ; i < 26 ; i++) // As we are checking for 2-words always, our loop runs from i = 0 till N - 1
        {
            int index = (int) (order[i] - 'a') ;

            newOrder[index] = i + 1 ;
        }

        for(int i = 0 ; i < n - 1 ; i++)
        {
            bool checkStrings = isSorted(words[i] , words[i + 1] , newOrder) ;

            if(!checkStrings) // If checkStrings is false, it means words[i] and words[i + 1] are not sorted in ascending order
                return false ; // So we directly return false
        }

        return true ; // At the end of the for loop, we return true 
    }
};

// Time Complexity:  O(N * K) [N is the number of words present in words[] and K is the average length of each string]
// Space Complexity: O(1)
