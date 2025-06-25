#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// n은 100 이하 wires는 최대 99
// 하나의 트리를 2개로 분할
// 이때 최대한 송전탑의 개수를 비슷하게 
// n이 작으므로 일일이 확인하면 됨

int dfs(const vector<vector<int>>& graph, vector<bool>& visited, int start)
{
    visited[start] = true;
    int count = 1;

    for (int end : graph[start])
    {
        if (!visited[end])
            count += dfs(graph, visited, end);
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) 
{
    vector<vector<int>> graph(n);
    int answer = 987654321;

    // 그래프 생성
    for (int i = 0; i < wires.size(); i++)
    {
        int start = wires[i][0] - 1;
        int end = wires[i][1] - 1;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    // 선을 하나씩 잘라본다.
    for (int i = 0; i < wires.size(); i++)
    {
        vector<bool> visited(n, false);
        int start = wires[i][0] - 1;
        int end = wires[i][1] - 1;

        // 간선 끊기
        graph[start].erase(remove(graph[start].begin(), graph[start].end(), end), graph[start].end());
        graph[end].erase(remove(graph[end].begin(), graph[end].end(), start), graph[end].end());

        int ret1 = dfs(graph, visited, start);

        fill(visited.begin(), visited.end(), false);

        int ret2 = dfs(graph, visited, end);

        answer = min(abs(ret1 - ret2), answer);

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    return answer;
}