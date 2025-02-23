#include <iostream>

using namespace std;

int n;
int pre_order[100000];
int in_order[100000];

int pre_idx{ 0 };

struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int val): value(val), left(nullptr), right(nullptr) {}
};

int get_inorder_idx_by_value(const int val, const int begin, const int end) {
    //이진 탐색 혹은 중복 값이 없다면 해시?
    for(int i{ begin }; i <= end; i++) {
        if (in_order[i] == val)
            return i;
    }
    return -1;
}

Node* build_tree(const int begin, const int end) {
    if (begin > end)
        return nullptr;

    int root_value = pre_order[pre_idx++];
    Node *tree = new Node(root_value);
    int in_idx = get_inorder_idx_by_value(root_value, begin, end);
    tree->left = build_tree(begin, in_idx - 1);
    tree->right = build_tree(in_idx + 1, end);

    return tree;
}

void print_postorder(Node *tree) {
    if (!tree) return;
    print_postorder(tree->left);
    print_postorder(tree->right);
    cout << tree->value << " ";
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> pre_order[i];

    for (int i = 0; i < n; i++) cin >> in_order[i];

    // Write your code here!
    Node *tree = build_tree(0, n - 1);
    print_postorder(tree);

    return 0;
}