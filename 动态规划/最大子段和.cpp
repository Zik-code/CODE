#include <iostream>
using namespace std;

// 函数功能：计算数组的最大子段和，并找出构成最大子段和的元素
// 参数a：指向数组的指针，存储输入的数组元素
// 参数n：数组元素的个数
// 返回值：最大子段和
int MaxSum(int *a, int n) {
    int b = 0;  // 用于记录包含当前元素的最大子段和
    int sum = 0;  // 用于记录全局最大子段和
    int start = 0;  // 记录最大子段和的起始位置
    int end = 0;    // 记录最大子段和的结束位置
    int tempStart = 0;  // 临时记录包含当前元素的最大子段和的起始位置

    for (int i = 0; i < n; i++) {
        if (b > 0) {
            b += a[i];
        } else {
            b = a[i];
            tempStart = i;  // 当重新开始计算子段和时，更新临时起始位置
        }

        if (b > sum) {
            sum = b;
            start = tempStart;  // 更新最大子段和的起始位置
            end = i;  // 更新最大子段和的结束位置
        }
    }

    // 输出构成最大子段和的元素
    cout << "构成最大子段和的元素为: ";
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

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
    cout << "最大子段和为: " << result << endl;

    delete[] a;  // 释放动态分配的数组内存
    return 0;
}