#include <iostream>
using namespace std;

int n, m, c;
int board[15][15];
/* dp[i][j]는 
 * board[i][j], board[i + 1][j], ..., board[i + m - 1][j] 중
 * 도둑이 가져갈 수 있는 최대 가치를 저장
 */
int dp[15][15];

void Simulate(const int row, const int start_col, 
    const int cur_col, const int sum, const int value_sum, int& max_val) 
{
    if (cur_col == start_col + m) {
        if (max_val < value_sum) {
            max_val = value_sum;
        }
        return;
    }

    for (int col{ cur_col }; col < start_col + m; col++) {
        int new_sum = sum + col;
        if (c < new_sum) continue;
        Simulate(row, start_col, col + 1, new_sum, value_sum + col * col, max_val);
    }
}

int FindMaxValue(const int row, const int col) {
    int max_val{ 0 };
    Simulate(row, col, col, 0, 0, max_val);

    return max_val;
}

void CalculateDp() {
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j + m - 1 < n; j++) {
            dp[i][j] = FindMaxValue(i, j);
        }
    }
}

int FindBestComb() {
    int max_sum{ 0 };
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j + m - 1 < n; j++) {
            int sum = dp[i][j];
            for(int k{ i }; k < n; k++) {
                for (int l{ 0 }; l + m - 1 < n; l++) {
                    if (k == i && l <= j) continue;
                    sum += dp[k][l];
                    if (max_sum < sum) max_sum = sum;
                }
            }
        }
    }

    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> c;

    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            cin >> board[i][j];
        }
    }

    CalculateDp();
    int ans = FindBestComb();

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}