//Chris Lin   ICS4U   Lindsay Cullum  June 10, 2019
//The program sorts the a random piece of data with three different methods
//and visualize it.
#include "sort.h"
#include "functionPrototypes.h"
ALLEGRO_FONT *farry;
ALLEGRO_FONT *farry64;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;

int main()
{
    double duration;
    std::clock_t start;
    srand(time(0));
    //initialize allegro
    initializeAllegro();
    //create object
    Sort numberList;
    bool returnToInter = true;
    while (true) {
        //start events
        ALLEGRO_EVENT events;
        ALLEGRO_MOUSE_STATE mouState;
        al_get_mouse_state(&mouState);
        al_wait_for_event(event_queue, &events);
        //close program
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            //destroy objects
            al_destroy_font(farry64);
            al_destroy_font(farry);
            al_destroy_event_queue(event_queue);
            al_destroy_display(display);
            return 0;
        }
        //check if the user want to return to the menu
        if (!returnToInter) {
            if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP & 1) {
                if (hitboxReturn(mouState)) {
                    returnToInter = true;
                }
            }
        }
        //draws the user interface
        if (returnToInter) {
            drawInterface();
            if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP & 1) {
                //if clicked quick sort button draw quick sort
                if (hitboxQuick(mouState)) {
                    //start timer
                    numberList.startTimer();
                    //draws the quick sort process
                    numberList.quickSort(0, numberList.getNumList().length()-1);
                    //fixate the position of the red line to the right
                    numberList.drawBars(numberList.getNumList().length()-1);
                    //reset the list for future use
                    numberList.resetList();
                    //does not automatically returns to the menu
                    returnToInter = false;
                }
                //if clicked merge sort button draw merge sort
                else if(hitboxMerge(mouState)) {
                    //the sort uses extra memory locations
                    numberList.setMemoryUse();
                    //start timer
                    numberList.startTimer();
                    //draws the merge sort process
                    numberList.mergeSort(0, numberList.getNumList().length()-1);
                    //fixate the position of red line to the right
                    numberList.drawBars(numberList.getNumList().length()-1);
                    //resets the list for future use
                    numberList.resetList();
                    //does not automatically returns to the menu
                    returnToInter = false;
                }
                //if clicked selection sort draw selection sort
                else if(hitboxSelection(mouState)) {
                    numberList.startTimer();
                    //draws the selection sort process
                    numberList.selectionSort();
                    //fixate the position of red line to the right
                    numberList.drawBars(numberList.getNumList().length()-1);
                    //resets the list for future use
                    numberList.resetList();
                    //does not automatically returns to the menu
                    returnToInter = false;
                }
                //if clicked creates a new set of data for sorting
                else if(hitboxNewData(mouState)){
                    numberList.newData();
                }
            }
        }
    }
    //destroy objects
    al_destroy_font(farry64);
    al_destroy_font(farry);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    return 0;
}

