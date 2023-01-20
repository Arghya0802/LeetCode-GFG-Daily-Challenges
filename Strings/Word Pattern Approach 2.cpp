// Link: https://leetcode.com/problems/word-pattern/description/

// We need to keep track of the Mapping from Character present in Pattern to Word present in S
// Also the number of words of present in S should be equal to the number of characters present in Pattern

class Solution {
public:
    bool wordPattern(string &pattern, string &s) 
    {
        unordered_map<char , string> charMap ; // Maps Character with String
        unordered_map<string , char> wordMap ; // Maps String with Character

        int index = 0 ; // Used to iterate over Pattern string
        
        int cnt = 0 ; // Used to count the number of words present in S

        int n = pattern.size() ;
        
        string wd = "" ;
        
        s += ' ' ; // To access Last Word of S we have to include a WhiteSpace at the end

        for(char ch : s)
        {
            if(ch != ' ')
                wd += ch ;

            else
            {
                // if(index == n)
                //     index = n - 1 ;
                
                char currChar = pattern[index] ; // Points to the Current-Character of Pattern
                
                // If any mapping of charMap[currChar] or wordMap[wd] is wrong, we directly return  false
              
                if(charMap.find(currChar) != charMap.end() )
                {
                    if(charMap[currChar] != wd)
                        return false ;
                }

                if(wordMap.find(wd) != wordMap.end() )
                {
                    if(wordMap[wd] != currChar)
                        return false ;
                }
                
                // Otherwise we map them again
              
                charMap[currChar] = wd ;

                wordMap[wd] = currChar ;
                   
                if(index < n)
                    index++ ;

                cnt++ ;
                wd = "" ;
            }    

        }

        // return (index == n) && (cnt == n)? true : false ;

        return cnt == n ? true : false ; // We return true if the number of words present in S is equal to the number of Characters present in Pattern and they have a 1:1 mapping which is ensured above
      
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
