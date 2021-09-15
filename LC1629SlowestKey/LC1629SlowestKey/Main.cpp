#include<iostream>
#include<vector>
#include<string>

using namespace std;

char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int max = releaseTimes[0];
    char key = keysPressed[0];
    int diff = 0;
    for (int i = 1; i < releaseTimes.size(); i++)
    {
        diff = releaseTimes[i] - releaseTimes[i - 1];
        if (diff > max)
        {
            max = diff;
            key = keysPressed[i];
        }
        else if (diff == max)
        {
            if (keysPressed[i] > key)
            {
                key = keysPressed[i];
            }
        }
    }
    return key;
}

int main()
{
    return 0;
}