
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size() - 1;  // 有效数据从arr[1]到arr[n]

    for (int i = 2; i <= n; ++i) {
        if (arr[i] < arr[i - 1]) {
            arr[0] = arr[i]; // 哨兵位
            int j;
            // 找到插入位置并移动元素
            for (j = i - 1; arr[0] < arr[j]; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0]; // 插入到正确位置
        }
    }
}

int main() {
    // 原始测试数组（索引0作为哨兵位）
    vector<int> array = { 0, 24, 19, 45, 28, 13, 14, 22, 32, 21, 48, 4, 47, 8, 39, 11 };
    // 打印原始数组（有效数据从索引1开始）
    cout << "Original array:\n";
    for (size_t i = 1; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
    cout << "\n\n";

    // 执行排序
    insertionSort(array);

    // 打印排序结果
    cout << "Sorted array:\n";
    for (size_t i = 1; i < array.size(); ++i) {
        cout << array[i] << " ";
    }

    return 0;
}s