//Including the other files
#include "Headers.h"
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_BITMAP *Table;
extern ALLEGRO_BITMAP *Dummy;
extern ALLEGRO_BITMAP *Player;
extern ALLEGRO_BITMAP *Dummyfires;
extern ALLEGRO_BITMAP *Dummyflash;
extern ALLEGRO_BITMAP *Playerfires;
extern ALLEGRO_BITMAP *Playerflash;
extern ALLEGRO_BITMAP *Buttons;
extern ALLEGRO_BITMAP *PlayerSelf1;
extern ALLEGRO_BITMAP *PlayerSelf2;
extern ALLEGRO_BITMAP *PlayerSelf3;
extern ALLEGRO_BITMAP *Shop;
extern ALLEGRO_BITMAP *BlankBulletCounter;
extern ALLEGRO_BITMAP *FullBulletCounter;
extern ALLEGRO_BITMAP *IndividualBulletForCounter;
extern ALLEGRO_BITMAP *InventoryButton;
extern ALLEGRO_BITMAP *ShopButton;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT eventOrder;
extern ALLEGRO_BITMAP *HealthBar1;
extern ALLEGRO_BITMAP *HealthBar2;
extern ALLEGRO_BITMAP *HealthBar3;
extern ALLEGRO_BITMAP *HealthBar4;
extern ALLEGRO_BITMAP *HealthBar5;
extern ALLEGRO_BITMAP *Zero;
extern ALLEGRO_BITMAP *One;
extern ALLEGRO_BITMAP *Two;
extern ALLEGRO_BITMAP *Three;
extern ALLEGRO_BITMAP *Four;
extern ALLEGRO_BITMAP *Five;
extern ALLEGRO_BITMAP *Six;
extern ALLEGRO_BITMAP *Seven;
extern ALLEGRO_BITMAP *Eight;
extern ALLEGRO_BITMAP *Nine;
extern ALLEGRO_BITMAP *Ball;
extern ALLEGRO_BITMAP *BallEmpty;
extern ALLEGRO_BITMAP *OpHeart;
extern ALLEGRO_BITMAP *ShootSelfButton;
extern ALLEGRO_BITMAP *ShootOpButton;

ALLEGRO_EVENT ButtonEvent;

extern int OpX;
extern int OpY;
extern int currentOp;



int AllegroMain() {
	// Initialize Allegro

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
 	al_set_window_title(display, "PaintBall Roulette");

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare the bitmaps setting it's initial value to nullptr


    // Create a display
    // Load the background image
    Table = al_load_bitmap("ImageFile\\Table.png");
    Dummy = al_load_bitmap("ImageFile\\Dummy.png");
    Player = al_load_bitmap("ImageFile\\Player.png");
    Dummyfires = al_load_bitmap("ImageFile\\Dummyshoot.png");
    Dummyflash = al_load_bitmap("ImageFile\\DummyFlash.png");
    Playerfires = al_load_bitmap("ImageFile\\PlayerGun.png");
    Playerflash = al_load_bitmap("ImageFile\\PlayerFlash.png");
    Buttons = al_load_bitmap("ImageFile\\buttons.png");
    PlayerSelf1 = al_load_bitmap("ImageFile\\PlayerPrepareShootSelf.png");
    PlayerSelf2 = al_load_bitmap("ImageFile\\PlayerShootSelf.png");
    PlayerSelf3 = al_load_bitmap("ImageFile\\PlayerShootSelfOof.png");
    Shop = al_load_bitmap("ImageFile\\Shop.png");
    IndividualBulletForCounter = al_load_bitmap("ImageFile\\Bulletcounter.png");
    FullBulletCounter = al_load_bitmap("ImageFile\\Bulletcounterfull.png");
    BlankBulletCounter = al_load_bitmap("ImageFile\\Bulletcount.png");
    InventoryButton = al_load_bitmap("ImageFile\\InventoryButton.png");
    ShopButton = al_load_bitmap("ImageFile\\ShopButton.png");
    HealthBar1 = al_load_bitmap("ImageFile\\FullHealthBar.png");
    HealthBar2 = al_load_bitmap("ImageFile\\HealthBarWithOneDamagePoint.png");
    HealthBar3 = al_load_bitmap("ImageFile\\HealthBarHalfWayFull.png");
    HealthBar4 = al_load_bitmap("ImageFile\\HealthBarOneHealthLeft.png");
    HealthBar5 = al_load_bitmap("ImageFile\\HealthBarEmpty.png");
    Zero = al_load_bitmap("ImageFile\\0.png");
    One = al_load_bitmap("ImageFile\\1.png");
    Two = al_load_bitmap("ImageFile\\2.png");
    Three = al_load_bitmap("ImageFile\\3.png");
    Four = al_load_bitmap("ImageFile\\4.png");
    Five = al_load_bitmap("ImageFile\\5.png");
    Six = al_load_bitmap("ImageFile\\6.png");
    Seven = al_load_bitmap("ImageFile\\7.png");
    Eight = al_load_bitmap("ImageFile\\8.png");
    Nine = al_load_bitmap("ImageFile\\9.png");
    Ball = al_load_bitmap("ImageFile\\ball.png");
    BallEmpty = al_load_bitmap("ImageFile\\ballempty.png");
    OpHeart = al_load_bitmap("ImageFile\\heart.png");
    ShootSelfButton = al_load_bitmap("ImageFile\\ShootSelfButton.png");
    ShootOpButton = al_load_bitmap("ImageFile\\ShootOpButton.png");


    //check if images are missing
    if (!Table  || !Dummy || !Player || !Dummyfires || !Dummyflash || !Playerflash
        || !Playerfires || !Buttons || !PlayerSelf1 || !PlayerSelf2 || !PlayerSelf3
        || !Shop || !IndividualBulletForCounter || !FullBulletCounter || !BlankBulletCounter
        || !InventoryButton || ! ShopButton || !HealthBar1 || !HealthBar2 || !HealthBar3
        || !HealthBar4 || !HealthBar5 || !Zero || !One || !Two || !Three || !Four
        || !Five || !Six || !Seven || !Eight || !Nine || !Ball || !BallEmpty || !OpHeart
        || !ShootSelfButton) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }
    //Start up phase.
    al_rest(1.0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_flip_display();
    al_rest(.2);
    al_draw_bitmap(Dummy, 0, 0, 0);
    al_flip_display();
    al_rest(.2);
    al_draw_bitmap(Player, 0, 0, 0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_rest(.2);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));


    frameOfGame();



    return 0;
}

