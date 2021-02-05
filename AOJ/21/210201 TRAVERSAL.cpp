#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C;

vector<int> getPostOrder(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0) return vector<int> {};
    if(preorder.size() == 1) return vector<int> {preorder[0]};

    vector<int>::iterator itr = find(inorder.begin(), inorder.end(), preorder[0]);
    int root_index = distance(inorder.begin(), itr);
    vector<int> preorder_left_child = {preorder.begin() + 1, preorder.begin() + root_index + 1};
    vector<int> preorder_right_child = {preorder.begin() + root_index + 1, preorder.end()};
    vector<int> inorder_left_child = {inorder.begin(), inorder.begin() + root_index};
    vector<int> inorder_right_child = {inorder.begin() + root_index + 1, inorder.end()};

    vector<int> result {};
    vector<int> centerPostOrder = vector<int> {preorder[0]};
    vector<int> leftPostOrder = getPostOrder(preorder_left_child, inorder_left_child);
    vector<int> rightPostOrder = getPostOrder(preorder_right_child, inorder_right_child);

    result.insert(result.end(), leftPostOrder.begin(), leftPostOrder.end());
    result.insert(result.end(), rightPostOrder.begin(), rightPostOrder.end());
    result.insert(result.end(), centerPostOrder.begin(), centerPostOrder.end());
    return result;
}

int main(void) {
    cin >> C;
    while(C--) {
        vector<int> preorder {};
        vector<int> inorder {};
        int N;
        cin >> N;
        for(int i = 0; i < N; ++i) {
            int node;
            cin >> node;
            preorder.push_back(node);
        }
        for(int i = 0; i < N; ++i) {
            int node;
            cin >> node;
            inorder.push_back(node);
        }
        vector<int> result = getPostOrder(preorder, inorder);
        for(int i = 0; i < N; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}