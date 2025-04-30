#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    vector<int> nums(10);
    cout << "Please enter 10 integers: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }

    bubbleSort(nums);

    cout << "Sorted integers: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}