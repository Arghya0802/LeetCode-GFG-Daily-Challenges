// Link: https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:

Node *dfs(Node *node , unordered_map<int , Node *> &map)
{
    if(node == NULL)  return NULL ;

    vector<Node *> edges ;

    for(auto neigh : node -> neighbors)
    {
        int val = neigh -> val ;

        if(map.find(val) == map.end() )
        {
            Node *newNeigh = new Node(val) ;

            edges.push_back(newNeigh) ;

            map[val] = newNeigh ;

            dfs(neigh , map) ;
        }

        else
            edges.push_back(map[val]) ;
    }

    Node *newNode ;

    if(map.find(node -> val) == map.end() )
    {
        newNode = new Node(node -> val , edges) ;

        map[node -> val] = newNode ;
    }

    else
    {
        newNode = map[node -> val] ;

        newNode -> neighbors = edges ;
    }

    return newNode ;
}

public:
    Node* cloneGraph(Node* node) 
    {
        unordered_map<int , Node *> map ;

        return dfs(node , map) ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
