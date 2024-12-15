#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
	int m = arr1.size();
	int n = arr2.size();

	arr1.resize(m + n);

	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;

	while (i >= 0 && j >= 0) {
		if (arr1[i] > arr2[j]) {
			arr1[k] = arr1[i];
			i--;
		}
		else {
			arr1[k] = arr2[j];
			j--;
		}
		k--;
	}

	if (j >= 0) {
		arr1[k] = arr2[j];
		j--;
		k--;
	}	

	return arr1;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    vector<int> result = mergeSortedArrays(arr1, arr2);

    cout << "Merged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}