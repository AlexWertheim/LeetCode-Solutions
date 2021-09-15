#include<iostream>
#include<vector>

using namespace std;

/* 
// My first attempt, which can be improved to "constant" memory 
// as below by just keeping track of the running product from the left
// and the right! It's also faster!
vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> left(len, 1);
    vector<int> right(len, 1);
    for (int i = 1; i < len; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
        right[(len - i) - 1] = right[(len - i)] * nums[(len - i)];
    }
    for (int k = 0; k < len; k++)
    {
        left[k] *= right[k];
    }
    return left;
}
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len, 1);
    int left = 1, right = 1;
    for (int i = 0; i < len; i++)
    {
        ans[i] *= left;
        left *= nums[i];
        ans[len - 1 - i] *= right;
        right *= nums[len - 1 - i];
    }
    return ans;
}

int main()
{
    return 0;
}
