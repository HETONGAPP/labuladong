
//           平均时间复杂度	最好情况	最坏情况	空间复杂度	    稳定性
// 冒泡排序	       O(n²)	O(n)	    O(n²)	     O(1)	      稳定   Bubble Sort
// 选择排序	       O(n²)	O(n²)	    O(n²)	     O(1)	     不稳定  selection sort
// 插入排序	       O(n²)	O(n)	    O(n²)	     O(1)	      稳定   Insertion sort
// 希尔排序	      O(nlogn)	O(n1.3)	    O(n²)	     O(1)	     不稳定  Hill sort
// 归并排序	      O(nlogn)	O(nlogn)	O(nlogn)	O(n + logn)	  稳定   Merge sort
// 快速排序	      O(nlogn)	O(nlogn)	O(n²)	    O(logn)	     不稳定  Quicksort 
// 堆排序	      O(nlogn)	O(nlogn)	O(nlogn)	O(1)	     不稳定  Heapsort 
// 桶排序	      O(n + k)	O(n + k)	O(n²)	    O(n + k)	  稳定   bucket sort
// 计数排序	      O(n + k)	O(n + k)	O(n + k)	O(k)	      稳定   Counting sort
// 基数排序	      O(n × m)	O(n × m)	O(n × m)	O(n + m)	  稳定   Radix sort


//冒泡排序
void bubbleSort(vector<int>& v){
    int n = v.size();
    for(int i =0; i<n-1; ++i)
    {
        for (int j = 0; j < n-i-1; ++j)
        {
            if(v[j]>v[j+1])
                swap(v[j], v[j+1]);
        }
    }
}

//选择排序
void selectSort(vector<int>& v){
    int n = v.size();
    for (int i = 0; i < n-1; i++)
    {
        int index = 0;
        for (int j = 1; j < n-i; j++)
        {
           if(v[j]>v[index]) index = j;
        }
        swap(v[index],v[n-1-i]);
    }
    
}

//插入排序
void insertSort(vector<int>& v){
    int n = v.size();
    for (int i = 1; i < n-1; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if(v[j]<v[j-1])
                swap(v[j],v[j-1]);
        }
        else
            break;
    }
}

//快速排序 
void quick_Sort(vector<int>& v, int left, int right){
    if(left>=right) return;

    int i = left, j = right, bas = v[left];
    while(i<j)
    {
        while(v[j]>=base && i<j) --j;
        while(v[i]<=base && i < j) ++i;
        if(i<j) swap(v[i],v[j]);
    }
    v[left] = v[i];
    v[i] = base;
    quick_Sort(v,left,i-1);
    quick_Sort(v, i+1,right);
} 



//并轨排序
void merge(vector<int>& v, int left, int mid, int right){
	vector<int> temp = v;
	int i = left, j = mid + 1;
	int index = left;
	while(i <= mid || j <= right){
		if(i > mid){
			v[index++] = temp[j];
			j++;
		}
		else if(j > right){
			v[index++] = temp[i];
			i++;
		}
		else if(temp[i] < temp[j]){
			v[index++] = temp[i];
			i++;
		}
		else{
			v[index++] = temp[j];
			j++;
		}
	}
	
}
void merge_Sort(vector<int>& v, int left, int right){
	if(left >= right) return;
	int mid = (left + right) / 2;
	merge_Sort(v, left, mid);
	merge_Sort(v, mid + 1, right);
	if(v[mid] > v[mid + 1]){
		merge(v, left, mid, right);
	}
}