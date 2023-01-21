// Link: https://leetcode.com/problems/restore-ip-addresses/description/

// This is a classic question of Recursion and BackTracking
// The only catch in the question is that we can only have at max 3 values because our values lie between [0 , 255]
// This is the only catch- other than that we have a classic backtracking question
// Another small optimization is that we use vector<string> CurrIP instead of our normal string CurrIP -- this makes our backtracking very easy

class Solution {
private:

bool validIPAddress(string &str) // ValidIPAddress() returns true if our IP address has a valid number and doesn't have leading zeros
{
    int len = str.size() ;

    if(len == 1) // For IP Address of Length 1, it will always be true
        return true ;

    if(len > 1 && str[0] == '0') // Checking for Leading Zeros
        return false ;

    if(stoi(str) > 255) // Checking if our IP Address value is within [0...255] or not
        return false ;

    return true ;
    // return cnt == len ? true : false ;
}

// This is the Recursive function which returns all the Valid Possible IP Addresses present in string S
void generateIPAddressess(int currIndex , int dots , int n , string &s , vector<string> &currIP , vector<string> &ans)
{
    if(currIndex >= n) // If we have traversed the entire string, then only we will include the Current-IP address into our ans[] vector if it has 4 dots
    {
        if(dots == 4) // If we have 4 dots, we have a Valid IP Address
        {
            string address = "" ; // We make the IP address by traversing over CurrIP[] vector

            for(string IP : currIP)
            {
                address += IP ;

                address += '.' ; // We need to insert dots as well
            }

            address.pop_back() ; // Last Dot is invalid so we pop it out of our final IP Address

            ans.push_back(address) ; // We push the Final IP Address into our ans[] vector
        }

        return ; // We return back from base case
    }

    if(dots > 4) // If we need more than 4-dots, we will never get a Valid IP address
        return ;
    
    // Instead of using substr() function, we can use NewIP string to actually calculate the subStrings from i = currIndex till i < currIndex + 3
    string newIP = "" ;

    for(int i = currIndex ; i < currIndex + 3 ; i++)
    {
        if(i == n) // If we have traversed till the end, we need to immediately break out 
            break ;
        
        newIP += s[i] ; // Otherwise we include s[i] into newIP string

        if(validIPAddress(newIP) == true) // If newIP is a Valid IP Address
        {
            currIP.push_back(newIP) ; // We push it into our vector of string currIP 

            generateIPAddressess(i + 1 , dots + 1 , n , s , currIP , ans) ; // We ask recursion to do rest of the task from (i + 1) th index

            currIP.pop_back() ; // At the end, we need to backtrack and undo the change to explore all possibilites
        }

    }

    return ;
}

public:
    vector<string> restoreIpAddresses(string &s) 
    {
        vector<string> currIP ;

        vector<string> ans ;

        generateIPAddressess(0 , 0 , s.size() , s , currIP , ans) ;

        return ans ;
    }
};

// Time Complexity:  O(Eponenital) [We cannot exactly now how may combinations are possible, though we have only 3 choices]
// Space Complexity: O(N) [ We have N valid IP address and CurrIP vector]
