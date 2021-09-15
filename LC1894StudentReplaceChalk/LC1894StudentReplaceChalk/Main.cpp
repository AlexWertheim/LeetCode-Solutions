#include<iostream>
#include<vector>

using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    int student = 0;
    int numStudents = chalk.size();
    unsigned int chalkSum = 0;
    int i = 0;
    while (i < numStudents && chalkSum < k)
    {
        chalkSum += chalk[i];
        i++;
    }
    k = k % chalkSum;
    while (k >= chalk[student])
    {
        k -= chalk[student];
        student++;
    }
    return student;
}

int main()
{
    return 0;
}