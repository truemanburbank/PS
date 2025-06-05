#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int size) : parent(size, -1), rank(size, 0) {}

    // 루트 노드 찾기
    int find(int x)
    {
        if (parent[x] == -1)
            return x;

        // 경로 압축
        parent[x] = find(parent[x]);

        return parent[x];
    }

    void makeUnion(int x, int y)
    {
        int root1 = find(x);
        int root2 = find(y);

        // 랭크 기반으로 합침 (균형을 위해)
        if (root1 != root2)
        {
            if (rank[root1] < rank[root2])
                parent[root1] = root2;
            else if (rank[root2] < rank[root1])
                parent[root2] = root1;
            else
            {
                parent[root1] = root2;
                rank[root2]++;
            }
        }
    }

    bool isCycle(int x, int y)
    {
        return find(x) == find(y);
    }
};

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;

    DisjointSet dsj(n);

    // 건설 비용이 낮은 순으로 정렬
    // 건설 비용이 낮은 순으로 다리를 만들고, 불필요한 다리(사이클)를 건설하려 하면 pass
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b) { return a[2] < b[2]; });

    for (const auto& edge : costs)
    {
        int cost = edge[2];
        int node1 = edge[0];
        int node2 = edge[1];

        // 사이클이 없다면 다리를 만든다.
        if (!dsj.isCycle(node1, node2))
        {
            dsj.makeUnion(node1, node2);
            answer += cost;
        }
    }

    return answer;
}