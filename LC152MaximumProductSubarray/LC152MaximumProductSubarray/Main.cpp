#include<iostream>
#include<vector>

using namespace std;

// Solution based on the idea that:
// maximum product subarrays first partitioned by locations of zeroes.
// then, maximum product within subarray with no zeroes given by longest
// subarray with an even number of negative entries; must check from both
// left and right.

// Apparently, there is a DP solution too! Should come back and write this

int maxProduct(vector<int>& nums) {
    if (nums.size() == 1)
    {
        return nums[0];
    }
    vector<int> candidates;
    // vector<int> zeroes;
    // vector<int> negatives;
    bool neg = 0;
    bool nonempty = 0;
    bool hasZero = 0;
    int posProd = 1;
    int negProd = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            nonempty = 1;
            if (neg)
            {
                negProd *= nums[i];
            }
            else
            {
                posProd *= nums[i];
            }
        }
        else if (nums[i] < 0)
        {
            if (neg)
            {
                negProd *= nums[i];
                posProd *= negProd;
                negProd = 1;
                neg = 0;
                nonempty = 1;
            }
            else
            {
                negProd *= nums[i];
                neg = 1;
            }
        }
        else
        {
            hasZero = 1;
            if (nonempty)
            {
                candidates.push_back(posProd);
            }
            posProd = 1;
            negProd = 1;
            neg = 0;
            nonempty = 0;
        }
    }
    if (nonempty) // if there was no zero, then we just have to add posProd
    {
        candidates.push_back(posProd);
    }
    if (hasZero)
    {
        candidates.push_back(0); // there's a 0, so make sure to add it!
    }
    posProd = 1;
    negProd = 1;
    neg = 0;
    nonempty = 0;
    for (int i = nums.size() - 1; i > -1; i--)
    {
        if (nums[i] > 0)
        {
            nonempty = 1;
            if (neg)
            {
                negProd *= nums[i];
            }
            else
            {
                posProd *= nums[i];
            }
        }
        else if (nums[i] < 0)
        {
            if (neg)
            {
                negProd *= nums[i];
                posProd *= negProd;
                negProd = 1;
                neg = 0;
                nonempty = 1;
            }
            else
            {
                negProd *= nums[i];
                neg = 1;
            }
        }
        else
        {
            if (nonempty)
            {
                candidates.push_back(posProd);
            }
            posProd = 1;
            negProd = 1;
            neg = 0;
            nonempty = 0;
        }
    }
    if (nonempty) // if there was no zero, then we just have to add posProd
    {
        candidates.push_back(posProd);
    }
    int max = nums[0];
    for (int j = 0; j < candidates.size(); j++)
    {
        // cout << "Candidates[j] is: " << candidates[j] << endl;
        if (max < candidates[j])
        {
            max = candidates[j];
        }
    }
    return max;
}