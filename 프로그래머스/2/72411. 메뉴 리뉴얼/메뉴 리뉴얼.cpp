#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 코스 요리는 최소 2가지 이상의 단품 메뉴로 구성
// 최소 2명 이상의 손님으로부터 주문되어야 함

// orders : 손님들이 주문한 단품메뉴들 
// course : 코스요리 단품 개수

unordered_map<string, int> orderTable;

// 문자열 조합 생성 후 hash 등록
void generateCombinations(const string& str)
{
    string sortedStr = str;

    // 문자열 조합을 만들기 위한 정렬
    sort(sortedStr.begin(), sortedStr.end());

    int n = sortedStr.length();

    // 0부터 2^n - 1까지 순회하며 비트 마스크로 조합 생성
    // 몇 번째 비트가 켜졌는지에 따라 문자 껐다 켜기 -> 조합 생성 가능

    // i = 0은 아무 문자도 선택 안 한 공집합을 뜻하므로 제외하고 시작
    for (int i = 1; i < (1 << n); i++)
    {
        string comb = "";
        for (int k = 0; k < n; k++)
        {
            // k 번째 비트가 켜져 있으면 k번째 문자를 선택
            // i라는 숫자의 k 번째 비트가 1인지 0인지 확인하는 방법.
            if ((i >> k) & 1)
                comb += sortedStr[k];
        }
        if(comb.length() >= 2)
            orderTable[comb]++;
    }
}

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    if (a.first.length() == b.first.length())
        return a.second > b.second;
    return a.first.length() < b.first.length();
}

// 수가 작으므로 모든 조합을 생각해 본다?
vector<string> solution(vector<string> orders, vector<int> course) 
{
    for (int i = 0; i < orders.size(); i++)
    {
        generateCombinations(orders[i]);   
    }

    vector<pair<string, int>> sortedList(orderTable.begin(), orderTable.end());
    sort(sortedList.begin(), sortedList.end(), cmp);

    vector<string> answer;

    for (int i = 0; i < course.size(); i++)
    {
        int max = 2;
        for (int j = 0; j < sortedList.size(); j++)
        {
            if (course[i] == sortedList[j].first.length() && sortedList[j].second >= max)
            {
                max = sortedList[j].second;
                answer.push_back(sortedList[j].first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}