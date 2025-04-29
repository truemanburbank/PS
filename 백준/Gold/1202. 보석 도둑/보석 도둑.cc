#include <iostream>
#include <algorithm> // sort
#include <vector> // stl 정렬 쓰려고
#include <set> // multiset

using namespace std;

int N, K;
vector<pair<int, int>> gem; // 무게, 가격
multiset<int> bag;
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
        bag.insert(c); // 자동 정렬됨
    }

    // 보석 가격 내림차순 정렬
    sort(gem.begin(), gem.end(), [](auto& a, auto& b)
    {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    // 가장 비싼 보석을 넣을 수 있는 최대한 딱 맞는 가방 찾기
    for (int i = 0; i < N; i++)
    {
        int m = gem[i].first;
        int v = gem[i].second;

        // 이 보석을 담을 수 있는 가장 작은 가방 찾기
        auto it = bag.lower_bound(m);
        if (it != bag.end())
        {
            ans += v;
            bag.erase(it); // 사용한 가방 제거
        }
    }

    cout << ans;

    return 0;
}