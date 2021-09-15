#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void vectorBTree(TreeNode* root, vector<vector<int>>& v, int level, unordered_map<int, bool>& levs)
{
    // cout << root->val << endl;
    // cout << "Level is: " << level << endl;
    if (root != nullptr)
    {
        if (!levs.count(level))
        {
            // cout << "BLOOBKE" << endl;
            v.push_back({ root->val });
            levs[level] = 1;
        }
        else
        {
            v[level].push_back(root->val);
        }
        level++;
        vectorBTree(root->left, v, level, levs);
        vectorBTree(root->right, v, level, levs);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levelOrd;
    unordered_map<int, bool> levs;
    int level = 0;
    vectorBTree(root, levelOrd, level, levs);
    return levelOrd;
}

int main()
{
    return 0;
}