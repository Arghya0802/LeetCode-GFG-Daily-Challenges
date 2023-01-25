// Link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

// The question is pretty simple but yet on the first look we find it confusing
// We are asked to find the Closest Node from both Node1 and Node2 
// In case of tie, we need to return the Node with the Lower Index
// Our approach will be pretty straightforward - start any traversal(BFS or DFS) and put all the Nodes that can be reached from Node1 and Node2 inside a vector along with the steps required
// In this way, we can get the Node Closest to both Node1 and Node2 by traversing over their neighbors and keeping track of the MinSteps we have encountered till now

class Solution {
private:

// Simple DFS() function to traverse all the Nodes which are reachable from given Node
// We use a Visited[] array such that we don't get into any Cycle
// Similarly, we keep track of a StepsCount which will let us know how much distance we need to travel in order to reach any given Node from the StartNode
void dfs(int node , int steps , vector<int> &visited , vector<int> &edges , vector<int> &adj)
{
    visited[node] = 1 ;

    adj[node] = steps ;

    int nextNode = edges[node] ;

    if(nextNode != -1 && !visited[nextNode])
        dfs(nextNode , steps + 1 , visited , edges , adj) ;

    return ;
}

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size() ;

        vector<int> adj1(n , -1) ; // Stores all the Nodes reachable from Node1
        vector<int> adj2(n , -1) ; // Stores all the Nodes reachable from Node2

        vector<int> visit1(n , 0) ;
        vector<int> visit2(n , 0) ;
        
        // We call dfs() function to get all the reachable Nodes from Node1 and Node2 respectively
      
        dfs(node1 , 0 , visit1 , edges , adj1) ;
        dfs(node2 , 0 , visit2 , edges , adj2) ;

        int closestNode = -1 ; // Stores our Final ClosestNode reachable from both Node1 and Node2
        int minSteps = INT_MAX ; // Keeps track of the minSteps required till now

        for(int node = 0 ; node < n ; node++) // We traverse over all the Nodes of the graph 
        {
            if(adj1[node] == -1 || adj2[node] == -1) // If either of adj1[node] or adj2[node] equals -1 signifies this Node is not reachable from Node1 or Node2 or both
                continue ; // Thus we simply continue

            int currMaxSteps = max(adj1[node] , adj2[node]) ; // As stated in the question, we take the Maximum of the Steps required from Node1 and Node2

            if(minSteps > currMaxSteps) // If our minSteps is greater than CurrMaxSteps, it means we need to Update our ClosestNode
            {
                closestNode = node ;

                minSteps = currMaxSteps ;
            }
        }
        
        return closestNode ; // At the end, we retun the Closest Node reachable from Node1 and Node2 both with the Minimum Possible Steps
    }   
};

// Time Complexity:  O(N) [In worst case, we will traverse all the nodes from either Node1 or Node2]
// Space Complexity: O(N)
