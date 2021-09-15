#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void DFS(int v, vector<bool>& visited, vector<bool>& finished, unordered_map<int, vector<int>>& vertices, bool& hasCycle)
{
    visited[v] = 1;
    for (int i = 0; i < vertices[v].size(); i++)
    {
        if (!finished[vertices[v][i]])
        {
            if (visited[vertices[v][i]])
            {
                hasCycle = 1;
                return;
            }
            else
            {
                DFS(vertices[v][i], visited, finished, vertices, hasCycle);
            }
        }
    }
    finished[v] = 1;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> vertices;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        if (vertices.count(prerequisites[i][1]))
        {
            vertices[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        else
        {
            vertices[prerequisites[i][1]] = { prerequisites[i][0] };
        }
    }
    bool hasCycle = 0;
    vector<bool> visited(numCourses, 0);
    vector<bool> finished(numCourses, 0);
    for (int j = 0; j < numCourses; j++)
    {
        if (vertices.count(j) && !finished[j])
        {
            DFS(j, visited, finished, vertices, hasCycle);
        }
        if (hasCycle == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}