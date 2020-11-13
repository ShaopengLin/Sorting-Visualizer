#ifndef _functionPrototypes_h_
#define _functionPrototypes_h_

#include <iostream>
#include <apvector.h>
#include <time.h>
#include <string>
#include <apstring.h>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

#define SCREENWIDTH 1300
#define SCREENHEIGHT 700
#define DEFAULTSIZE 200
using namespace std;
extern ALLEGRO_FONT *farry;
extern ALLEGRO_FONT *farry64;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
int initializeAllegro();
void drawInterface();
bool hitboxQuick(ALLEGRO_MOUSE_STATE mouState);
bool hitboxMerge(ALLEGRO_MOUSE_STATE mouState);
bool hitboxSelection(ALLEGRO_MOUSE_STATE mouState);
bool hitboxReturn(ALLEGRO_MOUSE_STATE mouState);
bool hitboxNewData(ALLEGRO_MOUSE_STATE mouState);
#endif // _functionPrototypes_h_
