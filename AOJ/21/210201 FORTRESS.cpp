#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct TreeNode {
    int x, y, r;
    vector<TreeNode*> children;
};

int C, INF = 87654321;

bool includes(TreeNode* a, TreeNode* b) { // return weather node a includes node b or not
    return a->r > b->r && pow(a->r - b->r, 2) > pow(a->x - b->x, 2) + pow(a->y - b->y, 2);
}

int getParentIndex(vector<TreeNode*> wall_list, TreeNode* node, TreeNode* root) {
    TreeNode* parent = root;
    int index = 0;
    for(int i = 0; i < wall_list.size(); ++i) {
        if(includes(wall_list[i], node) && includes(parent, wall_list[i])) {
            parent = wall_list[i];
            index = i;
        }
    }
    return index;
}

int getHeight(TreeNode* node) {
    if(node->children.size() == 0) return 0;
    int height = 0;
    for(int i = 0; i < node->children.size(); ++i) {
        height = max(height, 1 + getHeight(node->children[i]));
    }
    return height;
}

int getMaximumChildrenToChildren(TreeNode* node) {
    if(node->children.size() <= 1) return 0;
    int result = 0;
    vector<int> children_heights {};
    for(int i = 0; i < node->children.size(); ++i) {
        children_heights.push_back(getHeight(node->children[i]));
    }
    sort(children_heights.begin(), children_heights.end());
    return 2 + children_heights[children_heights.size() - 1] + children_heights[children_heights.size() - 2];
}

int solve(vector<TreeNode*> wall_list, TreeNode* root) {
    int maximum_children_to_children = 0;
    int maximum_height = 0;
    for(int i = 0; i < wall_list.size(); ++i) {
        maximum_height = max(maximum_height, getHeight(wall_list[i]));
        maximum_children_to_children = max(maximum_children_to_children, getMaximumChildrenToChildren(wall_list[i]));
    }
    return max(maximum_height, maximum_children_to_children);
}

int main(void) {
    cin >> C;
    while(C--) {
        int N, x, y, r;
        vector<TreeNode*> wall_list;
        cin >> N;
        while(N--) {
            cin >> x >> y >> r;
            TreeNode* node = new TreeNode{x, y, r, vector<TreeNode*> {}};
            wall_list.push_back(node);
        }
        TreeNode* root = wall_list[0];
        for(int i = 1; i < wall_list.size(); ++i) {
            int parent_index = getParentIndex(wall_list, wall_list[i], root);
            wall_list[parent_index]->children.push_back(wall_list[i]);
        }
        cout << solve(wall_list, root) << endl;
    }
    return 0;
}