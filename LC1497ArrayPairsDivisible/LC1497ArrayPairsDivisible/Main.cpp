#include<iostream>
#include<vector>

using namespace std;

bool canArrange(vector<int>& arr, int k) {
    vector<int> buckets(k, 0);
    int bucket;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
        {
            bucket = (arr[i] % k);
        }
        else
        {
            bucket = (k - (abs(arr[i]) % k)) % k;
        }
        buckets[bucket]++;
    }
    if (buckets[0] % 2)
    {
        return false;
    }
    if ((k % 2) == 0)
    {
        if (buckets[(k / 2)] % 2)
        {
            return false;
        }
    }
    int j = 1, l = k - 1;
    while (j < l)
    {
        if (buckets[j] != buckets[l])
        {
            return false;
        }
        j++;
        l--;
    }
    return true;
}

int main()
{
    return 0;
}