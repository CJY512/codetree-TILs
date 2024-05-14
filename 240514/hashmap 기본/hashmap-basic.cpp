#include <iostream>
#include <string>
#include <unordered_map>

void um_add(std::unordered_map<int, int>& um, const int key, const int value) {
    um[key] = value;
    return;
}

void um_remove(std::unordered_map<int, int>& um, const int key) {
    um.erase(key);
    return;
}

std::string um_find(std::unordered_map<int, int>& um, const int key) {
    auto it = um.find(key);
    return it != um.end() ? std::to_string(it->second) : "None";
}

int main() {
    std::unordered_map<int, int> um;

    int n;
    std::cin >> n;

    std::string cmd;
    int key, value;
    while(n--) {
        std::cin >> cmd;

        if (cmd == "add") {
            std::cin >> key >> value;
            um_add(um, key, value);
        } else if (cmd == "remove") {
            std::cin >> key;
            um_remove(um, key);
        } else if (cmd == "find") {
            std::cin >> key;
            std::cout << um_find(um, key) << "\n";
        } else {
            std::cout << "Undefined command.\n";
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}