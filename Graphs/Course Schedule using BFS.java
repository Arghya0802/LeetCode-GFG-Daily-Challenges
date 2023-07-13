// LeetCode link:  https://leetcode.com/problems/course-schedule/description/

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) 
    {
        int n = numCourses ;  int [] inDegree = new int [n] ;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>() ;

        for(int i = 0 ; i < n ; i++)  adj.add(new ArrayList<>() ) ;

        // for(int i = 0 ; i < n ; i++)  inDegree[i] = 0 ;

        for(int [] edge : prerequisites)
        {
            int u = edge[0] ; int v = edge[1] ;

            adj.get(u).add(v) ;  inDegree[v] += 1 ;
        }

        Queue<Integer> q = new LinkedList<>() ;

        for(int i = 0 ; i < n ; i++)  
        {
            if(inDegree[i] == 0) q.add(i) ;
        }

        ArrayList<Integer> topoSort = new ArrayList<>() ;

        while(!q.isEmpty() )
        {
            int node = q.poll() ;  topoSort.add(node) ;

            for(int neigh : adj.get(node))
            {
                inDegree[neigh] -= 1 ;

                if(inDegree[neigh] == 0)  q.add(neigh) ;
            }
        }

        System.out.println(topoSort.size() ) ;

        return topoSort.size() == n ;
    }
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
