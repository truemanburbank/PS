#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

// dfs
void dfs(const vector<vector<int>>& network, int node)
{
    visited[node] = true;

    for (int i = 0; i < network[node].size(); i++)
        if (network[node][i] == 1 && !visited[i])
            dfs(network, i);
}

int solution(int n, vector<vector<int>> computers) 
{
    visited = vector<bool>(computers.size(), false);

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(computers, i);
            answer++;
        }
    }

    return answer;
}