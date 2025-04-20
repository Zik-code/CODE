#include <iostream>
using namespace std;

// 假设Type为int类型，若实际是其他类型，修改此处即可
typedef int Type;

// 该函数用于对数组进行划分，返回基准元素最终所在的位置
// 参数 a 是待划分的数组，p 是数组的起始索引，r 是数组的结束索引
int Partiton(Type a[], int p, int r) {
    // 初始化左指针 i 为起始索引 p
    int i = p;
    // 初始化右指针 j 为结束索引 r 加 1，方便后续操作
    int j = r + 1;
    // 选择数组的第一个元素作为基准元素
    Type x = a[p];

    // 进入循环，不断交换元素，直到左右指针相遇或交叉
    while (true) {
        // 左指针 i 向右移动，找到第一个大于等于基准元素 x 的元素
        // 同时要保证 i 不超过结束索引 r
        while (a[++i] < x && i < r);
        // 右指针 j 向左移动，找到第一个小于等于基准元素 x 的元素
        while (a[--j] > x);
        // 如果左指针 i 已经大于等于右指针 j，说明划分完成，退出循环
        if (i >= j)
            break;
        // 交换左指针 i 和右指针 j 所指向的元素
        swap(a[i], a[j]);
    }

    // 将基准元素放到正确的位置，即右指针 j 所指向的位置
    a[p] = a[j];
    a[j] = x;
    // 返回基准元素最终所在的位置
    return j;
}

// 该函数用于实现快速排序算法
// 参数 a 是待排序的数组，p 是数组的起始索引，r 是数组的结束索引
void QuickSort(Type a[], int p, int r) {
    // 如果起始索引 p 小于结束索引 r，说明数组中至少有两个元素，需要继续排序
    if (p < r) {
        // 调用 Partiton 函数对数组进行划分，得到基准元素的位置 q
        int q = Partiton(a, p, r);
        // 对基准元素左边的子数组进行快速排序
        QuickSort(a, p, q - 1);
        // 对基准元素右边的子数组进行快速排序
        QuickSort(a, q + 1, r);
    }
}

int main() {
    // 定义测试数组
    Type arr[] = {13, 8, 17, 10, 15, 18, 12, 20, 9, 14, 6, 19};
    // 计算数组的长度
    int n = sizeof(arr) / sizeof(arr[0]);
    // 调用 QuickSort 函数对数组进行排序
    QuickSort(arr, 0, n - 1);
    // 遍历排序后的数组，并输出每个元素
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // 输出换行符
    cout << endl;
    // 程序正常结束，返回 0
    return 0;
}