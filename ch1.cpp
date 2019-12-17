/*
 * bubblesorta, 冒泡排序算法，复杂度、O(n^2)
 * countOnes, 计算二进制中1的位数，时间复杂度O(logn)
 * */
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

int countOnes(unsigned int n) {
    int count = 0;
    while(n > 0) {
        count += (n & 1);
        n >> 1;
    }
    return count;
}
/*
 * 数组倒置的线性递归版，复杂度O(n)
 * */
void reverse(int *A, int lo, int hi) {
    if(lo < hi) {
        swap(A[lo], A[hi]);
        reverse(A, lo+1, hi-1);
    }
}


/* 
 *幂函数的线性递归版 复杂度O(logn) 和n的位数乘线性关系
 * */
inline int sqr(int a) {return a*a;};
int power2(int n) {
    if (n == 0) return 1;
    return n&1 ? sqr(power2(n>>1))<<1 : sqr(power2(n>>1));
}
int main() {
    int test[7] = {2,5,1,7,6,3,4};
    bubblesortaA(test, 7);
    for (auto i : test) cout << power2(i) <<" ";
    cout << endl;
    
}