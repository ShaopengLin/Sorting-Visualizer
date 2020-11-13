#include "functionPrototypes.h"
//initialize Allegro functions
int initializeAllegro()
{
    // Initialize Allegro
    al_init();

    // initialize display
    display = al_create_display(SCREENWIDTH,SCREENHEIGHT);
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    al_set_window_title(display, "Graphical Sorting");
    // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // need to add image processor
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // Add fonts
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    //fonts
    farry = al_load_ttf_font("FARRAY.otf", 24, NULL);
    farry64 = al_load_ttf_font("FARRAY.otf", 64, NULL);
    // Initialize primative add on
    if (!al_init_primitives_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // set up event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }
    al_install_mouse();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    return 0;
}

//draws the interface
void drawInterface()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    //draws the title
    al_draw_text(farry64, al_map_rgb(255,255,255), SCREENWIDTH/2,SCREENHEIGHT/6, ALLEGRO_ALIGN_CENTER, "Graphical Sorting");
    //draws the name of the sorts
    al_draw_text(farry, al_map_rgb(0,255,0), (SCREENWIDTH/4+SCREENWIDTH/8)/2,SCREENHEIGHT/2+SCREENHEIGHT/8-12, ALLEGRO_ALIGN_CENTER, "Quick Sort");
    al_draw_text(farry, al_map_rgb(0,0,255), SCREENWIDTH/2,SCREENHEIGHT/2+SCREENHEIGHT/8-12, ALLEGRO_ALIGN_CENTER, "Merge Sort");
    al_draw_text(farry, al_map_rgb(255,0,0), SCREENWIDTH/4*2+SCREENWIDTH/16*3+(SCREENWIDTH/4)/2,SCREENHEIGHT/2+SCREENHEIGHT/8-12, ALLEGRO_ALIGN_CENTER, "Selectio Sort");
    al_draw_text(farry,  al_map_rgb(0,255,255), SCREENWIDTH/2,SCREENHEIGHT/2+SCREENHEIGHT/3, ALLEGRO_ALIGN_CENTER, "New Set");
    //draws the buttons for the quick sort
    al_draw_rounded_rectangle(SCREENWIDTH/16, SCREENHEIGHT/2, SCREENWIDTH/4+SCREENWIDTH/16, SCREENHEIGHT/4*3, 10,10,al_map_rgb(255,255,255), 1 );
    al_draw_rounded_rectangle(SCREENWIDTH/4+SCREENWIDTH/16*2, SCREENHEIGHT/2, SCREENWIDTH/4*2+SCREENWIDTH/16*2, SCREENHEIGHT/4*3, 10,10,al_map_rgb(255,255,255), 1 );
    al_draw_rounded_rectangle(SCREENWIDTH/4*2+SCREENWIDTH/16*3, SCREENHEIGHT/2, SCREENWIDTH/4*3+SCREENWIDTH/16*3, SCREENHEIGHT/4*3, 10,10,al_map_rgb(255,255,255), 1 );
    al_draw_rounded_rectangle(SCREENWIDTH/2-SCREENWIDTH/16, SCREENHEIGHT/2+SCREENHEIGHT/3, SCREENWIDTH/2+SCREENWIDTH/16, SCREENHEIGHT/2+SCREENHEIGHT/3+32, 10,10,al_map_rgb(255,255,255), 1 );
    al_flip_display();
}
