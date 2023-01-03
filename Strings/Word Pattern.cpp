// Link: https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    
    // This question requires us to map every character in Pattern with S and vice versa
    // Whenever we find any invalid case, we directly return false
    // Also take care, if we are traversing every character in Pattern as well as every word in S as well
  
    bool wordPattern(string &pattern, string &s) 
    {
        int n = pattern.size() ;

        unordered_map<char , string> mapChar ;
        unordered_map<string , char> mapString ;

        int index = 0 ; // Index will help us to iterate over Pattern
        string wd = "" ;

        s += ' ' ; // To extract the Last Word from S string
        
        for(char ch : s)
        {
            if(ch != ' ')
                wd += ch ;

            else
            {
                char currChar = pattern[index] ; // We take the Character from Pattern String
                
                // At any moment, if we get any invalid mapping we return false
              
                if(mapChar.find(currChar) != mapChar.end() )
                {
                    if(mapChar[currChar] != wd)
                        return false ;
                }

                if(mapString.find(wd) != mapString.end() )
                {
                    if(mapString[wd] != currChar)
                        return false ;
                }

                mapChar[currChar] = wd ;
                mapString[wd] = currChar ;

                if(index < n) // We must not put index out of Pattern string
                    index += 1 ;

                wd = "" ;
            }
        }

        return index == n ? true : false ; // At the end, we need to check if all the characters of Pattern String has been traversed as well
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
