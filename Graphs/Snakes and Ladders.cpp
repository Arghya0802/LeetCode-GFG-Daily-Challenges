// Link: https://leetcode.com/problems/snakes-and-ladders/description/

// The question seems very difficult on the first look but is actually simple
// We need to use BFS to get the minSteps possible to travel from 1 till N^2 [if possible]; Otherwise return -1 
// The main catch lies in the question is to actually transform the grid into a linear array and track all the Snakes and Ladders
// For N = Even and N = Odd, we have to deal seperately
// Also the matrix is labelled from bottom to top which again makes it tricky to handle

class Solution {
private:

// Returns One Single Linear Array having all the cells [1 to N ^ 2] along with all the destination cells for all the Snakes and Ladders
vector<int> snakesAndLadders(int total , int n , vector<vector<int>> &board)
{
    vector<int> ans(total + 1 , -1) ;

    int check = 0 ;
    
    if(n % 2 == 1) // If N is odd, we traverse the first row in reverse manner
        check = 1 ;
    
    vector<pair<int , int>> trackPos ; // Makes a pair of all the Snakes and Ladders along with their (StartCell , endCell)

    for(int row = 0 ; row < n ; row++)
    {
        if(check == 0)
        {
            for(int col = 0 ; col < n ; col++)
            {
                int dest = board[row][col] ;

                if(dest != -1) // If we have a value != -1, we have encountered a Snake or Ladder
                    trackPos.push_back({total , dest}) ;

                total-- ;
            }

            check = 1 ;
        }

        else
        {
            for(int col = n - 1 ; col >= 0 ; col--)
            {
                int dest = board[row][col] ;

                if(dest != -1)
                    trackPos.push_back({total , dest}) ;

                total-- ;   
            }

            check = 0 ;
        }
    }

    for(pair<int , int> &curr : trackPos)
    {
        int src = curr.first ;
        int dest = curr.second ;

        ans[src] = dest ; // We mark all the Source Cells with their Desination values which makes our BFS easier
    }

    return ans ;
}

public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size() ;

        int target = n * n ;

        vector<int> nums = snakesAndLadders(target , n , board) ;    

        vector<int> visited(target + 1 , 0) ; // We declare our Visited array with size = N * N

        queue<int> q ;
        q.push(1) ; // We start from Cell 1

        visited[1] = 1 ; // We mark it as visited

        int cnt = 0 ; // Keep tracks of the Levels we have encountered till now

        while(!q.empty() )
        {
            int size = q.size() ; // We traverse Level-Wise

            while(size--)
            {
                int node = q.front() ;
                q.pop() ;

                if(node == target) // If we have reached our Destination Cell, we return cnt
                    return cnt ;

                for(int dice = node + 1 ; dice <= (node + 6) ; dice++) // We have 6 possible moves to traverse
                {
                    if(dice > target) // If our CurrNode become greater than target, we immediately break
                        break ;

                    int ind = dice ; // Our destination will initally be equal to dice

                    if(nums[dice] != -1) // If nums[dice] != -1, we have encountered a Snake or Ladder
                        ind = nums[dice] ;

                    if(visited[ind] == 0) // If we haven't yet visited that Cell, 
                    {
                        q.push(ind) ; // We push it into our queue

                        visited[ind] = 1 ; // We mark it as visited
                    }
                }
            }

            cnt++ ; // We increment cnt by 1 as we move to next level
        }

        return -1 ; // If we get out of the queue, we return -1 signifying we can't reach our Target Cell

    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
