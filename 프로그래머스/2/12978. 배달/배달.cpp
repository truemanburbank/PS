#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

struct Compare
{
    // a : 도착점
    // b : 가중치
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

// 다익스트라로 최소 거리 찾아서 K 이상이면 팽 
// 입력: (시작점, 도착점, 가중치)
int solution(int N, vector<vector<int>> road, int K)
{
    vector<vector<pair<int, int>>> graph(N + 1);

    for (auto& info : road)
    {
        int start = info[0];
        int end = info[1];
        int weight = info[2];

        // 양방향 그래프
        graph[start].emplace_back(end, weight);
        graph[end].emplace_back(start, weight);
    }

    // 다익스트라
    int INF = numeric_limits<int>::max();
    vector<int> distances(N + 1, INF);
    vector<bool> visited(N + 1, false);
    distances[1] = 0;

    // 도착점, 가중치
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({ 1, 0 }); // 시작 노드 : 1
    
    // 도착점까지의 최소 거리 찾기
    while (!pq.empty())
    {
        int curEnd = pq.top().first;
        int curDistance = pq.top().second;
        pq.pop();

        if (visited[curEnd] == true) continue;

        visited[curEnd] = true;

        // 인접 노드에 대한 거리 업데이트
        for (const auto& [neighbor, weight] : graph[curEnd])
        {
            int newDistance = distances[curEnd] + weight;
            if (newDistance < distances[neighbor])
            {
                distances[neighbor] = newDistance;
                pq.push({ neighbor, newDistance });
            }
        }
    }

    // 시작점 0으로부터 가중치가 K이하인 도착점 개수 세기
    int answer = 0;
    for (int distance : distances)
        if (distance <= K) answer++;

    return answer;
}