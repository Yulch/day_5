#include <iostream>
using namespace std;

void pushToMas(int* source, int val, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << source[i];
	}
	cout << endl;
	for (int i = size - 2; i >= 0; i--) {
		source[i + 1] = source[i];
	}
	source[0] = val;
	for (int i = 0; i < size; i++)
	{
		cout << source[i];
	}
}
int main() {
	int val;
	const int size = 5;
	cin >> val;
	int source[size] = { 1,2,3,4,5 };
	pushToMas(source, val, size);
	return 0;
}
