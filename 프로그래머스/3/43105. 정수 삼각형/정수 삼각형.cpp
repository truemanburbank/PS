#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    // 각 숫자로 향하는 경로 중 최댓값만을 저장
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int maxSum = 0;
            if (j == 0)
            {
                auto start = dp[i - 1].begin();
                auto end = dp[i - 1].begin() + 1;
                maxSum = *max_element(start, end);
            }
            else if (j == triangle[i].size() - 1)
            {
                auto start = dp[i - 1].begin() + j - 1;
                auto end = dp[i - 1].end();
                maxSum = *max_element(start, end);
            }
            else
            {
                auto start = dp[i - 1].begin() + j - 1;
                auto end = dp[i - 1].begin() + j + 1;
                maxSum = *max_element(start, end);
            }
            dp[i].push_back(maxSum + triangle[i][j]);
        }
    }

    int lastLine = triangle.size() - 1;
    int ans = *max_element(dp[lastLine].begin(), dp[lastLine].end());
    return ans;
}