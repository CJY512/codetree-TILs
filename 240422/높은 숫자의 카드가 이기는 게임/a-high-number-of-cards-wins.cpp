#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {

    cin >> n;
    vector<bool> arr(2 * n + 1);

    int idx;
    for(int i{ 0 }; i < n; i++) {
        cin >> idx;
        arr[idx] = true;
    }
    
    int card_b{ 0 };
    int max_a_win{ 0 };
    for(int i{ 1 }; i <= 2 * n; i++) {
        if(arr[i]) {
            card_b++;
        }
        else {
            if(card_b > 0) {
                card_b--;
                max_a_win++;
            }
        }
    }

    cout << max_a_win;
    // 여기에 코드를 작성해주세요.
    return 0;
}