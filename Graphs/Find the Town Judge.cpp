// Link: https://leetcode.com/problems/find-the-town-judge/description/

// This is a classic graph question
// We must remember the conditions of being a Town Judge:
// a) Every other person in the village must trust him [InDegree == N-1 ]
// b) He himself shouldn't trust anyone [OutDegree == 0 ]
// If we use the above 2 conditions we can findout who is the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        // We declare two vectors InDegree[] and OutDegree[] to calculate the incoming and outgoing edges respectively
        vector<int> inDegree(n + 1 , 0) ;
        vector<int> outDegree(n + 1 , 0) ;

        for(vector<int> &edge : trust)
        {
            // As given in the question: there's a directed edge from a --> b
          
            int a = edge[0] ;
            int b = edge[1] ;

            inDegree[b] += 1 ; // InDegree of b should be incremented by 1 as it receives one edge

            outDegree[a] += 1 ; // OutDegree of a should be incremented by 1 as it provides one edge
        }    
        
        // We traverse from i = 1 till N covering all the Town Peoples
      
        for(int node = 1 ; node <= n ; node++)
        {
            int outgoing = outDegree[node] ;

            int incoming = inDegree[node] ;

            if(incoming == n - 1 && outgoing == 0) // As said in the problem, OutDegree should be 0 and InDegree should be N - 1 if that Node is to be the Town Judge
                return node ;
        }

        return -1 ; // Otherwise, we don't have a Town Judge so we return -1
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
