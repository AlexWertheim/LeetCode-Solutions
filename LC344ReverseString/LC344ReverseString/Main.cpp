#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) 
{
	int len = s.size();
	char temp;
	for (int i = 0; i < (len / 2); i++)
	{
		temp = s[i];
		s[i] = s[(len-1) - i];
		s[(len - 1) - i] = temp;
	}
}

/* lower memory solution
 void reverseString(vector<char>& s)
{
	int i =0, j = s.size()-1;
	char temp;
	while(i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
*/

int main()
{
	// vector<char> s = {"h", "e"}
	return 0;
}