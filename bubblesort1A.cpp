#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;

}
void bubblesortaA(int A[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n; i ++) {
            if (A[i-1] > A[i]) {
                swap(A[i-1], A[i]);
                sorted = false;
            }
        }
        n --;
    }
}

int main() {
    int test[7] = {2,5,1,7,6,3,4};
    bubblesortaA(test, 7);
    for (auto i : test) cout << i <<" ";
    cout << endl;
    
}