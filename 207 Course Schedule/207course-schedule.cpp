class Solution {
public:
    bool dfs(int course, unordered_map<int, vector<int>>& preMap, vector<int>& visited){
        if(visited[course] == 1) return false; //cycle detected, in the process of visiting a node
        if(visited[course] == 2) return true; //no cycles detected, procedure for this course was complete  
        visited[course] = 1; //this course is being checked/visited using dfs
        for (int pre : preMap[course]) { //wherever loop or bad condition found, return false
            if (!dfs(pre, preMap, visited))
                return false;
        }
        visited[course] = 2; // mark as visited
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //DFS (Cycle Detection)
        unordered_map <int, vector<int>> preMap;
        //creating the preMap for course -> pre-requisite
        for(int i = 0 ; i < prerequisites.size(); i++){
            int crs  = prerequisites[i][0];
            int pre = prerequisites[i][1];
            preMap[crs].push_back(pre);
        }
        vector<int> visited(numCourses, 0);  // 0 = unvisited, 1 = visiting , 2 = visited
        //size of numCourses, all initialized to 0 as a count; index meaning course number 
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preMap, visited))
                return false; // cycle found
        }
        return true; // no cycles, can finish
    }
};
