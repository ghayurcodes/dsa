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




// int main() {
// 	int n, t1 = 0, t2 = 1, nextTerm = 0;

// 	cout << "enter the no of terms: ";
// 	cin >> n;
// 	cout << "fibonacci series: ";
// 	cout << t1 << ", " << t2<<", ";

// 	for (int i = 0; i <= n; i++) {
// 		nextTerm = t1 + t2;

// 		t1 = t2;
// 		t2 = nextTerm;
// 		cout << nextTerm << ", ";
// 	}
	
// 	return 0;
// }