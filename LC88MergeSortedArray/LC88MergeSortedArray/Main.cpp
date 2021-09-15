#include <iostream>
#include <vector>

using namespace std;

/* Slow solution I wrote
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0, bound = m;
    while (j < n && i < bound)
    {
        if (nums1[i] <= nums2[j])
        {
            // cout << "LESS" << endl;
            cout << nums1[i] << ", " << nums2[j] << endl;
            i++;
        }
        else
        {
            // cout << "MORE" << endl;
            cout << nums1[i] << ", " << nums2[j] << endl;
            for (int k = m + j; k > i; k--)
            {
                nums1[k] = nums1[k - 1];
            }
            nums1[i] = nums2[j];
            j++;
            i++;
            bound++;
        }
    }
    if (j < n)
    {
        for (int k = m + j; k < m + n; k++)
        {
            nums1[k] = nums2[k - m];
        }
    }
}*/

// Clever solution I learned from submissions

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    return 0;
}