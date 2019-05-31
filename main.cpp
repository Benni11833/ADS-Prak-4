#include <iostream>
#include <iomanip>
#include <chrono>
#include "sorting.h"

#define NumbersInLine 8

void Print_Vec(std::vector<int>& arr){
    std::cout << std::endl << std::endl;
    for(int i=0; i < arr.size(); i++){
        if( i != 0 && i%NumbersInLine == 0)
            std::cout << std::endl;
        std::cout << std::setw(10) << std::left << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

struct Timer{
    //std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

   Timer(){
         start = std::chrono::high_resolution_clock::now();
   }
   void reset(){
       start = std::chrono::high_resolution_clock::now();
   }
   auto getDuration(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        return duration.count();
   }
   void printDuration(){
       end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Timer lief " << duration.count() << " Sekunden" << std::endl;
   }
   /*~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Timer lief " << duration.count() << " Sekunden" << std::endl;
   }*/
};

int main(int argc, char* argv[]){
    long unsigned int N{0L};
    if(argc == 1){
        std::cout << "Anz der Elemente: ";
        std::cin >> N;
    }else{
        N = atol(argv[1]);
    }
    std::cout << "Starte Sortieren mit " << N << " Elementen.\n";
    Timer t1;
    std::vector<int> rnd_vec;
    std::vector<int> sort_vec;
    sort_vec.resize(N);
    rnd_vec.resize(N);
    sorting::randomizeVector(rnd_vec, N);
    sort_vec = rnd_vec;
	/*std::cout << "Unsorted:\n";
	Print_Vec(sort_vec);
    */t1.reset();
    sorting::QuickSort(sort_vec, 0, sort_vec.size());
    std::cout << "Quicksort lief " << t1.getDuration() << " Sekunden\n";
	/*std::cout << "QuickSorted:\n";
	Print_Vec(sort_vec);*/
    
    sort_vec = rnd_vec;
    /*sort_vec.resize(5);
    sort_vec[0] = 1; sort_vec[1] = 7; 
    sort_vec[2] = 3; sort_vec[3] = 5;
    sort_vec[4] = 2;*/
    //Print_Vec(sort_vec);
    t1.reset();
    vector<int> x;
    sorting::MergeSort(sort_vec, x, 0, sort_vec.size());
    std::cout << "Mergesort lief " << t1.getDuration() << " Sekunden\n";
    /*std::cout << std::endl << "MergeSorted:\n";
    Print_Vec(sort_vec);*/
	system("Pause");
    return 0;
}

/*TODO
Shellsort (Hibbard Folge)
HeapSort
->Messzeiten in TextDatei anzeigen
 */