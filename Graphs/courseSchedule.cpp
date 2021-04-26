class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         check for cycle if any cycle is detected then it is not possible
//         create adjacency List 
        vector<int> *adjList = new vector<int>[numCourses];
        
        for(vector<int> edge: prerequisites) {
            int req = edge[1];
            int canTake = edge[0];
            adjList[req].push_back(canTake);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> ancestor(numCourses, false);
        
        for(int i=0; i<numCourses; ++i) {
            if(checkCyclic(adjList, visited, ancestor, i)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkCyclic(vector<int> *&adjList, vector<bool> &visited, vector<bool> &ancestor, int src) {
        if(!visited[src]) {
            visited[src] = true;
            ancestor[src] = true;
            
            for(int connectedNode: adjList[src]) {
                if(ancestor[connectedNode]) {
                    return true;
                }
                if(checkCyclic(adjList, visited, ancestor, connectedNode)) {
                    return true;
                }
            }
        }
        ancestor[src] = false;
        return false;
    }
};
