def binary_insertion_sort(array):
    # 从数组的第二个元素开始遍历，因为第一个元素可以看作已经排好序
    for i in range(1, len(array)):
        # 取出当前要插入的元素
        key = array[i]
        # 初始化二分查找的左右边界
        low, high = 0, i - 1

        # 二分查找插入位置
        while low <= high:
            mid = (low + high) // 2
            if array[mid] > key:
                high = mid - 1
            else:
                low = mid + 1

        # 将插入位置之后的元素依次后移
        for j in range(i - 1, low - 1, -1):
            array[j + 1] = array[j]

        # 将当前元素插入到合适的位置
        array[low] = key

    # 返回排序好的数组
    return array

if __name__ == '__main__':
    # 定义一个待排序的数组
    array = [24, 19, 45, 28, 13, 14, 22, 32, 21, 48, 4, 47, 8, 39, 11]
    # 调用折半插入排序函数对数组进行排序，并打印排序后的数组
    print(binary_insertion_sort(array))