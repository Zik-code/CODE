#include <iostream>
using namespace std;

// 计算最大子数组和的函数
int MaxSum(int *a, int n) {
    int b = 0, sum = 0;
    for (int i = 0; i < n; i++) {  
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > sum)
            sum = b;
    }
    return sum;
}
int main() {
    int n;
    cout << "请输入数组元素个数: ";
    cin >> n;
    int *a = new int[n];
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = MaxSum(a, n);
    cout << "最大子数组和为: " << result << endl;
    delete[] a;  // 释放动态分配的数组内存
    return 0;
}
