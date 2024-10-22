#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	
	int arr[2][4];/*= {
	{ 1,2,3,4 },
	{ 5,6,7,8 }
	};*/\
		srand(time(0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = rand() % 100;
                                           
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}
}