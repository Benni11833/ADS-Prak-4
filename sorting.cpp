#include "sorting.h"

namespace sorting {

	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right) {

		if(left < right){
			int mid = partition(arr, left, right);
			QuickSort(arr, left, mid-1);
			QuickSort(arr, mid+1, right);
		}

	}

void swap(int &val1, int &val2){
	int tmp{val1};	val1 = val2;	val2 = tmp;
}

int partition(std::vector<int>& arr, int left, int right){
	if (right == arr.size())
		--right;
		int x = arr[right];
		int i = left-1;
		for(int j=left; j <= right-1; j++){
			if(arr[j] <= x){
				++i;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i+1], arr[right]);
		return i+1;
	}

	//************
	// MergeSort *
	//************

	void Merge(vector<int> &a, vector<int> &b, int low, int pivot, int high) {
		int n1{pivot-low};
		if(high == a.size())
			--high;
		b.clear();	b.resize(high-low+1);
		for(int i=0; i < b.size(); i++){
			b[i] = a[low+i];
		}

		//einsortieren aus tmp in a
		int i{0}, j{n1+1}, k{low};
		for(k=low; k < high; k++){
			if(i <= n1 && j <= high - low && b[i] <= b[j]){
				a[k] = b[i++];
			}
			else if(j <= high-low){
				a[k] = b[j++];
			}
			else
				break;
		}

		//reste in TeilArrays in a einsortieren
		while(i <= n1 && k <= high)
			a[k++] = b[i++];
		while(j < high-low && k < high)
			a[k++] = b[j++];
	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high) {
		if(low < high){
			int q = (low+high)/2;
			MergeSort(a, b, low, q);
			MergeSort(a, b, q+1, high);
			Merge(a, b, low, q, high);
		}
	}

	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a, int n) {
		int i=n/2;
		while(i >= 0){
			percUp(a, i, n);
			--i;
		}
		int j = n-1;
		while(j > 0){
			swap(a[0], a[j]);
			percUp(a, 0, j);
			--j;
		}
	}

	void percUp(vector<int> &a, int i, int n){
		//Tauscht Max in Kindern mit Wurzel(i), falls groesser
		if(2*i+2 < n && a[2*i+2] >= a[2*i+1] && a[2*i+2] > a[i]){
			swap(a[2*i+2], a[i]);
			percUp(a, 2*i+2, n);	//rekursiv Teilbaum percUppen, da geändert(evtl neues Max)
		}else if(2*i+2 < n && a[2*i+1] > a[2*i+2] && a[2*i+1] > a[i]){
			swap(a[2*i+1], a[i]);
			percUp(a, 2*i+1, n);	//s. oben
		}else if(2*i+1 < n && a[2*i+1] > a[i]){	//wenn nur linken nachfolger, tauschen wenn groesser
			swap(a[2*i+1], a[i]);
			percUp(a, 2*i+1, n);	//s. oben
		}
	}

	//************
	// Shellsort *
	//************
	/*void ShellSort(vector<int> &a, int n)
	{
		for (int h = n / 2; h > 0; h /= 2) {
			for (int i = h; i < n; i++) {
				int tmp = a[i];
				int j{ i };
				for (; j >= h && tmp < a[j - h]; j -= h) {
					a[j] = a[j - h];
				}
				a[j] = tmp;
			}
		}
	}*/
	void ShellSort(vector<int> &a, int n)
	{
		for (int h = 1; h < n; h = 2*h+1) {
			for (int i = h; i < n; i++) {
				int tmp = a[i];
				int j{ i };
				for (; j >= h && tmp < a[j - h]; j -= h) {
					a[j] = a[j - h];
				}
				a[j] = tmp;
			}
		}
	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}