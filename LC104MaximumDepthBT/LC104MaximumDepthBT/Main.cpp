#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
}

/* Mysteriously faster?? 
 int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth)+1;
    }

*/

int main()
{
    int val;
    val = 6;
    cout << &val << endl;
    cout << val << endl;
    return 0;
}