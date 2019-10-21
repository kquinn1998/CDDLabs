
#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <complex>      /* complex number data type */
#include <time.h>       /* time */
#include <functional>  /* function type */
#include <limits>
#include <vector>      /* vectors used instead of arrays */

using namespace std ;


const int LENGTH=10;





//template <typename T>
int partition (vector<int>& myArray , int low , int high ){
  int pivot=myArray[high];
  int k=high;
  int i=low;
  int temp=0;
  while (i<k){
    while (myArray[i]<pivot && i<k)++i;
    while (myArray[k]>pivot && i<k)--k;
    if (i<k){
      //cout<<"swapping" << myArray[i] <<" and " <<myArray[k]<<endl;
      temp=myArray[i];
      myArray[i]=myArray[k];
      myArray[k]=temp;
      i++;k--;
    }
  }
  return i;
}

//template<typename T>
/**
 * @brief quicksort
 * @param myArray
 * @param low
 * @param high
 * @return
 */
int quicksort(vector<int>& myArray , int low , int high ){
  if (low<high){
    int pivot=partition(myArray,low,high);
    //really we should only do this if each partition is above a certain size (1000 elements?)
    //otherwise the overhead outweighs any gains from using threads
    //#pragma omp task shared(myArray)
    quicksort(myArray,low,pivot);
    quicksort(myArray,pivot+1,high);
    //#pragma omp taskwait
  return 1;
  }
}//quicksort

//int main(int argc, char *argv[])
//{
  //  QCoreApplication a(argc, argv);

    //return a.exec();
//}

int main(void){
  srand (time(NULL));
  vector<int> data={85, 603, 307, 885, 297, 257, 168, 709, 654, 362 };
  // for(auto& value:data){
  //  value=rand()%1000;
  //}
  for(auto& value:data){
    cout<<value<<" ";
  }
  cout << endl<<"*******************************"<<endl;
  quicksort(data,0,data.size()-1);
  for(auto& value:data){
    cout<<value<<" ";
  }
  cout << endl;
}
//
// quicksort.cpp ends here
