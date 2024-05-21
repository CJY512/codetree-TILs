#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;

bool isNumber(const std::string& str) {
    if(str.empty()) return false;

    for (const char& c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    unordered_map<string, int> str_to_idx;
    unordered_map<int, string> idx_to_str;

    cin >> n >> m;

    for (int i{ 1 }; i <= n; i++) {
        string s;
        cin >> s;
        str_to_idx[s] = i;
        idx_to_str[i] = s;
    }

    while(m--) {
        string s;
        cin >> s;
        if (isNumber(s)) {
            cout << idx_to_str[stoi(s)] << "\n";
        }
        else {
            cout << str_to_idx[s] << "\n";
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}