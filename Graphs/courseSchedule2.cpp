class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         using topological sorting 
//         but first check cycle as well
        vector<int> *adjList = new vector<int>[numCourses];
        
        for(vector<int> edge: prerequisites) {
            int req = edge[1];
            int canTake = edge[0];
            adjList[req].push_back(canTake);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> ancestor(numCourses, false);
        vector<int> order;
        for(int i=0; i<numCourses; ++i) {
            if(topSort(adjList, visited, ancestor, i, order)) {
                return {};
            }
        }
        
        reverse(order.begin(), order.end());
        return order;
    }
    
    bool topSort(vector<int> *&adjList, vector<bool> &visited, vector<bool> &ancestor, int src, vector<int> &order) {
        if(!visited[src]) {
            visited[src] = true;
            ancestor[src] = true;
            for(int connectedNode: adjList[src]) {
                if(ancestor[connectedNode]) {
                    return true;
                }
                if(topSort(adjList, visited, ancestor, connectedNode, order)) {
                    return true;
                }
            }
            order.push_back(src);
        }
        ancestor[src] = false;
        return false;
    }
    
};
