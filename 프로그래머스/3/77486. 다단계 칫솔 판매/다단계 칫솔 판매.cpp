#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 모든 판매원은 칫솔 판매 발생 이익에서 10퍼센트를 자신의 부모에게 줘야 한다.
// 자신에게 들어온 10퍼센트 이익은 그것도 자신의 부모에게 10퍼센트를 줘야 한다.
// 즉 자신에게 들어온 모든 이익은 자신의 부모에게 10퍼센트를 줘야 한다.

unordered_map<string, pair<int, string>> parent; // 자식 - <인덱스, 부모> (계층 관계)

void MLM(vector<int>& answer, string seller, int profit, int toSend, int netProfit)
{
    int idx = parent[seller].first;
    string parentName = parent[seller].second;

    // 추천자가 없다면 센터에 10퍼센트 주기
    if (seller == "-")
    {
        return;
    }

    // 이익이 10원 미만일 때
    if (profit < 10)
    {
        answer[idx] += profit;
        // cout << seller << " : " << profit << endl;
        return;
    }

    answer[idx] += netProfit;
    // cout << seller << " : " << netProfit << endl;
    MLM(answer, parentName, toSend, (int)(toSend * 0.1), toSend - (int)(toSend * 0.1));
}

// 자신의 추천인(부모)만 누군지 알면 됨
// 1. seller, amount의 크기만큼 돌며 칫솔 판매.
// 2. 판매금 계산 후 그 10퍼센트를 그 사람의 부모 -> 부모 -> 부모 -> 이어지게끔하기 while로 하면 될 듯.
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer(enroll.size());

    for (int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]].first = i;
        parent[enroll[i]].second = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        int profit = amount[i] * 100;
        MLM(answer, seller[i], profit, (int)(profit * 0.1), profit - (int)(profit * 0.1));
    }

    return answer;
}