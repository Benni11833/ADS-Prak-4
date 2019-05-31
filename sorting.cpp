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
		
		/*std::cout << "TestAusgabe:\n\n";
		std::cout << "a[low-high]:\n";
		for(int i=low; i < high; i++)
			std::cout << a[i] << ",";
		std::cout << std::endl << "tmp[0-(high-low):\n";
		for(int i=0; i < b.size(); i++)
			std::cout << b[i] << ",";
		std::cout << std::endl << std::endl;
		std::cout << "sollen gleich sein: " << a[pivot] << " - " << b[pivot-low] << std::endl;
		std::cin.get();*/

		/*std::cout << "low=" << low << " - piv=" << pivot << " - high="
		<< high  << " - n1=" << n1 << std::endl;
		std::cout << std::endl << "tmp[0-(high-low):\n";
		for(int i=0; i < b.size(); i++)
			std::cout << b[i] << ",";
		std::cout << std::endl;*/

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
		
		/*std::cout << "TestAusgabe:\n\n";
		std::cout << "a[low-high]:\n";
		for(int i=low; i <= high; i++)
			std::cout << a[i] << ",";
		std::cout << std::endl << "a[ges]:\n";
		for(int i=0; i < a.size(); i++)
			std::cout << a[i] << ",";
		std::cin.get();*/
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


		//***************************
		// implement heapsort here *
		//***************************

	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{
		int h{ (n + 1) / 2 };
		while (h >= 1) {
			for (int i = 0; i < n; i++)
				if (i+h < n && a[i] < a[(i + h)])
					swap(a[i], a[i + h]);
			h /= 2;
		}
	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





