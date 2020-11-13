#ifndef _sort_h_
#define _sort_h_
#include "functionPrototypes.h"
class Sort
{
private:
    int moves;
    int comparisons;
    int memoryUse;
    double start;
    double duration;
    apvector<int> reserveList;
    apvector<int> numList;
public:
    Sort();
    Sort(int length);
    ~Sort();
    void mergeSort(int minimum, int maximum);
    void mergeList(int left, int mid, int right);
    void quickSort(int left, int right);
    int partitions(int left, int right);
    void swapNum(int index1, int index2);
    void selectionSort();
    void drawBars(int movementPos);
    ///get the current number list in the class
    apvector<int> getNumList()
    {
        return numList;
    }
    void resetList();
    ///starts the timer
    void startTimer()
    {
        start = std::clock();
    }
    void drawTime();
    void drawComparisons();
    void drawMoves();
    void drawMemoryUse();
    void setMemoryUse();
    void drawReturnButton();
    void newData();
};
#endif // _sort_h_
