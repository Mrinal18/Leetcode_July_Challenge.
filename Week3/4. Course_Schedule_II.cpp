/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

/*
Approch:
1. we have the mapping here in a little different manner.
2. make an adj list first.
3. then we will do topological sorting and also check for cycle if any. 
4. For topological sorting we will be using DFS here, for that we will be using stack DS, 
5. when we visit a node, we will check its corresponding path till we have no other paths to viist and then push it into the stack.


*/

class Solution {
public:
    
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& s, vector<int>& visited){
        
        visited[u] = 1;
        
        for(int v : adj[u]){
            if(visited[v] == 1) return 1;
            if(visited[v] == 0 && dfs(v, adj, s, visited)) return true;
        }
        
        visited[u] = 2;
        s.push_back(u);
        
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //fist make the adj list:
        vector<vector<int>> adj(numCourses);
        
        for(vector<int>& courses: prerequisites){
            
            //this means if we are given [0,1] then it will be modeled as 1->0
            adj[courses[1]].push_back(courses[0]);
        }
        
        vector<int> s;
        vector<int> visited(numCourses, 0);
        
        for(int i = 0; i < numCourses; ++i)
            if(visited[i] == 0 && dfs(i, adj, s, visited)) return {};
        
        reverse(s.begin(), s.end());
            
        
        return s;
    }
};
