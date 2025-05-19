#include <iostream>
#include <string>
#include <vector>

using namespace std;
//bjbi

struct Element {
    char letter1;     
    char evenNumber;    
    char letter2;
    char number;   
};

void inputArray(vector<Element>& mass, int size) {
    Element elem;

    for (int i = 0; i < size; ++i) {
        cout << "Input Element bjbi " << i << ": ";
        string input;
        cin >> input;

        if (input.length() == 4 &&
            (input[0] >= 'a' && input[0] <= 'z') &&
            (input[1] >= '0' && input[1] <= '9') && (input[1] - '0') % 2 != 0 &&
            (input[2] >= 'a' && input[2] <= 'z') &&
            (input[3] >= '0' && input[3] <= '9') && (input[3] - '0') % 2 == 0)
            {
                elem.letter1 = input[0];
                elem.evenNumber = input[1];
                elem.letter2 = input[2];
                elem.number = input[3];
                mass.push_back(elem);
        }
        else {
            cout << "Error input" << endl;
            i--;
        }
    }
}

void printArray(const vector<Element>& mass) {
    for (int i = 0; i < mass.size(); ++i) {
        cout << "Element " << i << ": " << mass[i].letter1 << mass[i].evenNumber << mass[i].letter2 << mass[i].number << endl;
    }
}

void removeNonUnique(vector<Element>& mass) {
    vector<Element> uniqueElements;

    for (int i = 0; i < mass.size(); ++i) {
        bool isUnique = true;

        for (int j = 0; j < uniqueElements.size(); ++j) {
            if (mass[i].letter1 == uniqueElements[j].letter1 &&
                mass[i].evenNumber == uniqueElements[j].evenNumber &&
                mass[i].letter2 == uniqueElements[j].letter2 &&
                mass[i].number == uniqueElements[j].number) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            uniqueElements.push_back(mass[i]);
        }
    }

    mass.clear();
    for (size_t i = 0; i < uniqueElements.size(); ++i) {
        mass.push_back(uniqueElements[i]);
    }
}

void unionArrays(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); ++i)
        result.push_back(mass1[i]);
    for (int i = 0; i < mass2.size(); ++i)
        result.push_back(mass2[i]);
    removeNonUnique(result);
}

void intersectionArrays(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); i++) {
        for (int j = 0; j < mass2.size(); j++) {
            if (mass1[i].letter1 == mass2[j].letter1 &&
                mass1[i].evenNumber == mass2[j].evenNumber &&
                mass1[i].letter2 == mass2[j].letter2 &&
                mass1[i].number == mass2[j].number){
                result.push_back(mass1[i]);
            }
        }
    }
    removeNonUnique(result);
}

void complementArrays(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); i++) {
        bool isNotFound = true;
        for (int j = 0; j < mass2.size(); j++) {
            if (mass1[i].letter1 == mass2[j].letter1 &&
                mass1[i].evenNumber == mass2[j].evenNumber &&
                mass1[i].letter2 == mass2[j].letter2 &&
                mass1[i].number == mass2[j].number) {
                isNotFound = false;
            }
        }
        if (isNotFound)
            result.push_back(mass1[i]);
    }
}


void symmetricDifference(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    vector<Element> complement1;
    vector<Element> complement2;
    complementArrays(complement1, mass1, mass2);
    complementArrays(complement2, mass2, mass1);
    for (int i = 0; i < complement1.size(); ++i)
        result.push_back(complement1[i]);
    for (int i = 0; i < complement2.size(); ++i)
        result.push_back(complement2[i]);
}
int main() {
    int size1, size2;
    vector<Element> mass1;
    vector<Element> mass2;
    vector<Element> mass_unification;
    vector<Element> mass_intersection;
    vector<Element> mass_complementAB;
    vector<Element> mass_complementBA;
    vector<Element> mass_symmetricDiff;
    cout << "Input SIZE first array: ";
    cin >> size1;
    inputArray(mass1, size1);
    cout << "\n";

    cout << "Input SIZE second array: ";
    cin >> size2;
    inputArray(mass2, size2);
    cout << "\n";

    cout << "Unique elements of the first array: " << endl;
    removeNonUnique(mass1);
    printArray(mass1);
    cout << "\n";

    cout << "Unique elements of the second array: " << endl;
    removeNonUnique(mass2);
    printArray(mass2);
    cout << "\n";

    unionArrays(mass_unification, mass1, mass2);
    cout << "elements of union arrays: " << endl;
    printArray(mass_unification);
    cout << "\n";

    intersectionArrays(mass_intersection, mass1, mass2);
    cout << "elements of intersected arrays" << endl;
    printArray(mass_intersection);
    cout << "\n";

    complementArrays(mass_complementAB, mass1, mass2);
    cout << "elements of complement arrays (A/B)" << endl;
    printArray(mass_complementAB);
    cout << "\n";

    complementArrays(mass_complementBA, mass2, mass1);
    cout << "elements of complement arrays (B/A)" << endl;
    printArray(mass_complementBA);
    cout << "\n";

    symmetricDifference(mass_symmetricDiff, mass1, mass2);
    cout << "elements of symmetric difference arrays" << endl;
    printArray(mass_symmetricDiff);
    cout << "\n";

    return 0;
}