#include <iostream>
#include <string>
#include <stack>

using namespace std;


/* // String generating solution
string generateParens(string s)
{
	int inputStringPos = 0;
	int outputStringPos = 0;
	string output = "";
	int leftCounter = 0;
	while (inputStringPos < s.length())
	{
		if (s[inputStringPos] == '(')
		{
			output.insert(outputStringPos, "()");
			inputStringPos++;
			outputStringPos++;
			leftCounter++;
		}
		else if (s[inputStringPos] == '{')
		{
			output.insert(outputStringPos, "{}");
			inputStringPos++;
			outputStringPos++;
			leftCounter++;
		}
		else if (s[inputStringPos] == '[')
		{
			output.insert(outputStringPos, "[]");
			inputStringPos++;
			outputStringPos++;
			leftCounter++;
		}
		else
		{
			if (leftCounter > 0)
			{
				leftCounter--;
				outputStringPos++;
			}
			inputStringPos++;
			
		}
		// cout << "output is: " << output << endl;
		// cout << "leftCounter is: " << leftCounter << endl;
	}
	return output;
}

bool equalStrings(string a, string b)
{
	if (a.length() != b.length())
	{
		return 0;
	}
	int i = 0;
	while (i < a.length())
	{
		if (a[i] != b[i])
		{
			return 0;
		}
		i++;
	}
	return 1;
}

bool isValid(string parens)
{
	return equalStrings(parens, generateParens(parens))
}*/

// Stacky solution
bool isValid(string parens)
{
	stack<char> valid;
	int i = 0;
	while (i < parens.length())
	{
		if (parens[i] == '[')
		{
			valid.push(parens[i]);
		}
		else if (parens[i] == '(')
		{
			valid.push(parens[i]);
		}
		else if (parens[i] == '{')
		{
			valid.push(parens[i]);
		}
		else if (parens[i] == ']')
		{
			if (valid.empty() || valid.top() != '[')
			{
				return false;
			}
			else
			{
				valid.pop();
			}
		}
		else if (parens[i] == ')')
		{
			if (valid.empty() || valid.top() != '(')
			{
				return false;
			}
			else
			{
				valid.pop();
			}
		}
		else
		{
			if (valid.empty() || valid.top() != '{')
			{
				return false;
			}
			else
			{
				valid.pop();
			}
		}
		i++;
	}
	if (valid.empty())
	{
		return true;
	}
	return false;
}


int main()
{
	string s = "(([]){})";
	// cout << generateParens(s) << endl;
	if (isValid(s))
	{
		cout << "s is valid." << endl;
	}
	else
	{
		cout << "s is not valid." << endl;
	}
	return 0;
}