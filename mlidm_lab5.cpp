#include <iostream>
#include <vector>

using namespace std;

void booleanAddition(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {

	vector<vector<int>> temp(matrix1.size(), vector<int>(matrix1.size()));

	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1.size(); j++) {
			temp[i][j] = matrix1[i][j] || matrix2[i][j];
		}
	}
	matrix1 = temp;
}

void booleanMultiply(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
	
	vector<vector<int>> temp(matrix1.size(), vector<int>(matrix1.size(), 0));

	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1.size(); j++) {
			for (int k = 0; k < matrix1.size(); k++)
				temp[i][j] = temp[i][j] || (matrix1[i][k] && matrix2[k][j]);
		}
	}
	matrix1 = temp;
}


void getReachabilityMatrix(vector<vector<int>>& adjacencyMatrix) {

	vector<vector<int>> reachabilityMatrix = adjacencyMatrix;
	vector<vector<int>> temp = adjacencyMatrix;

	for (int i = 2; i < adjacencyMatrix.size(); i++) {
		booleanMultiply(temp, adjacencyMatrix);
		booleanAddition(reachabilityMatrix, temp);
	}

	cout << "the reachability matrix is: " << endl;
	for (int i = 0; i < reachabilityMatrix.size(); i++) {
		for (int j = 0; j < reachabilityMatrix.size(); j++)
			cout << reachabilityMatrix[i][j] << " ";
		cout << endl;
	}
			
}
int main() {
	int vertexNumber;
	cout << "enter the vertex number: ";
	cin >> vertexNumber;

	vector<vector<int>> adjacencyMatrix(vertexNumber, vector<int>(vertexNumber));
	cout << "enter the adjacency matrix (" << vertexNumber << " x " << vertexNumber << "): " << endl;
	for (int i = 0; i < vertexNumber; i++)
		for (int j = 0; j < vertexNumber; j++)
			cin >> adjacencyMatrix[i][j];
	cout << endl;
	getReachabilityMatrix(adjacencyMatrix);

	return 0;
}