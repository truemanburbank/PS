#include <string>
#include <vector>

using namespace std;

// 2 이상인 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수
int solution(int n) 
{
    int answer = 0;

    // n번째 피보나치수를 1234567로 나눈 값을 저장
    vector<int> dp = { 0, 1 };

    for (int i = 2; i <= n; ++i)
    {
        // (a + b) % m = ((a % m) + (b % M)) % m
        dp.push_back((dp[i - 1] + dp[i - 2]) % 1234567);
    }
    
    return dp[n];
}