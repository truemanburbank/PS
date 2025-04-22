#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.resize(arr1.size(), vector<int>(arr2[0].size()));

    for (int i = 0; i < arr1.size(); i++)            // 결과 행렬의 행
        for (int j = 0; j < arr2[0].size(); j++)     // 결과 행렬의 열
            for (int k = 0; k < arr1[0].size(); k++)    // 곱셈합 요소들
                answer[i][j] += arr1[i][k] * arr2[k][j];

    return answer;
}