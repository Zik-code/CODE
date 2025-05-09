
//暴力求解

//三层循环

//begin,end分别记录最大子段和的开始和结尾位置的下标，下标从0开始
//a[]是待求数组，n是序列长度
int maxSum(int a[],int n,int &begin,int &end){
	int sum=0;//用来保存最大子段和的值
	for (int i=0;i<n;i++)
		for(int j=i;j<n;i++){
			int temSum=0;//temSum保存每一次a[i]~a[j]的和，然后和当前最大子段和比较
			for(int k=i;k<=j;k++)
				temSum+=a[k];//计算a[i]~a[j]的和
			if(temSum>sum){//如果发现更大的子段和，则更新sum的值，并保存当前最大子段和的开始和结尾下标
				sum=temSum;
				begin=i;
				end=j;
			}
		}
	return sum;
}

// 暴力求解改进后：两层循环

lint maxSum(int a[],int n,int &begin,int &end){
	int sum=0;//用来保存最大子段和的值
	for(int i=0;i<n;i++){
		int temSum=0;//保存从下表为i开始至j的和，当求a[i]~a[j+1]的和时，就可以变为求temSum+a[j+1]
		for(int j=i;j<n;i++){
			temSum+=a[j];
			if(temSum>sum){
				sum=temSum;
				begin=i;
				end=j;
			}
		}
	}
	return sum;	
}

//分治策略
//left是做端点下标，right是右端点下标
int maxSubSum(int a[],int left,int right){
	int sum=0;
	if(left==right)//这是递归调用必须要有的终值情况。
		sum=(a[left]>0?a[left]:0);
	else{
		int center=(left+right)/2;
		int leftSum=maxSubSum(a,left,center);//求出左序列最大子段和
		int rightSum=maxSubSum(a,center+1,right);//求出右序列最大子段和
 
//求跨前后两段的情况，从中间分别向两端扩展。
		//从中间向左扩展。这里注意，中间往左的第一个必然包含在内。
		int ls=0;int lefts=0;
		for(int i=center;i>=left;i--){
			lefts+=a[i];
			if(lefts>ls)
				ls=lefts;
		}
		//从中间向右扩展。中间往右的第一个必然包含在内
		int rs=0;int rights=0;
		for(i=++center;i<=right;i++){
			rights+=a[i];
			if(rights>rs)
				rs=rights;
		}
		sum=ls+rs;//sum保存跨前后两段情况的最大子段和
//求跨前后两段的情况完成
 
		if(sum<leftSum)
			sum=leftSum;//记住，leftSum表示前段序列的最大子段和
		if(sum<rightSum)
			sum=rightSum;//rightSum表示后段序列的最大字段和
	}
	return sum;
}



// 动态规划法

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