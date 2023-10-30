#include<bits/stdc++.h>
using namespace std;

int arr[1001];
int n;

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if (right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void maxheap(vector<int> &arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
}
void push(vector<int> &arr, int val) {
    arr.push_back(val);

    int i = arr.size() - 1;
    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pop(vector<int> &arr) {
    if (arr.empty()) {
        throw std::runtime_error("Heap is empty.");
    }

    int max = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    heapify(arr, arr.size(), 0);
    return max;
}
int extractMax(vector<int> &arr, int &n){
    if (n <= 0){
        return INT_MIN;
    }

    int maxVal = arr[0];
    arr[0] = arr[n - 1];
    n--;

    heapify(arr, n, 0);

    return maxVal;
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    maxheap(arr, n);

    
    heapSort(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout << endl;

    return 0;
}

