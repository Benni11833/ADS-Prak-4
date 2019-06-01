#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "sorting.h"
#include "hashtable.h"

#include <algorithm>

#define CATCH_CONFIG_RUNNER
#include "catch.h"

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

enum Algorithms{ quicksort, mergesort, heapsort, shellsort};

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

bool writeData(const char* filename, unsigned long start, unsigned int step, unsigned long stop, Algorithms algorithm){
    std::ofstream outFile;
    outFile.open(filename);
    if(!outFile.is_open()){
        std::cerr << "Datei \"" << filename << "\" konnte nicht geoeffnet werden.\n";
        return false;
    }
    Timer t1;
    std::vector<int> sort_vec;
    while(start <= stop){
        std::cout << "Starte sortieren fuer " << start << " Elemente.\n";
    sort_vec.resize(start);
    sorting::randomizeVector(sort_vec, start);
    if(algorithm == Algorithms::quicksort){
        //QuickSort:
        t1.reset();
        sorting::QuickSort(sort_vec, 0, start);
    }else if(algorithm == Algorithms::mergesort){
        //MergeSort:
        vector<int> x;
        t1.reset();
        sorting::MergeSort(sort_vec, x, 0, start);
    }else if(algorithm == Algorithms::heapsort){
        //HeapSort:
        t1.reset();
        sorting::HeapSort(sort_vec, start);
    }else if(algorithm == Algorithms::shellsort){
        //ShellSort:
        t1.reset();
        sorting::ShellSort(sort_vec, start);
    }
    outFile << start << '\t' << t1.getDuration() << std::endl;
    start += step;
    };
    outFile.close();
    std::cerr << "Datei \"" << filename << "\" wurde erfolgreich beschrieben.\n";
    return true;
}

int main(int argc, char* argv[]){

    //UnitTests:
    /*Catch::Session().run();
	system("pause");
    */


    /*long unsigned int N{0L};
    if(argc == 1){
        std::cout << "Anz der Elemente: ";
        std::cin >> N;
    }else{
        N = atol(argv[1]);
    }
    std::cout << "Starte Sortieren mit " << N << " Elementen.\n";
    quicksort, mergesort, heapsort, shellsort*/
    writeData("quickSort.txt", 1000, 1000, 100000, Algorithms::quicksort);
    writeData("mergesort.txt", 1000, 1000, 100000, Algorithms::mergesort);
    writeData("heapsort.txt", 1000, 1000, 100000, Algorithms::heapsort);
    writeData("shellsort.txt", 1000, 1000, 100000, Algorithms::shellsort);
    /*Timer t1;
    std::vector<int> rnd_vec;
    std::vector<int> sort_vec;
    sort_vec.resize(N);
    rnd_vec.resize(N);
    sorting::randomizeVector(rnd_vec, N);
    sort_vec = rnd_vec;

    //Heap-Sort
    sort_vec = rnd_vec;
    t1.reset();
    sorting::HeapSort(sort_vec, sort_vec.size());
    std::cout << "HeapSort lief " << t1.getDuration() << " Sekunden.\n";

	sort_vec = rnd_vec;
	t1.reset();
    sorting::QuickSort(sort_vec, 0, sort_vec.size());
    std::cout << "Quicksort lief " << t1.getDuration() << " Sekunden\n";
    
	sort_vec = rnd_vec;
	t1.reset();
	sort(sort_vec.begin(), sort_vec.end());
	std::cout << "sort lief " << t1.getDuration() << " Sekunden\n";

	sort_vec = rnd_vec;
    vector<int> x;
	t1.reset();
    sorting::MergeSort(sort_vec, x, 0, sort_vec.size());
    std::cout << "Mergesort lief " << t1.getDuration() << " Sekunden\n";
	
	sort_vec = rnd_vec;
	t1.reset();
	sorting::ShellSort(sort_vec, sort_vec.size());
	std::cout << "Shellsort lief " << t1.getDuration() << " Sekunden." << std::endl;
	//system("Pause");*/
    return 0;
}

/*TODO
vec mit obergrenzen, von da aus mit schleife in sort_vec reinkopieren?
->Messzeiten in TextDatei anzeigen
2. Teil HashTable
 */