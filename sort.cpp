#include "sort.h"
#include <apstring.cpp>
///default constructor with a list of 200 integers
Sort::Sort()
{
    //initialize variables
    moves = 0;
    comparisons = 0;
    start = 0;
    duration = 0;
    memoryUse = 0;
    //default size is 200
    numList.resize(DEFAULTSIZE);
    //set all indexes value to -1 for value assignment
    for (int i = 0; i < numList.length(); i++) {
        numList[i] = -1;
    }
    //put integers 1-200 into random locations in the list
    for (int i = 1; i <= numList.length(); i++) {
        int index = rand()%numList.length();
        while (numList[index] != -1) {
            index = rand()%numList.length();
        }
        numList[index] = i;
    }
    //create a backup for reuse
    reserveList.resize(DEFAULTSIZE);
    reserveList = numList;
}
///constructor when user inputs list length
Sort::Sort(int length)
{
    //initialize variables
    moves = 0;
    comparisons = 0;
    start = 0;
    duration = 0;
    memoryUse = 0;
    //set to user defined size
    numList.resize(length);
    //set all indexes value to -1 for value assignment
    for (int i = 0; i < length; i++) {
        numList[i] = -1;
    }
    //put integers 1-length into random locations in the list
    for (int i = 1; i <= length; i++) {
        int index = rand()%length;
        while (numList[index] != -1) {
            index = rand()%length;
        }
        numList[index] = i;
    }
    //create a backup for reuse
    reserveList.resize(length);
    reserveList = numList;
}
///destructor
Sort::~Sort()
{
}
///helps draws sorting processes in each sort
void Sort::drawBars(int movementPos)
{
    al_clear_to_color(al_map_rgb(0,0,0));
    //draw the bars
    for (int i = 0; i < numList.length(); i++) {
        al_draw_filled_rectangle(i*1.0*SCREENWIDTH/numList.length(), SCREENHEIGHT, (i+1)*1.0*SCREENWIDTH/numList.length(), SCREENHEIGHT-numList[i]*500/numList.length(), al_map_rgb(255,255,255));
    }
    //draw the red line #progress
    al_draw_filled_rectangle(movementPos*1.0*SCREENWIDTH/numList.length(), SCREENHEIGHT, (movementPos+3)*1.0*SCREENWIDTH/numList.length(), SCREENHEIGHT-numList[movementPos]*500/numList.length(), al_map_rgb(255,0,0));
    drawTime();
    drawComparisons();
    drawMoves();
    drawMemoryUse();
    drawReturnButton();
    al_flip_display();
}
///merges two part of the list together in order
void Sort::mergeList(int left, int mid, int right)
{
    int indexInNumList = left;
    int indexListOne = 0;
    int indexListTwo = 0;
    //create a list for the left half
    apvector<int> listOne(mid - left+1);
    for (int i = 0; i < listOne.length(); i++) {
        listOne[i] = numList[left+i];
    }
    //create a list for the right half
    apvector<int> listTwo(right-mid);
    for (int i = 0; i < listTwo.length(); i++) {
        listTwo[i] = numList[mid+1+i];
    }
    comparisons++;
    drawBars(indexInNumList);
    //if one of the list is still unsorted
    while (listOne.length() != indexListOne || listTwo.length() != indexListTwo) {
        drawBars(indexInNumList);
        //if one list is sorted, move the rest of the other list into the actual list
        if (comparisons++ && listOne.length() == indexListOne) {
            moves++;
            numList[indexInNumList++] = listTwo[indexListTwo++];
        } else if (comparisons++ && listTwo.length() == indexListTwo) {
            moves++;
            numList[indexInNumList++] = listOne[indexListOne++];
        } else {
            drawBars(indexInNumList);
            //moves the smaller variable in the two lists into the actual list
            if (listOne[indexListOne] <= listTwo[indexListTwo]) {
                moves++;
                numList[indexInNumList++] = listOne[indexListOne++];
            } else {
                moves++;
                numList[indexInNumList++] = listTwo[indexListTwo++];
            }
        }
        drawBars(indexInNumList-1);
        comparisons++;
    }
}
///recursion for merge sort
void Sort::mergeSort(int left, int right)
{
    //base case: if there is only one variable to sort, starts to go back
    if (left < right) {
        //finds mid point
        int midInt = (right - left)/2 + left;
        //sort the left half
        mergeSort(left, midInt);
        //sort the right half
        mergeSort(midInt+1, right);
        //merge the two halves
        mergeList(left, midInt, right);
    }
}
///quick sort method for a given part of the list
int Sort::partitions(int left, int right)
{

    //This is the pseudo code from a website that I altered, it goes from left to right and move all the small element to the left
    /*int indexSmallerNum = left;
    for (; left < right; left++){
        drawBars(indexSmallerNum);
        comparisons++;
        if (numList[left] <= numList[right]){
            moves++;
            swapNum(indexSmallerNum++, left);
        }
    }
    moves++;
    swapNum(indexSmallerNum, right);
    drawBars(indexSmallerNum);
    return indexSmallerNum;*/
    //This is my own code that sorts from right to left and left to right at the same time.
    //last index as pivots
    int indexRight = right -1 ;
    for (; left <= indexRight; left++) {
        drawBars(left);
        comparisons++;
        //swaps the index if the left element is bigger than pivot and right element is smaller the pivot
        if (numList[left] > numList[right] && numList[indexRight] < numList[right]) {
            moves++;
            swapNum(indexRight--, left);
            drawBars(left);
        } else {
            drawBars(left);
            comparisons += 2;
            //if index right is bigger than pivot which does not fit the swapping criteria, move on to the next element
            if (numList[indexRight] >= numList[right]) {
                indexRight--;
            }
            drawBars(left);
            //if index left fits the swapping criteria, the index minus to be able to stay the same in the next iteration
            if (numList[left] > numList[right]) {
                left--;
            }
        }

    }
    moves++;
    //swaps the pivot with the left
    swapNum(left, right);
    drawBars(left);
    return left;
}
///quick sort iteration
void Sort::quickSort(int left, int right)
{
    if (left < right) {
        //find the pivot and sort the list from left part and right part
        int pivot = partitions(left, right);
        //sort left half
        quickSort(left, pivot-1);
        //sort right half
        quickSort(pivot+1, right);
    }
}
///swap position of two numbers in the number list
void Sort::swapNum(int index1, int index2)
{
    int temp = numList[index1];
    numList[index1] = numList[index2];
    numList[index2] = temp;
}
///uses repetition to selectively sort the number list
void Sort::selectionSort()
{
    int smallestIndex;
    //finds the smallest element
    for (int i = 0; i < numList.length(); i++) {
        smallestIndex = i;
        for (int j = i+1; j < numList.length(); j++) {
            comparisons++;
            if (numList[j] < numList[smallestIndex]) {
                smallestIndex = j;
            }
            drawBars(j);
        }
        moves++;
        //swaps the smallest element to its right position
        swapNum(i, smallestIndex);
        drawBars(i);
    }
}
///resets the list and other variables for reuse purpose
void Sort::resetList()
{
    numList = reserveList;
    moves = 0;
    comparisons = 0;
    duration = 0;
    memoryUse = 0;
}
///calculates and draws the time used for each sort
void Sort::drawTime()
{
    apstring text = "Time: ";
    //calculates current time
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    text += to_string(duration).c_str();
    text += " s";
    //draws time
    al_draw_text(farry, al_map_rgb(255,255,255), 0, 0, NULL, text.c_str());
}
///draws the number of comparisons of the sort
void Sort::drawComparisons()
{
    apstring text = "Comparisons: ";
    text += to_string(comparisons).c_str();
    al_draw_text(farry, al_map_rgb(255,255,255), SCREENWIDTH/4, 0, NULL, text.c_str());
}
///draws the number of moves the sort took
void Sort::drawMoves()
{
    apstring text = "Moves: ";
    text += to_string(moves).c_str();
    al_draw_text(farry, al_map_rgb(255,255,255), SCREENWIDTH/2, 0, NULL, text.c_str());
}
///draws the memory use of the sort
void Sort::drawMemoryUse()
{
    apstring text = "MemoryUsage: ";
    text += to_string(memoryUse).c_str();
    text += " bytes";
    al_draw_text(farry, al_map_rgb(255,255,255), SCREENWIDTH*2.7/4, 0, NULL, text.c_str());
}
///Merge sort only, calculates the memory Use of the sort in ybtes
void Sort::setMemoryUse()
{
    for (int i = 0; i < numList.length(); i++) {
        memoryUse += sizeof(numList[i]);
    }
}
///draws the return button
void Sort::drawReturnButton()
{
    al_draw_triangle(0,75,45,55,45,95,al_map_rgb(255,255,255), 2);
    al_draw_rounded_rectangle(0,50, 50, 100, 10,10, al_map_rgb(255,255,255), 1);
}
///creates a new set of data for the sorts
void Sort::newData(){
    //set all indexes value to -1 for value assignment
    for (int i = 0; i < numList.length(); i++) {
        numList[i] = -1;
    }
    //put integers 1-number list length into random locations in the list
    for (int i = 1; i <= numList.length(); i++) {
        int index = rand()%numList.length();
        while (numList[index] != -1) {
            index = rand()%numList.length();
        }
        numList[index] = i;
    }
    //backup
    reserveList = numList;
}
