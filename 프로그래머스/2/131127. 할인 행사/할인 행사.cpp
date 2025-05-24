#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 사야 하는 물건을 다 충족시켰는지 확인
// want, numer 데이터가 현재 hash 정보와 맞는지 확인
bool isPossible(unordered_map<string, int> items, vector<string> want, vector<int> number)
{
    for (int i = 0; i < want.size(); i++)
    {
        if (items.find(want[i]) == items.end() || items[want[i]] != number[i])
            return false;
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    // i일째를 시작으로 앞으로의 10일치 일일이 확인
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        unordered_map<string, int> items;

        // 현재 날짜부터 10일치 판매 물건 정보를 hash에 등록
        for (int j = 0; j < 10; j++)
        {
            string itemName = discount[i + j];
            items[itemName]++;
        }

        // 물건을 다 살 수 있는지 확인
        if (isPossible(items, want, number))
            answer++;
    }

    return answer;
}