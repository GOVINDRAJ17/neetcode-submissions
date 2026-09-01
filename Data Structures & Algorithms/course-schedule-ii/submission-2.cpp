class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // graph[a] contains courses that become available
        // after completing course a
        vector<vector<int>> graph(numCourses);

        // indegree[i] = number of prerequisites of course i
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto edge : prerequisites) {

            int course = edge[0];
            int prerequisite = edge[1];

            graph[prerequisite].push_back(course);

            indegree[course]++;
        }

        // Courses with 0 prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        // Topological sort
        while (!q.empty()) {

            int course = q.front();
            q.pop();

            result.push_back(course);

            // Remove this course as a prerequisite
            // from all courses depending on it
            for (int next : graph[course]) {

                indegree[next]--;

                // No prerequisites left
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we couldn't take every course,
        // there must be a cycle
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};