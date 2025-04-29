#include <iostream>
#include <algorithm> // sort
#include <vector> // stl 정렬 쓰려고 원시 배열 대신 vector
#include <queue> // 우선 순위 큐

using namespace std;

int N, K;
vector<pair<int, int>> gem; // 무게, 가격
vector<int> bag;

long long ans;

int main()
{
    // 보석 개수, 가방 개수
    cin >> N >> K;

    // 보석 info
    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v;
        gem.push_back({ m, v });
    }

    // 가방 info
    for (int i = 0; i < K; i++)
    {
        int c;
        cin >> c;
        bag.push_back(c);
    }

    // 보석 무게 오름차순 정렬
    sort(gem.begin(), gem.end());

    // 가방 무게 오름차순 정렬
    sort(bag.begin(), bag.end());

    priority_queue<int> pq; // 가격 기준 max heap
    int gem_i = 0; // 보석 인덱스

    // 가방을 기준으로 어떤 보석을 담을지
    for (int bag_i = 0; bag_i < K; bag_i++)
    {
        int bagWeight = bag[bag_i];

        // 현재 가방에 담을 수 있는 보석들을 모두 pq에 넣음
        // 자동 정렬 됨
        while (gem_i < N && gem[gem_i].first <= bagWeight) 
        {
            pq.push(gem[gem_i].second); // 가격만 넣음
            gem_i++;
        }

        // 가장 비싼 보석을 선택
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    std::cout << ans;

    return 0;
}