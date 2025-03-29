
# 定义插入排序函数，该函数接受一个数组作为参数
def insertion_sort(array):
    # 从数组的第二个元素开始遍历，因为第一个元素可以看作已经排好序
    for i in range(1, len(array)):
        # 取出当前要插入的元素a
        key = array[i]
        # 记录当前元素的前一个位置的索引
        j = i - 1
        # 当 j 大于等于 0 且前一个元素大于当前要插入的元素时
        while j >= 0 and array[j] > key:
            # 将前一个元素后移一位
            array[j + 1] = array[j]
            # j 减 1，继续比较前一个元素
            j = j - 1
        # 找到合适的插入位置后，将当前元素插入到该位置
        array[j + 1] = key
    # 返回排序好的数组
    return array

if __name__ == '__main__':
    # 定义一个待排序的数组
    array = [24, 19, 45, 28, 13, 14, 22, 32, 21, 48, 4, 47, 8, 39, 11]
    # 调用插入排序函数对数组进行排序，并打印排序后的数组
    print(insertion_sort(array))






    