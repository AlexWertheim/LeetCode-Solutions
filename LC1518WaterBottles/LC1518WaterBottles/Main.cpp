#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) 
{
	int emptyBottles = 0, totalBottles = 0, drinkBottles = numBottles, bottlesDrunk = 0;
	while (drinkBottles > 0)
	{
		emptyBottles += drinkBottles;
		totalBottles += drinkBottles;
		bottlesDrunk = drinkBottles;
		/* cout << "drinkBottles is: " << drinkBottles << endl;
		cout << "emptyBottles is: " << emptyBottles << endl;
		cout << "totalBottles is: " << totalBottles << endl;
		cout << "bottlesDrunk is: " << bottlesDrunk << endl;*/
		drinkBottles = (emptyBottles / numExchange);
		emptyBottles = (emptyBottles % numExchange);
		/* cout << "drinkBottles is: " << drinkBottles << endl;
		cout << "emptyBottles is: " << emptyBottles << endl;
		cout << endl;*/
	}
	return totalBottles;
}

int main()
{
	cout << numWaterBottles(5, 5) << endl;
	return 0;
}