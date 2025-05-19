#include <iostream>
#include <vector>

using namespace std;

bool isReflexive(vector<vector<int>>& r) {
	for (int i = 0; i < r.size(); i++) {
		int fl = 0;
		for (int j = 0; j < r.size(); j++) {
			if (r[j][0] == r[j][1] && r[j][0] == r[i][0])
				fl++;
			
		}
		if (fl == 0)
			return false;
	}
	return true;
}

bool isSymmetric(vector<vector<int>>& r) {
	for (int i = 0; i < r.size(); i++) {
		int fl = 0;
		for (int j = 0; j < r.size(); j++) {
			if (r[i][0] == r[j][1] && r[i][1] == r[j][0])
				fl++;
		}
		if (fl == 0)
			return false;
	}
	return true;
}

bool isTransitive(vector<vector<int>>& r) {
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			if (r[i][1] == r[j][0]) {
				int a = r[i][0];
				int b = r[j][1];
				bool found = false;
				for (int k = 0; k < r.size(); k++) {
					if (r[k][0] == a && r[k][1] == b) {
						found = true;
						break;
					}
				}
				if (found == false) {
					return false;
				}
			}
		}
	}
	return true;
}

bool isAntisymmetric(vector<vector<int>>& r) {
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			if (r[i][0] == r[j][1] && r[i][1] == r[j][0] && r[i][0] != r[i][1])
				return false;
		}
	}
	return true;
}

int main() {
	int n;

	cout << "enter the number of pairs: ";
	cin >> n;

	vector<vector<int>> relation(n, vector<int>(2));
	for (int i = 0; i < n; i++){
		cout << "enter the " << i << " pair (a,b): ";
		for (int j = 0; j < 2; j++)
			cin >> relation[i][j];
	}

	if (isReflexive(relation))
		cout << "relation is reflexive\n";
	if (!isReflexive(relation))
		cout << "relation isn't reflexive\n";

	if (isSymmetric(relation))
		cout << "relation is symmetric\n";
	if (!isSymmetric(relation))
		cout << "relation isn't symmetric\n";

	if (isTransitive(relation))
		cout << "relation is transitive\n";
	if (!isTransitive(relation))
		cout << "relation isn't transitive\n";

	if (isAntisymmetric(relation))
		cout << "relation is antisymmetric\n";
	if (!isAntisymmetric(relation))
		cout << "relation isn't antisymmetric\n";

	return 0;
}
