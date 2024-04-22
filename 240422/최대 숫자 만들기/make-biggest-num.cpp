#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;

bool cmp(const string s1, const string s2) {
    string s = s1 + s2;
    string s_rev = s2 + s1;
    return stoi(s) > stoi(s_rev);
}

int main() {

    cin >> n;
    vector<string> arr(n);
    
    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);

    for(int i{ 0 }; i < n;i++) {
        cout << arr[i];
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}