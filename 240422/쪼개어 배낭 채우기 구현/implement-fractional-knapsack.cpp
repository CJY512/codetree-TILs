#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, m;

bool comp(tuple<int, int, double> t1, tuple<int, int, double> t2) {
    int w1, w2, v1, v2;
    double vpw1, vpw2;
    tie(w1, v1, vpw1) = t1;
    tie(w2, v2, vpw2) = t2;
    
    if (vpw1 == vpw2) {
        return w1 >= w2;
    }

    return vpw1 > vpw2;
}

int main() {

    cin >> n >> m;
    vector<tuple<int, int, double>> w_v_vpw(n);

    for(int i{ 0 }; i < n;i++) {
        int w, v;
        cin >> w >> v;
        double vpw = static_cast<double>(v) / w;
        w_v_vpw[i] = {w, v, vpw};
    }
    sort(w_v_vpw.begin(), w_v_vpw.end(), comp);

    double max_val = 0.0;
    for(int i{ 0 }; i < n;i++) {
        int w, v;
        double vpw;
        tie(w, v, vpw) = w_v_vpw[i];

        if (m <= w) {
            max_val += m * vpw;
            break;
        }
        else {
            max_val += v;
            m -= w;
        }
    }

    cout << fixed << setprecision(3) << max_val;
    // 여기에 코드를 작성해주세요.
    return 0;
}