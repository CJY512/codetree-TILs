#include <iostream>
#include <stack>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n; std::cin >> n;
    std::string cmd;
    int arg;
    std::stack<int> stk;
    while(n--) {
        std::cin >> cmd;
        if (cmd == "push") {
            std::cin >> arg;
            stk.push(arg);
        } else if (cmd == "size") {
            std::cout << stk.size() << "\n";
        } else if (cmd == "empty") {
            std::cout << stk.empty() << "\n";
        } else if (cmd == "pop") {
            std::cout << stk.top() << "\n";
            stk.pop();
        } else if (cmd == "top") {
            std::cout << stk.top() << "\n";
        } else {
            std::cout << "cannot reach here!\n";
        }
    }
    return 0;
}