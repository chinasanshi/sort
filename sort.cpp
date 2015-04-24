#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
 

void printarray(int a[], int length);

void bubblesort(int a[], int length);

void insertsort(int a[], int length);
void insertsort2(int a[], int length);
void insertsort3(int a[], int length);

void mergearray(int a[], int left, int right, int middle, int temparray[]);
void mergesort(int a[], int left, int right, int temparray[]);

int parentnode(int i);
int leftnode(int i);
int rightnode(int i);
void maxheapify(int a[], int i, int num);
void buildheap(int a[], int num);
void heapsort(int a[], int num);

int partition(int a[], int left, int right);
void quicksort(int a[], int left, int right);

void countingsort(int a[], int b[], int num, int c[], int upperbound);

void shellsort(int a[], int num);




int main(){
	int a[10] = { 6, 2, 4, 1, 9, 0, 8, 7, 3, 5 };
	int b[10] = { 0 };
	int c[10] = { 0 };

	//int a1[10] = { 0, 2, 14, 6, 39, 1, 3, 5, 28, 7 };
	//int a2[10] = {0};
	//int a3[40] = { 0 };

	printarray(a,10);

	//bubblesort(a,9);
	//insertsort(a, 9);
	//insertsort3(a, 9);
	mergesort(a, 0, 9, b);
	//heapsort(a, 9);
	//partition(a1, 0, 9);
	//quicksort(a, 0, 9);
	//countingsort(a, b, 9, c, 9);
	//countingsort(a1, a2, 9, a3, 39);
	//shellsort(a, 10);

	printarray(a, 10);
	printarray(b, 10);



	//srand((int)time(0));
	//cout << 10*(double)rand() / RAND_MAX << endl;
	system("pause");
	return 0;
}


void printarray(int a[], int length){
	for (int i = 0; i < length; ++i){
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}

//int getlen(int a[]){
//	//此时无法求解数组的长度，因为参数只是一个指针，返回的长度永远为1
//	return sizeof(a) / sizeof(a[0]);
//}


/*将被排序的记录数组R[1..n]垂直排列，每个记录R看作是重量为R.key的气泡。
根据轻气泡不能在重气泡之下的原则，从下往上扫描数组R：凡扫描到违反本
原则的轻气泡，就使其向上"飘浮"。如此反复进行，直到最后任何两个气泡
都是轻者在上，重者在下为止。*/
//length为索引
void bubblesort(int a[], int length){
	for (int i = 0; i <= length; ++i){
		//for (int j = 0; j <= length - i - 1; ++j){
		for (int j = length - 1; j >= i; --j){
			if (a[j + 1] < a[j]){
				//std::swap(a[j + 1], a[j]);
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}



//插入排序，length为索引
void insertsort(int a[], int length){
	int key = 0;
	int j = 0;
	for (int i = 1; i <= length; ++i){
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void insertsort2(int a[], int length){
	int j = 0;
	for (int i = 1; i <= length; ++i){
		int temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; --j){
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void insertsort3(int a[], int length){
	for (int i = 1; i <= length; ++i){
		for (int j = i - 1; j >= 0 && a[j + 1] <= a[j]; --j){
			std::swap(a[j + 1], a[j]);
		}
	}
}

//无法使用，error
//合并数组a的两个已经排好序的子数组a[left,middle]和a[middle+1,right]
//void mergearray(int a[], int left, int right, int middle, int temparray[]){
//	for (int i = left; i <= right; ++i){
//		temparray[i] = a[i];
//		printarray(temparray, 2);
//	}
//	int n1 = left;
//	int n2 = middle + 1;
//	bool leftover = false;
//	bool rightover = false;
//	for (int j = left; j <= right; ++j){
//		if (temparray[n1] <= temparray[n2]){
//			a[j] = temparray[n1];
//			++n1;
//			if (n1 == middle + 1){
//				leftover = true;
//				break;
//			}
//		}
//		else if(temparray[n1] >= temparray[n2]){
//			a[j] = temparray[n2];
//			++n2;
//			if (n2 == right + 1){
//				rightover = true;
//				break;
//			}
//		}
//	}
//	if (leftover){
//		for (int k = n2; k <= right; ++k){
//			a[k] = temparray[k];
//		}
//	}
//	else if (rightover){
//		for (int k = n1; k <= middle; ++k){
//			a[k] = temparray[k];
//		}
//	}
//}

//合并数组a的两个已经排好序的子数组a[left,middle]和a[middle+1,right]
//void mergearray(int a[], int left, int right, int middle, int temparray[]){
//	int i = left;
//	int j = middle + 1;
//	int k = left;
//	while (i <= middle && j <= right){
//		if (a[i] <= a[j]){
//			temparray[k] = a[i];
//			++k;
//			++i;
//		}
//		else{
//			temparray[k] = a[j];
//			++k;
//			++j;
//		}
//	}
//	while (i <= middle){
//		temparray[k] = a[i];
//		++k;
//		++i;
//	}
//	while (j <= right){
//		temparray[k] = a[j];
//		++k;
//		++j;
//	}
//	for (i = left; i <= right; ++i){
//		a[i] = temparray[i];
//	}
//}

//合并数组a的两个已经排好序的子数组a[left,middle]和a[middle+1,right]
void mergearray(int a[], int left, int right, int middle, int temparray[]){
	//将a[left,right]复制到temparray[left,right]中
	for (int n = left; n <= right; ++n){
		temparray[n] = a[n];
	}

	int i = left;
	int j = middle + 1;
	int k = left;
	//依次从temparray[left,middle]和temparray[middle+1,right]中取出最小的值放入a[]中
	while (i <= middle && j <= right){
		if (temparray[i] <= temparray[j]){
			a[k] = temparray[i];
			++k;
			++i;
		}
		else{
			a[k] = temparray[j];
			++k;
			++j;
		}
	}
	//此时至少已经有一半的temparray[]中的数放入了a[]中，现在将剩余的放入a[]中
	while (i <= middle){
		a[k] = temparray[i];
		++k;
		++i;
	}
	while (j <= right){
		a[k] = temparray[j];
		++k;
		++j;
	}
}

void mergesort(int a[], int left, int right, int temparray[]){
	if (left < right){
		int middle = (int)((right + left) / 2);
		mergesort(a, left, middle, temparray);
		mergesort(a, middle + 1, right, temparray);
		mergearray(a, left, right, middle, temparray);
	}
	//printarray(a,10);
}


//返回父节点的索引
int parentnode(int i){
	return (int)((i - 1) / 2);
}
//返回左子节点的索引
int leftnode(int i){
	return 2 * i + 1;
}
//返回右子节点的索引
int rightnode(int i){
	return 2 * i + 2;
}
//a[]为堆，i表示要修正的节点索引，num表示堆栈的长度（索引）
void maxheapify(int a[], int i, int num){
	int left = leftnode(i);
	int right = rightnode(i);
	int max = i;//max用来记录i和其leftnode、rightnode中的最大值的索引
	if (left <= num && a[left] > a[i]){
		max = left;
	}
	if (right <= num && a[right] > a[max]){
		max = right;
	}
	//如果最大值的索引不是i,那么继续递归修正堆的性质
	if (max != i){
		std::swap(a[i], a[max]);//此时只是交换了a[i]和a[max]的值，要被修正的节点放到了索引为max的节点上
		maxheapify(a, max, num);//
	}
}

//建立最大堆
void buildheap(int a[], int num){
	int i = (int)((num + 0) / 2);
	//堆为近似完全二叉树（若为完全二叉树时，叶节点为所有节点个数的一半），a[((num+1)/2)]到a[num]都是叶子节点，都满足最大堆的性质
	for (i; i >= 0; --i){
		maxheapify(a, i, num);
	}
}

//num是数组的最大索引，而不是个数
void heapsort(int a[], int num){
	buildheap(a, num);
	int heaplength = num;
	//将根节点从堆中移除，放到数组的最后面（与堆的最后一个值交换），维护堆的性质；将堆的长度减1继续递归
	for (int i = num; i > 0; --i){
		std::swap(a[0], a[i]);
		--heaplength;
		maxheapify(a, 0, heaplength);
	}
}


//快速排序，将数组划分成三部分（小于某一个值、某值、大于某值），left和right都是索引值
int partition(int a[], int left, int right){
	int key = a[right];
	int i = left;
	for (int j = left; j < right; ++j){
		if (a[j] <= key){
			std::swap(a[i], a[j]);
			++i;
		}
	}
	std::swap(a[i], a[right]);
	return i;
}

void quicksort(int a[], int left, int right){
	if (left < right){
		int middle = partition(a, left, right);
		quicksort(a, left, middle - 1);
		quicksort(a, middle + 1, right);
	}
}


//计数排序：num为a[]和b[]的最大索引；upperbound是a[]中最大的值，但应该定义c[upperbound+1]；
void countingsort(int a[], int b[], int num, int c[], int upperbound){
	//确保c数组全为0
	for (int i = 0; i <= upperbound; ++i){
		c[i] = 0;
	}
	for (int i = 0; i <= num; ++i){
		c[a[i]]++;
	}
	for (int j = 1; j <= upperbound; ++j){
		c[j] += c[j - 1];
	}
	//printarray(c, 10);
	for (int k = 0; k <= num; ++k){
		b[c[a[k]] - 1] = a[k];
		c[a[k]]--;
	}
}


void shellsort(int a[], int n){
	int gap, i, j, temp;
	//步长最开始为总长度的一半，之后依次减半
	for (gap = n / 2; gap >= 1; gap = gap / 2){
		//从第一组的第二个值开始依次往后计算。并不是计算完一个组再计算另一个组，而是先依次计算玩每组的第二个值，
		//再依次计算每组的第三个值，直到最后一个数。（每组都是插入排序）
		for (i = gap; i <= n; i++){
			temp = a[i];
			//对每组的值进行插入排序。此时每组值之间的索引差值为step而不是1
			for (j = i - gap; (j >= 0) && (a[j] > temp); j = j - gap){
				a[j + gap] = a[j];
			}
			a[j + gap] = temp;
		}
	}
}

//void shellsort(int a[], int num){
//	for (int gap = num / 2; gap > 0; gap /= 2){
//		for (int i = 0; i < gap; ++i){
//			for (int j = i + gap; j < num; j += gap){
//				int key = a[j];
//				while (a[j] < a[j - gap] && j - gap >= 0){
//					a[j] = a[j - gap];
//					j -= gap;
//					//a[j+gap] = a[j];
//				}
//				a[j] = key;
//				
//				////反复交换也可以达到插入的目的
//				//while (a[j] < a[j - gap] && j >= 0)
//				//std::swap(a[j], a[j - gap]);
//			}
//		}
//	}
//}

//void test(int a[], int m, int b[], int n, ){
//	int *p = new int[m + n];
//
//}

