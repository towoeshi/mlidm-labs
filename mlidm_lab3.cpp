#include <iostream>
#include <vector>

using namespace std;

bool isFunction(vector<vector<int>>& relation, vector<string>& arrA, vector<int>& arrB) {
	

	if (relation.size() != arrA.size())
		return false;

	for (int i = 0; i < relation.size(); i++) {
		int c = 0;
		for (int j = 0; j < relation[i].size(); j++) {
			if (relation[i][j] == 1) {
				c++;
			}
		}
		if (c > 1 || c == 0)
			return false;
		c = 0;
	}

	return true;
}
int main() {

	int sizeA, sizeB;

	cout << "enter the number of array A: ";
	cin >> sizeA;
	vector<string> arrA(sizeA);
	cout << "enter the elements of array A (a,b,c...): ";
	for (int i = 0; i < sizeA; i++)
		cin >> arrA[i];

	cout << "enter the number of array B: ";
	cin >> sizeB;
	vector<int> arrB(sizeB);
	cout << "enter the elements of array B (1,2,3...): ";
	for (int i = 0; i < sizeB; i++) {
		cin >> arrB[i];
	}

	int n, m;
	cout << "enter the number of rows and collumns: ";
	cin >> n >> m;
	vector<vector<int>> relation(n, vector<int>(m));
	cout << "enter the matrix (" << n << " x " << m << ") of the relation : \n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> relation[i][j];

	if (isFunction(relation, arrA, arrB))
		cout << "relation is a function";
	if (!isFunction(relation, arrA, arrB))
		cout << "relation is NOT a function";

	return 0;
}