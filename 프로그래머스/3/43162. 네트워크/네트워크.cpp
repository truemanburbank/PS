#include <string>
#include <vector>

using namespace std;

// union - find
class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int size) : parent(size, -1), rank(size, 0) {}

    int Find(int node)
    {
        if (parent[node] == -1)
            return node;

        // 경로 압축
        return parent[node] = Find(parent[node]);
    }

    void MakeUnion(int node1, int node2)
    {
        int root1 = Find(node1);
        int root2 = Find(node2);

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

    bool IsCycle(int node1, int node2) { return Find(node1) == Find(node2); }

    int GetRootCount()
    {
        int rootCount = 0;
        for (int i = 0; i < parent.size(); i++)
            if (parent[i] == -1)
                rootCount++;

        return rootCount;
    }
};

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;

    DisjointSet disjointSet(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (computers[i][j] == 1 && j != i)
                disjointSet.MakeUnion(i, j);

    answer = disjointSet.GetRootCount();

    return answer;
}