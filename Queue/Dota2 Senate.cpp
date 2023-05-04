// Link: https://leetcode.com/problems/dota2-senate/description/

class Solution {
public:
    string predictPartyVictory(string &senate) 
    {
        int n = senate.size() ;

        queue<int> rQueue , dQueue ;

        for(int i = 0 ; i < n ; i++)
        {
            char ch = senate[i] ;

            if(ch == 'R')  rQueue.push(i) ;

            else  dQueue.push(i) ;
        }

        while(!rQueue.empty() && !dQueue.empty() )
        {
            int indR = rQueue.front() ; rQueue.pop() ;
            int indD = dQueue.front() ; dQueue.pop() ;

            if(indR < indD)  rQueue.push(indR + n) ;

            else dQueue.push(indD + n) ;
        }

        return !rQueue.empty() ? "Radiant" : "Dire" ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
