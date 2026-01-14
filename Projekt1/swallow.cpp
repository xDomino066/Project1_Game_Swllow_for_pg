//------------------------------------------------
//----------------- BOCP PROJECT 1----------------
//------------------------------------------------
//-------------------- AUTHOR --------------------
//---------------- DOMINIK ROSIK -----------------
//------------------------------------------------
//------------------ TODO LIST -------------------
//--------------  1.add levels               -----
//--------------  2.                         -----
//--------------  3.                         -----
//--------------  4.                         -----
//--------------  5.                         -----
//------------------------------------------------
//------------------------------------------------
//     \\
//      (o>
// \\_//)
//  \_/_)
//   _|_



#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#include <ncurses.h>
#include <time.h>
#include <math.h>

//------------------------------------------------
//------------  CONFIGURATION CONSTANTS ----------
//------------------------------------------------

//SETTINGS CONSTANTS
#define MAXIMUMNAME 12
#define NUMBEROFSETTINGS 3     //max number of settings
#define NUMBEROFSTARSETTINGS 2     //max number of settings
#define NUMBEROFGENERALSETTINGS 7    //max number of settings
#define NUMBEROFHUNTERSETTINGS 6 
#define NUMBEROFSTARTSCREEN 5


// Keyboard controls
#define QUIT 27 //esc key to quit
#define START 10 //enter key to start the game
#define STARTRANKING 11
#define UP 'w' //key to move swallow up
#define DOWN 's' //key to move swallow down
#define LEFT 'a' //key to move swallow left
#define RIGHT 'd' //key to move swallow right
#define SPEEDDOWN 'o' //decreses swollow speed
#define SPEEDUP 'p' //increses swollow speed
#define UP2 'W' //key to move swallow up
#define DOWN2 'S' //key to move swallow down
#define LEFT2 'A' //key to move swallow left
#define RIGHT2 'D' //key to move swallow right
#define SPEEDDOWN2 'O' //decreses swollow speed
#define SPEEDUP2 'P' //increses swollow speed
#define NOKEY ERR //no key pressed
#define SETTINGS 'x'
#define RANKINGS 22
#define BACKSPACE 127
#define ARROWUP KEY_UP
#define ARROWDOWN KEY_DOWN        //keys for arrows
#define ARROWLEFT KEY_LEFT 
#define ARROWRIGHT KEY_RIGHT
//DIFICULTY LEVELS
#define EASY 0
#define NORMAL 1
#define HARD 2
#define BONUSHARDMULT 10
#define BONUEASYMULT 0.9
#define EASYMULT 0.75
#define HARDMULT 1.5

// Timing and speed
#define FRAME_TIME	  100	    // Milliseconds per frame (100ms = 0.1 sec)
#define BIRD_SPEED    1		    // Swallow moves 1 cell per frame

//Game conditions

//Stats Logic
#define ABSOLUTEMAXSTARS 100
#define ABSOLUTEMINSTARS 20

#define ABSOLUTEMAXSTARSRATE 40
#define ABSOLUTEMINSTARSRATE 10

#define ABSOLUTEMAXTIME 600
#define ABSOLUTEMINTIME 90

#define ABSOLUTEMAXLIFE 10
#define ABSOLUTEMINLIFE 1

#define ABSOLUTEMAXSCORE 10000
#define ABSOLUTEMINSCORE 25

#define ABSOLUTEMAXSPEED 8
#define ABSOLUTEMINSPEED 1

#define ABSOLUTEMAXHUNTERS 20
#define ABSOLUTEMINHUNTERS 1

#define ABSOLUTEMAXWINHI 65
#define ABSOLUTEMINWINHI 10

#define ABSOLUTEMAXWINWI 235
#define ABSOLUTEMINWINWI 50

#define ABSOLUTEMAXHUNTERRATE 80
#define ABSOLUTEMINHUNTERRATE 10

#define ABSOLUTEMAXHUNTERSPEED 5
#define ABSOLUTEMINHUNTERSPEED 1

#define ABSOLUTEMAXSHUNTERBOUNCES 10
#define ABSOLUTEMINHUNTERBOUNCES 1

#define ABSOLUTEMAXHUNTERDAMAGE 10
#define ABSOLUTEMINHUNTERDAMAGE 1

#define ABSOLUTEMAXHUNTERWIDTH 7
#define ABSOLUTEMINHUNTERWIDTH 3

#define ABSOLUTEMAXHUNTERHEIGHT 7
#define ABSOLUTEMINHUNTERHEIGHT 3
//hunter logic

#define HUNTERCOLORSMALL 3
#define HUNTERCOLORBIG 4
#define HUNTERPREDICT 5
#define sNORMAL 0
#define sWAITING 1          //when free time add this shit to config
#define sDash 2
//#define DASHTIME 20
#define DASHSPEED 5

//star logic
#define RATE3TIERSTAR 10        //chance for tier 3 star
#define RATE2TIERSTAR 30        //chance for tier 2 star
#define RATE1TIERSTAR 100       //chance for tier 1 star
#define POINTS1TIERSTAR 25      //points for tier 3 star
#define POINTS2TIERSTAR 50      //points for tier 2 star
#define POINTS3TIERSTAR 100      //points for tier 1 star
#define SPEED1TIERSTAR 1        //speed for tier 3 star
#define SPEED2TIERSTAR 2        //speed for tier 2 star
#define SPEED3TIERSTAR 3        //speed for tier 1 star

// Window dimensions and position
#define BORDER		  1		    // Border width
#define ROWS		  65	    // Play window height
#define COLS		  235 	    // Play window width
#define OFFY		  2		    // Y offset from top of screen
#define OFFX		  5		    // X offset from left of screen
#define EDGETOP       0
#define EDGEBOTTOM    1
#define EDGELEFT      2         //spawning edges
#define EDGERIGHT     3
#define SPAWNRIGHT    0

// Color pair identifiers (used with ncurses color system)
#define MAIN_COLOR	    1		// Main window color
#define STAT_COLOR	    2		// Status bar color
#define PLAY_COLOR	    3		// Play area color
#define SWALLOW_COLOR	4		// Bird color
#define START_COLOR	    5		// Bird color
#define STAR_YELLOW_COLOR 6     // color of star for 10 points
#define STAR_L_YELLOW_COLOR 7   // color of star for 25 points
#define STAR_RED_COLOR  8       // color of star for 50 points
#define TOP1COLOR       9       //top1 color
#define NIGHTCOLOR   10      //color for night fall

#define SWALLOWHIGHLIFE 11      //color for highlife swallow
#define SWALLOWLOWLIFE 12       //color for low life swallow
#define ENDSCREENCOLOR 14

// NEW COLORS PALET
	
#define DARK_GRAY     8
#define LIGHTRED      9
#define LIGHTGREEN    10
#define LIGHTYELLOW   11
#define LIGHTBLUE     12
#define LIGHTMAGENTA  13
#define LIGHTCYAN     14
#define LIGHTWHITE    15

//swallow parameters
#define swallowHIGHT 1
#define swallowWidth 5
#define swallowFRAMES 2 //numbers of models for swallow
#define animationDELAY 2 //dealey of changing animation

//albartros logic defines
#define ALBATROSMODELWIDTH 11
#define ALBATROSMODELHIGHT 1
#define INVULNERABLESWALLOWWHILECARRYING 999
#define INALBATROS 1
#define NOTINALABATROS 0
#define ALBATROSCOLOR 13

//additional defines for other numbers
#define SLEEP3000000 3000000
#define SLEEP200000 200000
#define SLEEP100000 100000
#define SLEEP50000 50000
#define SLEEP20000 20000
#define SLEEP1000 1000
#define OPTION0 0
#define OPTION1 1
#define OPTION2 2
#define OPTION3 3
#define OPTION4 4
#define OPTION5 5
#define OPTION6 6
#define MINUS1 1
#define CHANGESTARMAX 5
#define CHANGERATESTAR 1
#define CHANGETIMER 10
#define CHANGESTARTLIFE 1
#define CHANGESCORE 25
#define CHANGESPEED 1
#define WINHIGHCHANGE 5
#define WINWITDHCHANGE 10
#define HUNTERRATECHANGE 5
#define HUNTERRATECHANGE2 10
#define HUNTERSPEEDCHANGE 1
#define HUNTERBUNCESCHANGE 1
#define HUNTERDAMAGECHANGE 1
#define HUNTERWIDTHCHANGE 1
#define HUNTERHEIGHTCHANGE 1
#define STARTSWALLOWX 5
#define DEFOULTDXSWALLOW 1
#define DEFOULTDYSWALLOW 0
#define POSDX 1
#define NEGDX -1
#define NULLDX 0
#define POSDY 1
#define NEGDY -1
#define NULLDY 0
#define OFFY1 1
#define OFFX1 1
#define YES 1
#define NO 0
#define maxrankingshow 25
//yes its the same catergory
#define SETTINGSSHOWED 5
#define setting1showed 10
#define setting2showed 12
#define setting3showed 14
#define setting4showed 16
#define setting5showed 18
#define setting6showed 20
#define setting7showed 22

#define mainscreen1 30
#define mainscreen2 34
#define mainscreen3 38
#define mainscreen4 42
#define mainscreen5 46

#define statwin1 1
#define statwin2 2
#define statwin3 3
#define statwin4 4
#define statwin5 5

#define ranking1 3
#define ranking2 5
#define ranking3 6
#define ranking4 8
//its still goes on
#define OFFBY10 10
#define OFFBY5 5
#define OFFBY15 15
#define OFFBY20 20
#define OFFBY7 7
#define OFFBY4 4
#define OFFBY3 3
#define OFFBY2 2
#define OFFBY1 1

#define MAXKEY 50
#define albatrosvector 1
#define cappedatemp 50
#define safedist 15
#define fallingdown 1
//i propably should better caterogised it
#define swallowstarssigny 10
#define swallowstarssignx 70
#define PREC100 100
#define onefourofscreen 4
#define BY2 2
#define huntersizetype2 9
#define minhunter 2
#define eges4 4
#define minswallowoff2 2
#define oppostevect -1


// model /`V`\

//------------------------------------------------
//------------------  Structs  -------------------
//------------------------------------------------

typedef struct {
    WINDOW* window;     // ncurses window
    int x, y;		    // position on screen
	int rows, cols;		// size of window
	int color;          // color scheme
} UI;

typedef struct{
    char name[MAXIMUMNAME];
    long score;
    int difficulty;
    float MULT;
} SCORE;

typedef struct {
    int currentWincolor;
    //game settings
    int Timer;
    int WinningScore;
    int Startlife;
    int invulnerable;
    int WinWidth;
    int WinHight;
    int StHight;
    //star settings
    int StarRate;
    int MaxStars;
    int StarTier1Speed;
    int StarTier2Speed;
    int StarTier3Speed;
    //speed settings
    int MinSpeed;
    int MaxSpeed;

    //hunter settings
    int HunterRate;    
    int HunterSpeed;    
    int HunterBounces;  
    int HunterDamage;   
    int HunterWidth;    
    int HunterHeight; 
    char HunterTemplate;  
    int hunterscaling; //for how many frames it becomes harder
    int huntercheckingdash;
    int HunterDashTime;
    //albatros config
    int albatrosRate;
    int albatrosSpeed;
    int albatrosSpeedWhileCarrying;

    //backup settings im to lazy to create new struct
    int backuphuntersrate;
    int backuphuntersbounce;

    //fog settings
    int fogRate;
    int fogDuration;
    float fogcutProcent;

    //seed
    int Seed;
} CONFIG;

typedef struct {
	WINDOW* win;		// window containing the swallow
	int x, y;		// current position
	int dx, dy;		// velocity direction vector
	int speed;		// movement speed
	char model[swallowFRAMES][swallowWidth+1];	    // swallow model 
    int currentFRAME;   //current frame
    int frameDelay;     //animation delay
    int width;      // width of the swallow model
    int height;     // hight of the swallow model
	int color;      // color scheme
    int life;		// life of swallow
    int score;      // score of player
    int time;       // time of the game
    float timeacumulator;
    int timeLeft;   // time left
    int quit;
    int invulnerableTimer; //time after hit when you cant get hit again
    int inAlbatros;
} SWALLOW;

typedef struct {
    int x, y;		// current position
	int dx, dy;		// velocity direction vector
	int speed;		// movement speed
    int active;     //is star active
    char model;     //model of star
    int color;      //color of star
    int points;     //points for collecting
} STAR;

typedef struct{
    float x,y;
    float dx,dy;
    int speed;
    int active;
    int bounces;
    int width;
    int height;
    char templete;
    int hit;
    int timerscaling;
    int timeafterspawn;
    int state;
    int waiting;
    int dashed;
    int color;
    int hunterdamage;
}HUNTER;

typedef struct{
    float x,y;
    float dx,dy;
    int speed;
    int active;
    int carrying;
    int aheight;
    int awitdh;
    int targex;
    int targety;
    char model[ALBATROSMODELWIDTH];
    int color;
}ALBATROS;

typedef struct {
    char name[MAXIMUMNAME];
    int score;
} RANKING;

typedef struct{
    int active;
    int timer;
    float currentCUTX;
    float currentCUTY;
    float targetCutX;
    float targetCutY;
    int spawnRate;
    int duration;
    char fogmodel;
}FOG;
//------------------------------------------------
//------------------  FUCTIONS  ------------------
//------------------------------------------------

WINDOW* Start(CONFIG* cfg);//Function of initalization of ui
void mainMenu(SWALLOW* s,STAR stars[],HUNTER hunters[],ALBATROS* a,SCORE* scoring,CONFIG* cfg,CONFIG* bcfg,WINDOW *st_win,FOG* fog,char y);
void starranking(SWALLOW* s,STAR stars[],HUNTER hunters[],ALBATROS* a,SCORE* scoring,CONFIG* cfg,CONFIG* bcfg,WINDOW *st_win,FOG* fog);
void startfreeplay(SWALLOW* s,STAR stars[],HUNTER hunters[],ALBATROS* a,SCORE* scoring,CONFIG* cfg,CONFIG* bcfg,WINDOW *st_win,FOG* fog);
SWALLOW* SetupSwallow(WINDOW* w, CONFIG* cfg);//swallow initalization
void colorset(SWALLOW* s,WINDOW* status_win,CONFIG* cfg); //color setup
void colorchange(SWALLOW* s,WINDOW* status_win,CONFIG* cfg);
int LoadConfig(const char* filename, CONFIG* config); //loading config
void loadconf1(CONFIG* config, char* key, int value);
void loadconf2(CONFIG* config, char* key, int value);
void loadconf3(CONFIG* config, char* key, int value);
void savebasicconfig(CONFIG* cfg,CONFIG* bcfg);
void loadbasicconfig(CONFIG* cfg,CONFIG* bcfg);
void backup(CONFIG* cfg);
void entername(char* name,SCORE* scoring);
void selecDificulty(SCORE* scoring);
void applaydificulty(SCORE* scoring,CONFIG*cfg,CONFIG *bcfg);
void calculatescore(SCORE* score,SWALLOW* s,CONFIG*cfg);
void sort(RANKING rank[], int count);
void updateRankings(SCORE* score);
void showRanking();
void seedInit(CONFIG* cfg);

void settingsScreen(CONFIG* cfg);
void settingsUi2(CONFIG* cfg);
void settingsUi3(CONFIG* cfg);
void sui3ex1(CONFIG* cfg,int option);
void sui3ex2(CONFIG* cfg,int option);
void settingsUi4(CONFIG* cfg);
void sui4ex1(CONFIG* cfg,int option);
void sui4ex2(CONFIG* cfg,int option);
void blinkon();
void blinkoff();
void drawSettingUi(CONFIG* cfg,int option);
void drawSettingsUi2(CONFIG* cfg,int option);
void drawSettingsUi3(CONFIG* cfg,int option);
void drawSettingsUi3_5(CONFIG* cfg,int option);
void drawSettingsUi4(CONFIG* cfg,int option);
void drawSettingsUi4_5(CONFIG* cfg,int option);

void MainGameLoop(SWALLOW* s,WINDOW* status_win,STAR stars[],CONFIG* cfg,HUNTER hunters[],ALBATROS* a,FOG* fog,SCORE* scoring);//Function of Main loop for the game
void moveSwallow(SWALLOW* s,CONFIG* cfg, char ch,FOG* fog);//function of moving logic
void speedSet(SWALLOW* s, char ch,CONFIG* cfg);//fuction for seting speed
void drawSwallow(SWALLOW* s); //drawing swallow


void startScreen(char& s);  //function for starting screen
void drawstartingscreenUi(int option);
void DRAWSWALLOWSTARS();    //draw text on starting screen
void printSTATwin(SWALLOW* s, WINDOW* status_win, int ch,CONFIG* cfg,SCORE* scoring); //printing status window
void resetGame(SWALLOW* s,CONFIG* cfg); //reseting game status
void checkWinLose(SWALLOW* s, CONFIG* cfg, STAR stars[], HUNTER hunters[], FOG* fog, ALBATROS* a,SCORE* score,WINDOW* st_win); //checking win cond
void gameoveranim(SWALLOW* s, CONFIG* cfg, STAR stars[], HUNTER hunters[], FOG* fog, ALBATROS* a,SCORE* score,WINDOW* st_win);
void playfallinganimation(SWALLOW* s, CONFIG* cfg, STAR stars[], HUNTER hunters[], FOG* fog, ALBATROS* a);
void GAMEOVERaniamtion(WINDOW* win,WINDOW* st_win,CONFIG* cfg,SWALLOW* s);

void INITSTAR(STAR stars[],CONFIG* cfg);                            //initializing stars
void spwanStar(STAR stars[],CONFIG* cfg);                           //spwaning stars function
void moveStar(STAR stars[],CONFIG* cfg);                            //moving stars function
void drawStar(WINDOW* win, STAR stars[],CONFIG* cfg);               //drawing stars function
void checkstarpickup(SWALLOW* s, STAR stars[],CONFIG* cfg);         //function for checking if star was picked up

void INITHUNTERS(HUNTER hunters[],CONFIG* cfg); //initializing stars
void chooseedgestart(CONFIG* cfg,HUNTER hunters[],int edge,int i);// edge
void spawnhunter(SWALLOW* s,CONFIG* cfg,HUNTER hunters[]);
void calculatehuntervector(SWALLOW* s,CONFIG* cfg,HUNTER hunters[],int i);
void moveHunters(SWALLOW* s,CONFIG* cfg, HUNTER hunters[]);
void hunterNormal(SWALLOW* s,CONFIG* cfg, HUNTER hunters[],int i,float firstdis);
void hunterWaiting(SWALLOW* s,CONFIG* cfg, HUNTER hunters[],int i);
void dedectbounce(CONFIG* cfg, HUNTER hunters[],int i);
void drawHunters(WINDOW* win, HUNTER hunters[]);
void swallowhuntercolison(SWALLOW* s, CONFIG* cfg, HUNTER hunters[]);
void hunterscaling(CONFIG* cfg,HUNTER hunters[]);

void INITTIME(SWALLOW* s,CONFIG* cfg); //initializing timer
//albatros logic functions
void initAlbatros(ALBATROS* a);
void spawnAlbatros(ALBATROS* a,CONFIG* cfg);
void moveAlbatros(SWALLOW* s,ALBATROS* a,CONFIG* cfg,HUNTER hunters[]);
void listenforcarrying(SWALLOW* s,ALBATROS* a,CONFIG* cfg,HUNTER hunters[]);
void serchforsafe(HUNTER hunters[],CONFIG* cfg,ALBATROS* a);
void serchagainifsafe(HUNTER hunters[],CONFIG* cfg,ALBATROS* a);
void drawAlbatros(WINDOW* win, ALBATROS* a);

//fog logic
void initFog(FOG* fog,CONFIG*cfg);
void updateFog(SWALLOW* s,FOG* fog,CONFIG*cfg);
void drawFog(WINDOW* win,FOG* fog,CONFIG*cfg);


int main()
{
    char s;
    CONFIG config;
    CONFIG basicCfg;
    WINDOW *mainwin = Start(&config);
    SCORE scoring;
    FOG fog;
    if(LoadConfig("config.txt", &config))
    {
        return 1;
    }
    savebasicconfig(&config,&basicCfg);
    //star setup
    STAR stars[ABSOLUTEMAXSTARS];
    HUNTER hunters[ABSOLUTEMAXHUNTERS];

    while(1)
    {   
        WINDOW *p_win = newwin(config.WinHight, config.WinWidth, OFFY, OFFX);   //player win initalization
        WINDOW *st_win = newwin(config.StHight, config.WinWidth, OFFY +config.WinHight , OFFX); // status window initalization
        //swallow initialization
        SWALLOW* swallow = SetupSwallow(p_win, &config);
        ALBATROS albatros;
        colorset(swallow, st_win,&config);
        //star initalization
        INITSTAR(stars,&config);
        //fog initalization
        initFog(&fog,&config);
        resetGame(swallow,&config); 
        //start screen
        startScreen(s);
        //main game loop
        mainMenu(swallow,stars,hunters,&albatros,&scoring,&config,&basicCfg,st_win,&fog,s);
        if(s==QUIT)
        {
            //deleting UI
            delwin(p_win);
            delwin(st_win);
            //free ram
            free(swallow);
            break;
        }
    }

    //ending ncurses
    endwin();

    return 0;
}
//0 MAIN MENU HANDLING
void mainMenu(SWALLOW* s,STAR stars[],HUNTER hunters[],ALBATROS* a,SCORE* scoring,CONFIG* cfg,CONFIG* bcfg,WINDOW *st_win,FOG* fog,char y)
{
    if(y==SETTINGS)
    {
        settingsScreen(cfg);
    }
    else if(y==STARTRANKING)
    {
        seedInit(cfg);
        starranking(s,stars,hunters,a,scoring,cfg,bcfg,st_win,fog);
    }
    else if(y==START)
    {
        seedInit(cfg);
        startfreeplay(s,stars,hunters,a,scoring,cfg,bcfg,st_win,fog);
    }
    else if(y==RANKINGS)
    {
        showRanking();
    }
}
//1 FUNCTIONS FOR STARTING GAME MODES
void starranking(SWALLOW* s,STAR stars[],HUNTER hunters[],ALBATROS* a,SCORE* scoring,CONFIG* cfg,CONFIG* bcfg,WINDOW *st_win,FOG* fog)
{
    //starting all functions needed for raking
    char playerName[MAXIMUMNAME];
    entername(playerName,scoring);
    selecDificulty(scoring);
    applaydificulty(scoring,cfg,bcfg);
    resetGame(s,cfg);

    INITTIME(s, cfg);
    INITHUNTERS(hunters,cfg);
    initAlbatros(a);
    clear();
    backup(cfg);
    MainGameLoop(s, st_win, stars, cfg,hunters,a,fog,scoring);
    checkWinLose(s,cfg,stars,hunters,fog,a,scoring,st_win);
}
void startfreeplay(SWALLOW* s,STAR stars[],HUNTER hunters[],ALBATROS* a,SCORE* scoring,CONFIG* cfg,CONFIG* bcfg,WINDOW *st_win,FOG* fog)
{
    //starting all function for free play mode
    strcpy(scoring->name, "FreePlay");  //for player w dont have name couse its free play
    INITTIME(s, cfg); //initializing time
    INITHUNTERS(hunters,cfg);
    initAlbatros(a);
    clear();
    backup(cfg);
    MainGameLoop(s, st_win, stars, cfg,hunters,a,fog,scoring); // main game loop
    checkWinLose(s,cfg,stars,hunters,fog,a,scoring,st_win);//checkingwinconfition
}
//2 STARTING GAME INITIALIZATION
WINDOW* Start(CONFIG* cfg)
{
	WINDOW* win;
	// Initialize ncurses - sets up terminal for text UI
	if ( (win = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}
    //input initalization
    cbreak();
    //special keys initalization
    keypad(win, TRUE);
    //no freeze when waiting for input
    nodelay(win, TRUE);
	// Don't echo typed characters to screen
	noecho();
    //start colors
    start_color();

    if(cfg->Seed>0)
    {
        srand(cfg->Seed);
    }
    else
    {
        srand(time(NULL));
    }

	// Make cursor invisible (curs_set: 0=invisible, 1=normal, 2=very visible)
	curs_set(0);

	return win;
}
//3 CONFING FUNCTIONS
//3.1 LOADING CONFIG
int LoadConfig(const char* filename, CONFIG* config)
{
    //loading cnofig from config file
    FILE* file = fopen(filename, "r");//opoening file ending when failed
    if(file==NULL)
    {
        return 1;
    }

    char key[MAXKEY];//fized maximum words for config key word
    
    while(fscanf(file,"%s",key) != EOF)//loop for reading whole file
    {
        if (strcmp(key, "HUNTERTEMPLATE") == 0)
        {
            char ch;
            fscanf(file, " %c", &ch);       //special function for reading char
            config->HunterTemplate = ch;
        }
        else
        {
        int value;
        fscanf(file, "%d", &value);
        loadconf1(config,key,value);
        loadconf2(config,key,value);        //all other configs
        loadconf3(config,key,value);
        }
    }
     
    fclose(file);
    return 0;
}
void loadconf1(CONFIG* config, char* key, int value)
{
    if (strcmp(key, "TIMELIMIT") == 0) config->Timer = value;
    else if (strcmp(key, "WINSCORE") == 0) config->WinningScore = value;
    else if (strcmp(key, "STARRATE") == 0) config->StarRate = value;
    else if (strcmp(key, "MAXSTARS") == 0) config->MaxStars = value;
    else if (strcmp(key, "LIFE") == 0) config->Startlife = value;
    else if (strcmp(key, "MINSPEED") == 0) config->MinSpeed = value;
    else if (strcmp(key, "MAXSPEED") == 0) config->MaxSpeed = value;
    else if (strcmp(key, "HUNTERRATE") == 0) config->HunterRate = value;
    else if (strcmp(key, "HUNTERSPEED") == 0) config->HunterSpeed = value;
    else if (strcmp(key, "HUNTERBOUNCES") == 0) config->HunterBounces = value;
    else if (strcmp(key, "HUNTERDAMAGE") == 0) config->HunterDamage = value;
    else if (strcmp(key, "TIER1STARSPEED") == 0) config->StarTier1Speed = value;
    else if (strcmp(key, "TIER2STARSPEED") == 0) config->StarTier2Speed = value;
    else if (strcmp(key, "TIER3STARSPEED") == 0) config->StarTier3Speed = value;

}
void loadconf2(CONFIG* config, char* key, int value)
{
    if (strcmp(key, "HUNTERWIDTH") == 0) config->HunterWidth = value;
    else if (strcmp(key, "HUNTERHEIGHT") == 0) config->HunterHeight = value;
    else if (strcmp(key, "HUNTERDASHTIME") == 0) config->HunterDashTime = value;
    else if (strcmp(key, "WINWIDTH") == 0) config->WinWidth = value;
    else if (strcmp(key, "WINHIGHT") == 0) config->WinHight = value;
    else if (strcmp(key, "STHIGHT") == 0) config->StHight = value;
    else if (strcmp(key, "INVULNERABLE") == 0) config->invulnerable = value;
    
}
void loadconf3(CONFIG* config, char* key, int value)
{
    if (strcmp(key, "HUNTERSCAILING") == 0) config->hunterscaling = value;
    else if (strcmp(key, "HUNTERCHECKINGDASH") == 0) config->huntercheckingdash = value;
    else if (strcmp(key, "ALBATROSSRATE") == 0) config->albatrosRate = value;
    else if (strcmp(key, "ALBATROSSPEED") == 0) config->albatrosSpeed = value;
    else if (strcmp(key, "ALBATROSSPEEDWHILECARRYING") == 0) config->albatrosSpeedWhileCarrying = value;
    else if (strcmp(key, "FOGRATE") == 0) config->fogRate = value;
    else if (strcmp(key, "FOGDURATION") == 0) config->fogDuration = value;
    else if (strcmp(key, "FOGCUTTARGETPROCENT") == 0) config->fogcutProcent = value;
    else if (strcmp(key, "SEED") == 0) config->Seed = value;
}
//3.2 BACKUP CONFIGS
void savebasicconfig(CONFIG* cfg,CONFIG* bcfg)
{
    bcfg->Timer=cfg->Timer;
    bcfg->WinningScore=cfg->WinningScore;
    bcfg->StarRate=cfg->StarRate;
    bcfg->MaxStars=cfg->MaxStars;
    bcfg->Startlife=cfg->Startlife;
    bcfg->invulnerable=cfg->invulnerable;
    bcfg->MinSpeed=cfg->MinSpeed;
    bcfg->MaxSpeed=cfg->MaxSpeed;
    bcfg->HunterRate=cfg->HunterRate;                   //saving backup of config for initialization into ranking mode
    bcfg->HunterBounces=cfg->HunterBounces;
    bcfg->HunterDamage=cfg->HunterDamage;
    bcfg->HunterWidth=cfg->HunterWidth;
    bcfg->HunterHeight=cfg->HunterHeight;
    bcfg->hunterscaling=cfg->hunterscaling;
    bcfg->huntercheckingdash=cfg->huntercheckingdash;
    bcfg->albatrosRate=cfg->albatrosRate;
    bcfg->albatrosSpeed=cfg->albatrosSpeed;
    bcfg->albatrosSpeedWhileCarrying=cfg->albatrosSpeedWhileCarrying;
}
void loadbasicconfig(CONFIG* cfg,CONFIG* bcfg)
{
    cfg->Timer=bcfg->Timer;
    cfg->WinningScore=bcfg->WinningScore;
    cfg->StarRate=bcfg->StarRate;
    cfg->MaxStars=bcfg->MaxStars;
    cfg->Startlife=bcfg->Startlife;
    cfg->invulnerable=bcfg->invulnerable;
    cfg->MinSpeed=bcfg->MinSpeed;
    cfg->MaxSpeed=bcfg->MaxSpeed;
    cfg->HunterRate=bcfg->HunterRate;
    cfg->HunterBounces=bcfg->HunterBounces;                 //loading backup of config for initialization into ranking mode
    cfg->HunterDamage=bcfg->HunterDamage;
    cfg->HunterWidth=bcfg->HunterWidth;
    cfg->HunterHeight=bcfg->HunterHeight;
    cfg->hunterscaling=bcfg->hunterscaling;
    cfg->huntercheckingdash=bcfg->huntercheckingdash;
    cfg->albatrosRate=bcfg->albatrosRate;
    cfg->albatrosSpeed=bcfg->albatrosSpeed;
    cfg->albatrosSpeedWhileCarrying=bcfg->albatrosSpeedWhileCarrying;
}
void backup(CONFIG* cfg)
{
    cfg->backuphuntersbounce=cfg->HunterBounces;
    cfg->backuphuntersrate=cfg->backuphuntersrate;//saving back up hunter stats that chenge while scailing
}
void loadbackup(CONFIG* cfg)
{
    cfg->HunterBounces=cfg->backuphuntersbounce;//loading back up hunter stats that chenge while scailing
    cfg->backuphuntersrate=cfg->backuphuntersrate;
}
//4 SETTINGS FUNCTIONS
//4.1 SETTINGS BACKEND
void settingsScreen(CONFIG* cfg)
{
    int option=OPTION0; //operaiting backend of settings screen uno
    while(1)
    {
        drawSettingUi(cfg,option);//drawing frontend

        int ch = getch();
        if(ch==ARROWUP)
        {
            option--;
            if(option<OPTION0)
            {
                option=NUMBEROFSETTINGS-MINUS1;
            }
        }
        else if(ch==ARROWDOWN)
        {
            option++;
            if(option>=NUMBEROFSETTINGS)
            {
                option=NUMBEROFSETTINGS-MINUS1;
            }
        }
        else if(ch==START)
        {
            if(option==OPTION0)
            {
                settingsUi3(cfg);
            }
            if(option==OPTION1)
            {
                settingsUi2(cfg);
            }
            if(option==OPTION2)
            {
                settingsUi4(cfg);
            }
        }
        
        if(ch==QUIT)
        {
            break;
        }
        usleep(SLEEP100000);
    } 
}
void settingsUi2(CONFIG* cfg)
{
    int option=OPTION0; //operaiting backend of settings screen dos
    while(1)
    {
        drawSettingsUi2(cfg,option);//drawing frontend

        int ch = getch();
        if(ch==ARROWUP)
        {
            option--;
            if(option<OPTION0)
            {
                option=NUMBEROFSTARSETTINGS-MINUS1;
            }                                   //up/down arrow press to  switch between what to change
        }                                      
        else if(ch==ARROWDOWN)
        {
            option++;
            if(option>=NUMBEROFSTARSETTINGS)
            {
                option=NUMBEROFSTARSETTINGS-MINUS1;
            }
        }
        else if(ch==ARROWRIGHT)
        {                                //left/right arrow press to  desrese/increse value
            if(option==OPTION0)
            {
                cfg->MaxStars += CHANGESTARMAX;
                if(cfg->MaxStars > ABSOLUTEMAXSTARS) 
                {
                    cfg->MaxStars = ABSOLUTEMINSTARS;
                }
            }
            if(option==OPTION1)
            {
                cfg->StarRate += CHANGERATESTAR;
                if(cfg->StarRate > ABSOLUTEMAXSTARSRATE) 
                {
                    cfg->StarRate = ABSOLUTEMINSTARSRATE;
                }
            }
        }
        else if(ch==ARROWLEFT)
        {
            if(option==OPTION0)
            {
                cfg->MaxStars -= CHANGESTARMAX;
                if(cfg->MaxStars < ABSOLUTEMINSTARS) 
                {
                    cfg->MaxStars = ABSOLUTEMAXSTARS;
                }
            }
            if(option==OPTION1)
            {
                cfg->StarRate -= CHANGERATESTAR;
                if(cfg->StarRate < ABSOLUTEMINSTARSRATE) 
                {
                    cfg->StarRate = ABSOLUTEMAXSTARSRATE;
                }
            }
        }
        if(ch==QUIT)
        {
            break;
        }
        usleep(SLEEP100000);
    } 
}
void settingsUi3(CONFIG* cfg)
{
    int option=OPTION0; //operaiting backend of settings screen tres
    while(1)
    {
        drawSettingsUi3(cfg,option);//drawing frontend

        int ch = getch();
        if(ch==ARROWUP)
        {
            option--;
            if(option<OPTION0)
            {
                option=NUMBEROFGENERALSETTINGS-MINUS1;
            }
        }
        else if(ch==ARROWDOWN)                  //up/down arrow press to  switch between what to change
        {
            option++;
            if(option>=NUMBEROFGENERALSETTINGS)
            {
                option=NUMBEROFGENERALSETTINGS-MINUS1;
            }
        }
        else if(ch==ARROWRIGHT)
        {
            sui3ex1(cfg,option);
        }
        else if(ch==ARROWLEFT)              //left/right arrow press to  desrese/increse value
        {
            sui3ex2(cfg,option);
        }
        if(ch==QUIT)
        {
            break;
        }
        usleep(SLEEP100000);
    } 
}
void sui3ex1(CONFIG* cfg,int option)
{//operaiting backend of settings screen tres
if(option==OPTION0)
            {
                cfg->Timer += CHANGETIMER;
                if(cfg->Timer > ABSOLUTEMAXTIME) 
                {
                    cfg->Timer = ABSOLUTEMINTIME;
                }
            }
            if(option==OPTION1)
            {
                cfg->Startlife += CHANGESTARTLIFE;
                if(cfg->Startlife > ABSOLUTEMAXLIFE) 
                {
                    cfg->Startlife = ABSOLUTEMINLIFE;
                }
            }
            if(option==OPTION2)
            {
                cfg->WinningScore += CHANGESCORE;
                if(cfg->WinningScore > ABSOLUTEMAXSCORE) 
                {
                    cfg->WinningScore = ABSOLUTEMINSCORE;
                }
            }
            if(option==OPTION3)
            {
                cfg->MinSpeed += CHANGESPEED;
                if(cfg->MinSpeed > ABSOLUTEMAXSPEED) 
                {
                    cfg->MinSpeed = ABSOLUTEMINSPEED;
                }
                if(cfg->MinSpeed>cfg->MaxSpeed)
                {
                    cfg->MaxSpeed++;
                }
            }
            if(option==OPTION4)
            {
                cfg->MaxSpeed += CHANGESPEED;
                if(cfg->MaxSpeed > ABSOLUTEMAXSPEED) 
                {
                    cfg->MaxSpeed = ABSOLUTEMINSPEED;
                }
                if(cfg->MinSpeed>cfg->MaxSpeed)
                {
                    cfg->MaxSpeed++;
                }
            }
            if(option==OPTION5)
            {
                cfg->WinHight += WINHIGHCHANGE;
                if(cfg->WinHight > ABSOLUTEMAXWINHI) 
                {
                    cfg->WinHight = ABSOLUTEMINWINHI;
                }
            }
            if(option==OPTION6)
            {
                cfg->WinWidth += WINWITDHCHANGE;
                if(cfg->WinWidth > ABSOLUTEMAXWINWI) 
                {
                    cfg->WinWidth = ABSOLUTEMINWINWI;
                }
            }
}
void sui3ex2(CONFIG* cfg,int option)
{//operaiting backend of settings screen tres
    if(option==OPTION0)
            {
                cfg->Timer -= CHANGETIMER;
                if(cfg->Timer < ABSOLUTEMINTIME) 
                {
                    cfg->Timer = ABSOLUTEMAXTIME;
                }
            }
            if(option==OPTION1)
            {
                cfg->Startlife -= CHANGESTARTLIFE;
                if(cfg->Startlife < ABSOLUTEMINLIFE) 
                {
                    cfg->Startlife = ABSOLUTEMAXLIFE;
                }
            }
            if(option==OPTION2)
            {
                cfg->WinningScore -= CHANGESCORE;
                if(cfg->WinningScore < ABSOLUTEMINSCORE) 
                {
                    cfg->WinningScore = ABSOLUTEMAXSCORE;
                }
            }
            if(option==OPTION3)
            {
                cfg->MinSpeed -= CHANGESPEED;
                if(cfg->MinSpeed < ABSOLUTEMINSPEED) 
                {
                    cfg->MinSpeed = ABSOLUTEMAXSPEED;
                }
                if(cfg->MinSpeed>cfg->MaxSpeed)
                {
                    cfg->MinSpeed--;
                }
            }
            if(option==OPTION4)
            {
                cfg->MaxSpeed -= CHANGESPEED;
                if(cfg->MaxSpeed < ABSOLUTEMINSPEED) 
                {
                    cfg->MaxSpeed = ABSOLUTEMAXSPEED;
                }
                if(cfg->MinSpeed>cfg->MaxSpeed)
                {
                    cfg->MinSpeed--;
                }
            }
            if(option==OPTION5)
            {
                cfg->WinHight -= WINHIGHCHANGE;
                if(cfg->WinHight < ABSOLUTEMINWINHI) 
                {
                    cfg->WinHight = ABSOLUTEMAXWINHI;
                }
            }
            if(option==OPTION6)
            {
                cfg->WinWidth -= WINWITDHCHANGE;
                if(cfg->WinWidth < ABSOLUTEMINWINWI) 
                {
                    cfg->WinWidth = ABSOLUTEMINWINWI;
                }
            }
}
void settingsUi4(CONFIG* cfg)
{//operaiting backend of settings screen cuatro
    int option=0;
    while(1)
    {
        drawSettingsUi4(cfg,option);//drawing frontend

        int ch = getch();
        if(ch==ARROWUP)
        {
            option--;
            if(option<OPTION0)
            {                             //up/down arrow press to  switch between what to change
                option=NUMBEROFHUNTERSETTINGS-MINUS1;
            }
        }
        else if(ch==ARROWDOWN)
        {
            option++;
            if(option>=NUMBEROFHUNTERSETTINGS)
            {
                option=NUMBEROFHUNTERSETTINGS-MINUS1;
            }
        }
        else if(ch==ARROWRIGHT)
        {
            sui4ex1(cfg,option);                 //left/right arrow press to  desrese/increse value
        }
        else if(ch==ARROWLEFT)
        {
            sui4ex2(cfg,option);
        }
        if(ch==QUIT)
        {
            break;
        }
        usleep(SLEEP100000);
    }
}
void sui4ex1(CONFIG* cfg,int option)
{
    if(option==OPTION0)
            {
                cfg->HunterRate += HUNTERRATECHANGE;
                if(cfg->HunterRate > ABSOLUTEMAXHUNTERRATE) 
                {
                    cfg->HunterRate = ABSOLUTEMINHUNTERRATE;
                }
            }
            if(option==OPTION1)
            {
                cfg->HunterSpeed += HUNTERSPEEDCHANGE;
                if(cfg->HunterSpeed > ABSOLUTEMAXHUNTERSPEED) 
                {
                    cfg->HunterSpeed = ABSOLUTEMINHUNTERSPEED;
                }
            }
            if(option==OPTION2)
            {
                cfg->HunterBounces += HUNTERBUNCESCHANGE;
                if(cfg->HunterBounces > ABSOLUTEMAXSHUNTERBOUNCES) 
                {
                    cfg->HunterBounces = ABSOLUTEMINHUNTERBOUNCES;
                }
            }
            if(option==OPTION3)
            {
                cfg->HunterDamage += HUNTERDAMAGECHANGE;
                if(cfg->HunterDamage > ABSOLUTEMAXHUNTERDAMAGE) 
                {
                    cfg->HunterDamage = ABSOLUTEMINHUNTERDAMAGE;
                }
            }
            if(option==OPTION4)
            {
                cfg->HunterWidth+= HUNTERWIDTHCHANGE;
                if(cfg->HunterWidth > ABSOLUTEMAXHUNTERWIDTH) 
                {
                    cfg->HunterWidth = ABSOLUTEMINHUNTERWIDTH;
                }
            }
            if(option==OPTION5)
            {
                cfg->HunterHeight += HUNTERHEIGHTCHANGE;
                if(cfg->HunterHeight > ABSOLUTEMAXHUNTERHEIGHT) 
                {
                    cfg->HunterHeight = ABSOLUTEMINHUNTERHEIGHT;
                }
            }
}
void sui4ex2(CONFIG* cfg,int option)
{
    if(option==OPTION0)
            {
                cfg->HunterRate -= HUNTERRATECHANGE;
                if(cfg->HunterRate < ABSOLUTEMINHUNTERRATE) 
                {
                    cfg->HunterRate = ABSOLUTEMAXHUNTERRATE;
                }
            }
            if(option==OPTION1)
            {
                cfg->HunterSpeed -= HUNTERSPEEDCHANGE;
                if(cfg->HunterSpeed < ABSOLUTEMAXHUNTERSPEED) 
                {
                    cfg->HunterSpeed = ABSOLUTEMINHUNTERSPEED;
                }
            }
            if(option==OPTION2)
            {
                cfg->HunterBounces -= HUNTERBUNCESCHANGE;
                if(cfg->HunterBounces < ABSOLUTEMINHUNTERBOUNCES) 
                {
                    cfg->HunterBounces = ABSOLUTEMAXSHUNTERBOUNCES;
                }
            }
            if(option==OPTION3)
            {
                cfg->HunterDamage -= HUNTERDAMAGECHANGE;
                if(cfg->HunterDamage < ABSOLUTEMINHUNTERDAMAGE) 
                {
                    cfg->HunterDamage = ABSOLUTEMAXHUNTERDAMAGE;
                }
            }
            if(option==OPTION4)
            {
                cfg->HunterWidth-= HUNTERWIDTHCHANGE;
                if(cfg->HunterWidth < ABSOLUTEMINHUNTERWIDTH) 
                {
                    cfg->HunterWidth = ABSOLUTEMAXHUNTERWIDTH;
                }
            }
            if(option==OPTION5)
            {
                cfg->HunterHeight -= HUNTERHEIGHTCHANGE;
                if(cfg->HunterHeight <ABSOLUTEMINHUNTERHEIGHT) 
                {
                    cfg->HunterHeight = ABSOLUTEMAXHUNTERHEIGHT;
                }
            }
}
//4.2 START SCREEN BACKEND
void startScreen(char& s)
{
    int ch;//backend of start screen
    int option=OPTION0;
    while (1)
    {
        ch = getch();
        if(ch==ARROWUP)
        {
            option--;
            if(option<OPTION0)
            {
                option=NUMBEROFSTARTSCREEN-MINUS1;
            }
        }
        if(ch==ARROWDOWN)
        {
            option++;
            if(option>=NUMBEROFSTARTSCREEN)
            {
                option=OPTION0;
            }
        }
        if(ch == START)
        {
            if(option==OPTION0)
            {
                s=STARTRANKING;
            }
            if(option==OPTION1)
            {
                s=START;
            }
            if(option==OPTION2)
            {
                s=SETTINGS;
            }
            if(option==OPTION4)
            {
                s=QUIT;
            }
            if(option==OPTION3)
            {
                s=RANKINGS;
            }
            break;
        }
        if(ch == QUIT)
        {
            s=QUIT;
            break;
        }

        clear(); //clearing screen

        drawstartingscreenUi(option);
        flushinp();

        refresh(); //screen refresh
        usleep(SLEEP100000);
    }
}
//4.3 SETTINGS FRONTEND
void drawSettingUi(CONFIG* cfg,int option)
{   //drawing UI
    wclear(stdscr);
    box(stdscr,0 ,0);
    mvprintw(SETTINGSSHOWED, (COLS/BY2), "SETTINGS");

    if(option == OPTION0)
    {
        blinkon();
    }
    mvprintw(setting1showed, (COLS/BY2)-OFFBY5, "General Settings");
    if(option == OPTION0) 
    {
        blinkoff();
    }

    if(option == OPTION1)
    {
        blinkon();
    }
    mvprintw(setting2showed, (COLS/BY2)-OFFBY5, "Star Settings");
    if(option == OPTION1) 
    {
        blinkoff();
    }
    if(option == OPTION2)
    {
        blinkon();
    }
    mvprintw(setting3showed, (COLS/BY2)-OFFBY5, "Hunters Settings");
    if(option == OPTION2) 
    {
        blinkoff();
    }
    
    mvprintw(LINES-OFFBY2, OFFBY2, "Use ARROWS to navigate  Press |ENTER| to select Press |ESC| to leave");

    refresh();
}
void drawSettingsUi2(CONFIG* cfg,int option)
{
    //drawing UI
    wclear(stdscr);
    box(stdscr,0 ,0);
    mvprintw(SETTINGSSHOWED, (COLS/BY2), "SETTINGS");

    if(option == OPTION0)
    {
        blinkon();
    }
    mvprintw(setting1showed, (COLS/BY2)-OFFBY5, "MAXSTARS < %d >   ", cfg->MaxStars);
    if(option == OPTION0) 
    {
        blinkoff();
    }

    if(option == OPTION1)
    {
        blinkon();
    }
    mvprintw(setting2showed, (COLS/BY2)-OFFBY5, "STARRATE < %d > ", cfg->StarRate);
    if(option == OPTION1) 
    {
        blinkoff();
    }
    
    mvprintw(LINES-OFFBY2, OFFBY2, "Use ARROWS to navigate  Press |ENTER| to select Press |ESC| to leave");

    refresh();
}
void drawSettingsUi3(CONFIG* cfg,int option)
{
    wclear(stdscr);
    box(stdscr,0 ,0);
    mvprintw(SETTINGSSHOWED, (COLS/BY2), "SETTINGS");

    if(option == OPTION0)
    {
        blinkon();
    }
    mvprintw(setting1showed, (COLS/BY2)-OFFBY5, "Time < %d >   ", cfg->Timer);
    if(option == OPTION0) 
    {
        blinkoff();
    }

    if(option == OPTION1)
    {
        blinkon();
    }
    mvprintw(setting2showed, (COLS/BY2)-OFFBY5, "Life of swallow < %d > ", cfg->Startlife);
    if(option == OPTION1) 
    {
        blinkoff();
    }
    if(option == OPTION2)
    {
        blinkon();
    }
    mvprintw(setting3showed, (COLS/BY2)-OFFBY5, "Quota < %d > ", cfg->WinningScore);
    if(option == OPTION2) 
    {
        blinkoff();
    }
    drawSettingsUi3_5(cfg,option);

    refresh();
}
void drawSettingsUi3_5(CONFIG* cfg,int option)
{//drawing UI
    if(option == OPTION3)
    {
        blinkon();
    }
    mvprintw(setting4showed, (COLS/BY2)-OFFBY5, "Minnimal Speed < %d > ", cfg->MinSpeed);
    if(option == OPTION3) 
    {
        blinkoff();
    }
    if(option == OPTION4)
    {
        blinkon();
    }
    mvprintw(setting5showed, (COLS/BY2)-OFFBY5, "Maximum Speed < %d > ", cfg->MaxSpeed);
    if(option == OPTION4) 
    {
        blinkoff();
    }
    if(option == OPTION5)
    {
        blinkon();
    }
    mvprintw(setting6showed, (COLS/BY2)-OFFBY5, "Window Hight < %d > ", cfg->WinHight);
    if(option == OPTION5) 
    {
        blinkoff();
    }
    if(option == OPTION6)
    {
        blinkon();
    }
    mvprintw(setting7showed, (COLS/BY2)-OFFBY5, "Window Width < %d > ", cfg->WinWidth);
    if(option == OPTION6) 
    {
        blinkoff();
    }
    
    mvprintw(LINES-OFFBY2, OFFBY2, "Use ARROWS to navigate  Press |ENTER| to select Press |ESC| to leave");
}
void drawSettingsUi4(CONFIG* cfg,int option)
{//drawing UI
    wclear(stdscr);
    box(stdscr,0 ,0);
    mvprintw(SETTINGSSHOWED, (COLS/BY2), "SETTINGS");

    if(option == OPTION0)
    {
        blinkon();
    }
    mvprintw(setting1showed, (COLS/BY2-OFFBY5), "HUNTER SPAWNRATE < %d >   ", cfg->HunterRate);
    if(option == OPTION0) 
    {
        blinkoff();
    }

    if(option == OPTION1)
    {
        blinkon();
    }
    mvprintw(setting2showed, (COLS/BY2-OFFBY5), "HUNTER SPEED < %d > ", cfg->HunterSpeed);
    if(option == OPTION1) 
    {
        blinkoff();
    }
    if(option == OPTION2)
    {
        blinkon();
    }
    mvprintw(setting3showed, (COLS/BY2-OFFBY5), "HUNTER BOUNCES < %d > ", cfg->HunterBounces);
    if(option == OPTION2) 
    {
        blinkoff();
    }
    if(option == OPTION3)
    {
        blinkon();
    }
    mvprintw(setting4showed, (COLS/BY2-OFFBY5), "HUNTER DAMAGE < %d > ", cfg->HunterDamage);
    if(option == OPTION3) 
    {
        blinkoff();
    }
    drawSettingsUi4_5(cfg,option);

    refresh();
}
void drawSettingsUi4_5(CONFIG* cfg,int option)
{ //drawing UI
    if(option == OPTION4)
    {
        blinkon();
    }
    mvprintw(setting5showed, (COLS/BY2-OFFBY5), "HUNTER WIDTH < %d > ", cfg->HunterWidth);
    if(option == OPTION4) 
    {
        blinkoff();
    }
    if(option == OPTION5)
    {
        blinkon();
    }
    mvprintw(setting6showed, (COLS/BY2-OFFBY5), "HUNTER HEIGHT < %d > ", cfg->HunterHeight);
    if(option == OPTION5) 
    {
        blinkoff();
    }
    
    mvprintw(LINES-OFFBY2, OFFBY2, "Use ARROWS to navigate  Press |ENTER| to select Press |ESC| to leave");
}
//4.4 START SCREEN FRONTEND
void drawstartingscreenUi(int option)
{
    DRAWSWALLOWSTARS();
    box(stdscr,0 ,0);
    //drawing ui of start screen
    if(option == OPTION0)
    {
        blinkon();
    }
    mvprintw(mainscreen1, (COLS/BY2), "START");
    if(option == OPTION0) 
    {
        blinkoff();
    }

    if(option == OPTION1)
    {
        blinkon();
    }
    mvprintw(mainscreen2, (COLS/BY2), "START FREE PLAY");
    if(option == OPTION1) 
    {
        blinkoff();
    }
    if(option == OPTION2)
    {
        blinkon();
    }
    mvprintw(mainscreen3, (COLS/BY2), "SETTINGS");
    if(option == OPTION2) 
    {
        blinkoff();
    }
    if(option == OPTION3)
    {
        blinkon();
    }
    mvprintw(mainscreen4, (COLS/BY2), "RANKINGS");
    if(option == OPTION3) 
    {
        blinkoff();
    }
    if(option == OPTION4)
    {
        blinkon();
    }
    mvprintw(mainscreen5, (COLS/BY2), "EXIT");
    if(option == OPTION4) 
    {
        blinkoff();
    }
    
    mvprintw(LINES-OFFBY2, OFFBY2, "Use ARROWS to navigate  Press |ENTER| to select Press |ESC| to leave");

}
void DRAWSWALLOWSTARS()
{
    mvprintw(swallowstarssigny, swallowstarssignx, "   _______          __     _      _      ______          __   _____ _______       _____   _____ ");
    mvprintw(swallowstarssigny+1, swallowstarssignx, "  / ____\\ \\        / /\\   | |    | |    / __ \\ \\        / /  / ____|__   __|/\\   |  __ \\ / ____|");
    mvprintw(swallowstarssigny+2, swallowstarssignx, " | (___  \\ \\  /\\  / /  \\  | |    | |   | |  | \\ \\  /\\  / /  | (___    | |  /  \\  | |__) | (___  ");
    mvprintw(swallowstarssigny+3, swallowstarssignx, "  \\___ \\  \\ \\/  \\/ / /\\ \\ | |    | |   | |  | |\\ \\/  \\/ /    \\___ \\   | | / /\\ \\ |  _  / \\___ \\ ");
    mvprintw(swallowstarssigny+4, swallowstarssignx, "  ____) |  \\  /\\  / ____ \\| |____| |___| |__| | \\  /\\  /     ____) |  | |/ ____ \\| | \\ \\ ____) |");
    mvprintw(swallowstarssigny+5, swallowstarssignx, " |_____/    \\/  \\/_/    \\_\\______|______\\____/   \\/  \\/     |_____/   |_/_/    \\_\\_|  \\_\\_____/ ");
}
//4.5 STATUS WINDOW PRINNTING
void printSTATwin(SWALLOW* s, WINDOW* status_win, int ch,CONFIG* cfg,SCORE* scoring)
{
    wclear(status_win); //clearing status
    box(status_win, 0, 0); //box for status

    mvwprintw(status_win, statwin2, OFFBY1, "Pressed button: %c", ch);
    mvwprintw(status_win, statwin3, cfg->WinWidth/BY2+OFFBY15, "Szybkosc: %d", s->speed);  //printing stat windows
    mvwprintw(status_win, statwin3, cfg->WinWidth/BY2, "Score: %d", s->score);
    mvwprintw(status_win, statwin3, cfg->WinWidth/BY2-OFFBY20, "Life: %d", s->life);
    mvwprintw(status_win, statwin4, cfg->WinWidth/BY2-OFFBY20, "Time Left: %d", s->timeLeft);
    if(*scoring->name)
    {
    mvwprintw(status_win, statwin3, OFFBY1, "Player: %s", scoring->name); 
    }
    s->timeacumulator += (FRAME_TIME / (float)SLEEP1000);

        if (s->timeacumulator >= 1.0) 
        {
            s->timeLeft--;              //updating time
            s->timeacumulator -= 1.0; 
        }
        if (s->invulnerableTimer > 0) 
        {
            s->invulnerableTimer--; 
        }
}
//5 MAIN GAMElOOP !!!
void MainGameLoop(SWALLOW* s,WINDOW* status_win,STAR stars[], CONFIG* cfg,HUNTER hunters[],ALBATROS* a,FOG* fog,SCORE* scoring)
    {
        int ch; //pressed key
        int get_ch=NOKEY;//addidional keyholder for smoth moving
        while(s->timeLeft>0 && s->life>0) //initalization of main game loop
        {
            //getting input
            ch = NOKEY;
            while((get_ch=getch())!=ERR)
            {
                ch=get_ch;
            }
            //exit game
            if (ch == QUIT) 
            {
                s->quit=0;
                break;
            }
            
            moveSwallow(s,cfg,ch,fog); //moving swallow
            speedSet(s,ch,cfg);     //changing speed

            spwanStar(stars,cfg); //spwaning stars
            spawnhunter(s,cfg,hunters);//spawning hunters
            spawnAlbatros(a,cfg);//spawning albatros

            moveStar(stars,cfg); //movin stars
            moveHunters(s,cfg,hunters);//moving hunters
            moveAlbatros(s,a,cfg,hunters);//moving albatros

            swallowhuntercolison(s,cfg,hunters);//swallow hunter closion handling
            checkstarpickup(s,stars,cfg); //chacking if player picked up
            updateFog(s,fog,cfg);   //fog logic
        
            if (s->score >= cfg->WinningScore) 
            {
                break;
            }
            wclear(s->win); //clearing screen

            drawStar(s->win, stars,cfg); //drawing star
            drawHunters(s->win,hunters);//drawing hunter
            drawAlbatros(s->win,a);//drawing albatros
            drawFog(s->win,fog,cfg);//drawing fog

            printSTATwin(s, status_win, ch,cfg,scoring);
        
            //draw swallow
            drawSwallow(s);

            wrefresh(s->win);       //screen refresh                //   ADD FUNCTION FOR THIS FIX THIS MESS
            wrefresh(status_win);   //refreshing status win

            //implamanting frame per second
            usleep(FRAME_TIME * SLEEP1000); 
        }
        loadbackup(cfg);// loading backup
    }
//6 SWALLOW FUNCTIONS
SWALLOW* SetupSwallow(WINDOW* w,CONFIG* cfg)
{
    SWALLOW* s = (SWALLOW*)malloc(sizeof(SWALLOW));

    //initalization of swallow into struct
    s->win = w;             //initalization of window where swallow is
    s->x = STARTSWALLOWX;              // start position X
    s->y = cfg->WinHight/BY2;               // start position Y
    s->dx = DEFOULTDXSWALLOW;              // defult direction X
    s->dy = DEFOULTDYSWALLOW;              // defult diretio Y
    s->speed = cfg->MinSpeed;  // Basic speed = 1
    s->width = swallowWidth;
    s->height = swallowHIGHT;
    s->currentFRAME = 0;
    s->frameDelay =0;
    strcpy(s->model[0], "/'V'\\");  // model of swallow
    strcpy(s->model[1], "-~V~-");
    s->quit=1;
    s->color = SWALLOWHIGHLIFE;           // defult swallow color
    s->score = 0;           // score of points
    s->life = cfg->Startlife;            // life of swallow
    s->invulnerableTimer = 0;
    s->inAlbatros =0;
    
    //return swallow
    return s;
}
void moveSwallow(SWALLOW* s,CONFIG* cfg, char ch,FOG* fog)
{   
    if (s->inAlbatros==1) 
    {
        return;
    }
    //change of vector of move depending on key
    if (ch == UP|| ch==UP2)
    {
        s->dy= NEGDY;
        s->dx= NULLDX;
    }
    else if (ch == DOWN || ch==DOWN2) 
    {
        s->dy= POSDY;
        s->dx= NULLDX;
    }
    else if (ch == LEFT || ch==LEFT2)
    {
        s->dy= NULLDY;
        s->dx= NEGDX;
    }
    else if (ch == RIGHT|| ch==RIGHT2) 
    {
        s->dy= NULLDY;
        s->dx= POSDX;
    }

    //initalizastion of changes of moving
    s->x += (s-> dx* s->speed);
    s->y += (s-> dy* s->speed);

    //colizion handling
    if (s->y < (int)fog->currentCUTY) s->y = (int)fog->currentCUTY;                           // hits roof
    if (s->x < (int)fog->currentCUTX) s->x = (int)fog->currentCUTX;                           // hits left wall
    if (s->y >= cfg->WinHight-(int)fog->currentCUTY) s->y = cfg->WinHight - (int)fog->currentCUTY-OFFY1;  // hits floor
    if (s->x >= (cfg->WinWidth-(int)fog->currentCUTX)-s->width) s->x = (cfg->WinWidth-(int)fog->currentCUTX) - s->width;              // hits right wall
}
void speedSet(SWALLOW* s, char ch,CONFIG* cfg)
{
    if(s->inAlbatros==NO)
    {
        if(ch==SPEEDUP ||ch==SPEEDUP2)
        {
            s->speed++;
        }
        else if(ch==SPEEDDOWN|| ch==SPEEDDOWN2)
        {
            s->speed--;
        }
        
        //speed cap
        if(s->speed>cfg->MaxSpeed) s->speed=cfg->MaxSpeed;
        if(s->speed<cfg->MinSpeed) s->speed=cfg->MinSpeed;
    }
}
void drawSwallow(SWALLOW* s)
{
     wattron(s->win, COLOR_PAIR(s->color));

    if (s->invulnerableTimer > 0 && s->invulnerableTimer % 2 != 0) 
    {
        s->frameDelay++;
        if(s->frameDelay == animationDELAY) {
            s->currentFRAME = (s->currentFRAME + 1) % swallowFRAMES;    //if inovurable it will blink by not displaying one frame of swallow
            s->frameDelay = 0;
        }
        return; 
    }
    mvwprintw(s->win, s->y , s->x, "%s", s->model[s->currentFRAME]);
    
    s->frameDelay++;
    if(s->frameDelay==animationDELAY)   //evry 2 refreshes swallow model changes by changing the current frame value
    {
        s->currentFRAME++;
        if(s->currentFRAME>swallowFRAMES-1)         //curent frame handling
        {
            s->currentFRAME=0;
        }
        s->frameDelay=0;
    }
    wattroff(s->win, COLOR_PAIR(s->color));
}
//7 STARS FUNCTIONS
void INITSTAR(STAR stars[],CONFIG* cfg)
{
    //setup of all stars
    for(int i=0;i<cfg->MaxStars;i++)
    {
        stars[i].active=NO;
        stars[i].model='*';
    }
}
void spwanStar(STAR stars[],CONFIG* cfg)
{
    //initialization of spawning stars
    if(rand() %cfg->StarRate==0)
    {
        for(int i=0;i<cfg->MaxStars;i++)
        {
            if(stars[i].active==NO)
            {
                stars[i].active=YES;
                stars[i].y=0;
                stars[i].x= (rand()%(cfg->WinWidth-OFFBY2))+OFFBY1;// 2 and 1 to not tuch border

                int rolltier=rand()%PREC100;

                if(rolltier<RATE3TIERSTAR)
                {
                    stars[i].points=POINTS3TIERSTAR;
                    stars[i].speed=cfg->StarTier3Speed;           //STATS FOR TIER 3 STAR
                    stars[i].color=STAR_RED_COLOR;
                }
                else if(rolltier<RATE2TIERSTAR)
                {
                    stars[i].points=POINTS2TIERSTAR;
                    stars[i].speed=cfg->StarTier2Speed;            //STATS FOR TIER 2 STAR
                    stars[i].color=STAR_L_YELLOW_COLOR;
                }
                else if(rolltier<RATE1TIERSTAR)
                {
                    stars[i].points=POINTS1TIERSTAR;
                    stars[i].speed=cfg->StarTier1Speed;            //STATS FOR TIER 1 STAR
                    stars[i].color=STAR_YELLOW_COLOR;
                }

                break;
            }
        }
    }
}
void moveStar(STAR stars[],CONFIG* cfg)
{
    for(int i=0;i<cfg->MaxStars;i++)
    {
        if(stars[i].active==YES)
        {
            stars[i].y+=stars[i].speed;
        }
        if(stars[i].y>=cfg->WinHight-OFFY1)
        {
            stars[i].active = NO;
        }
    }
    
}
void drawStar(WINDOW* win, STAR stars[],CONFIG* cfg)
{//drawing stars
    for(int i=0; i<cfg->MaxStars;i++)
    {
        if(stars[i].active==YES )
        {
            if(stars[i].y>cfg->WinHight-(cfg->WinHight/onefourofscreen)&&(rand()%2==1))
            {
                wattron(win, A_REVERSE);
            }
            wattron(win, COLOR_PAIR(stars[i].color));
            mvwprintw(win, stars[i].y, stars[i].x, "%c",stars[i].model);
            wattroff(win, COLOR_PAIR(stars[i].color));
            if(stars[i].y>cfg->WinHight-(cfg->WinHight/4))
            {
                wattroff(win, A_REVERSE);
            }
        }
    }
}
void checkstarpickup(SWALLOW* s, STAR stars[],CONFIG* cfg)
{
    int prevx= s->x - (s->dx * s->speed);
    int prevy= s->y - (s->dy * s->speed);
    //creating bounding box for chacking if swallow picked star
    int left= (prevx < s->x) ? prevx : s->x;//setting most left x point of x
    int right= (prevx > s->x) ? prevx : s->x;//setting most left x point of x
    right += s->width-1; //correcting on bigger model of swallow
    int top= (prevy < s->y) ? prevy : s->y;
    int bottom= (prevy > s->y) ? prevy : s->y;
    bottom += s->height - 1;//conidering bigger swallow model
    
    for(int i=0;i<cfg->MaxStars;i++)
    {
        if(stars[i].active==1)
        {
            int prevSTARy= stars[i].y - stars[i].speed;
            //checking box status conidering star
            bool overlapX = (stars[i].x>=left && stars[i].x<=right);
            bool overlapY = (stars[i].y>=top && prevSTARy<=bottom);
            if(overlapX==true && overlapY==true)
            {
                stars[i].active=NO;
                s->score+=stars[i].points;
            }
            
        }
    }
}
//8 HUNTER FUNCTIONS
void INITHUNTERS(HUNTER hunters[],CONFIG* cfg)
{
    for(int i=0; i<ABSOLUTEMAXHUNTERS; i++) 
    {
        hunters[i].active = NO;
        hunters[i].templete = cfg->HunterTemplate;//activating hunter logic
        hunters[i].dashed=NO;
    }
    hunters->timerscaling =cfg->hunterscaling;
}
void spawnhunter(SWALLOW* s,CONFIG* cfg,HUNTER hunters[])
{
    hunterscaling(cfg,hunters);
    if(rand()% cfg->HunterRate==0)
    {
        for(int i=0;i<ABSOLUTEMAXHUNTERS;i++)
        {
            if(hunters[i].active==NO)
            {
                hunters[i].active=YES;
                hunters[i].bounces=cfg->HunterBounces;              //generaiting random hunter size capped by config or setting input
                hunters[i].speed=cfg->HunterSpeed;
                hunters[i].width=(rand()%cfg->HunterWidth)+OFFBY1;
                hunters[i].height=(rand()%cfg->HunterHeight)+OFFBY1;
                if(hunters[i].height==1&&hunters[i].width==1)
                {
                    hunters[i].width=minhunter;                         //handling the one one model to be bigger
                }
                int huntersize = hunters[i].width*hunters[i].height;
                hunters[i].templete=cfg->HunterTemplate;
                hunters[i].timeafterspawn=0;                //initialazing hunter attribiutes
                hunters[i].state=sNORMAL;
                hunters[i].dashed=NO;
                if(huntersize>=huntersizetype2)
                {
                    hunters[i].color=HUNTERCOLORBIG;                    //applaying correct type of hunter depending on size
                    hunters[i].hunterdamage=cfg->HunterDamage*2;
                }
                else
                {
                    hunters[i].color=HUNTERCOLORSMALL;
                    hunters[i].hunterdamage=cfg->HunterDamage;
                }
                int edge = rand()%eges4;
                chooseedgestart(cfg,hunters,edge,i);//applaying other hunter attribiutes
                calculatehuntervector(s,cfg, hunters,i);
                break;
            }
        }
    }
}
void chooseedgestart(CONFIG* cfg,HUNTER hunters[],int edge,int i)
{
    if(edge==EDGETOP)
    {
        hunters[i].x = (rand() % (cfg->WinWidth-OFFBY4)) + OFFBY2; 
        hunters[i].y = 1;
    }
    else if(edge==EDGEBOTTOM)
    {
        hunters[i].x = (rand() % (cfg->WinWidth-OFFBY4)) + OFFBY2; //chosing where hunter will spawn top/bottom/rtght/left
        hunters[i].y = cfg->WinHight - OFFBY2 - hunters[i].height;
    }
    else if(edge==EDGELEFT)
    {
        hunters[i].x = 1; 
        hunters[i].y = (rand() % (cfg->WinHight-OFFBY4)) + OFFBY2;
    }
    else if(edge==EDGERIGHT)
    {
        hunters[i].x = COLS - OFFBY2 - hunters[i].width; 
        hunters[i].y = (rand() % (cfg->WinHight-OFFBY4)) + OFFBY2;
    }
}
void calculatehuntervector(SWALLOW* s,CONFIG* cfg,HUNTER hunters[],int i)
{
    int swallowx=s->x;
    int swallowy=s->y;
    if(s->dx>NULLDX)
    {
        swallowx+=HUNTERPREDICT;
        if(swallowx>cfg->WinWidth)
        {
            swallowx=cfg->WinWidth-OFFBY2;                       //detecting where the swallow is and based on this chosing vectro of hunter
        }
    }
    else if(s->dx<NULLDX)
    {
        swallowx-=HUNTERPREDICT;
        if(swallowx<0)
        {
            swallowx=minswallowoff2;
        }
    }
    if(s->dy>NULLDY)
    {
        swallowy+=HUNTERPREDICT;
        if(swallowy>cfg->WinHight)
        {
            swallowy=cfg->WinHight-OFFBY2;
        }
    }
    else if(s->dy<NULLDY)
    {
        swallowy-=HUNTERPREDICT;
        if(swallowy<0)
        {
            swallowy=minswallowoff2;
        }
    }
    int vectorx=swallowx-hunters[i].x;
    int vectory=swallowy-hunters[i].y;

    float length = sqrt(vectorx*vectorx + vectory*vectory);

    if(length != 0) 
    {
        hunters[i].dx = vectorx / length;
        hunters[i].dy = vectory / length;
    } 
    else 
    {
        hunters[i].dx = POSDX; hunters[i].dy = NULLDY;
    }
}
void moveHunters(SWALLOW* s,CONFIG* cfg, HUNTER hunters[])
{
    //moving all hunters that are active
    for(int i=0; i<ABSOLUTEMAXHUNTERS; i++)
    {
        if(hunters[i].active)
        {
            hunters[i].timeafterspawn++;

            int firstdisx=s->x-hunters[i].x;
            int firstdisy=s->y-hunters[i].y;
            float firstdis=sqrt(firstdisx*firstdisx + firstdisy*firstdisy);
            if(hunters[i].state==sNORMAL)
            {
                hunterNormal(s,cfg,hunters,i,firstdis);
            }
            if(hunters[i].state==sWAITING)
            {
                hunterWaiting(s,cfg,hunters,i);
            }
            if(hunters[i].state==sDash)
            {
                hunters[i].waiting--;
                hunters[i].x += hunters[i].dx * DASHSPEED;
                hunters[i].y += hunters[i].dy * DASHSPEED;//logiv for hunter dash state
                if(hunters[i].waiting<=0)
                {
                    hunters[i].state=sNORMAL;
                    hunters[i].dashed=YES;
                }
            }
            dedectbounce(cfg,hunters,i);
        }
    }
}
void hunterNormal(SWALLOW* s,CONFIG* cfg, HUNTER hunters[],int i,float firstdis)
{
    hunters[i].x += hunters[i].dx * hunters[i].speed;
    hunters[i].y += hunters[i].dy * hunters[i].speed;

    int seconddisx=s->x-hunters[i].x;
    int seconddisy=s->y-hunters[i].y;           //moving while hunter state is normal
    float secondtdis=sqrt(seconddisx*seconddisx + seconddisy*seconddisy);

    if(secondtdis>firstdis && hunters[i].timeafterspawn>cfg->huntercheckingdash && hunters[i].dashed==0)
    {
        hunters[i].state = sWAITING;
        hunters[i].waiting=cfg->huntercheckingdash;
    }
}
void hunterWaiting(SWALLOW* s,CONFIG* cfg, HUNTER hunters[],int i)
{
    hunters[i].waiting--;
    int diffx=s->x-hunters[i].x;
    int diffy=s->y-hunters[i].y;
    float detect=sqrt(diffx*diffx + diffy*diffy);

    if(detect>0)
    {
        hunters[i].dx = diffx / detect;
        hunters[i].dy = diffy / detect;                 //hunter waiting when state is wait
    }
    if(hunters[i].waiting<=0)
    {
        hunters[i].state=sDash;
        hunters[i].waiting=cfg->HunterDashTime;
    }
}
void dedectbounce(CONFIG* cfg, HUNTER hunters[],int i)
{
    int hit = NO;
    if(hunters[i].x+cfg->HunterWidth>cfg->WinWidth)
    {
        hit=YES;
        hunters[i].dx*=oppostevect;
        hunters[i].x=cfg->WinWidth-cfg->HunterWidth;
    }
    if(hunters[i].x<0)
    {
        hit=YES;
        hunters[i].dx*=oppostevect;
        hunters[i].x=0;                                     //dedecting screen end to bounce
    }
    if(hunters[i].y+cfg->HunterHeight>cfg->WinHight)
    {
        hit=YES;
        hunters[i].dy*=oppostevect;
        hunters[i].y=cfg->WinHight-cfg->HunterHeight;
    }
    if(hunters[i].y<0)
    {
        hit=YES;
        hunters[i].dy*=oppostevect;
        hunters[i].y=0;
    }
    if(hit)
    {
        hunters[i].bounces--;                   //when hit bounces of hunter dicreses 
        if(hunters[i].bounces==0)
        {
            hunters[i].active=0;
        }
    }
}
void drawHunters(WINDOW* win, HUNTER hunters[])
{//drawing hunters
    for(int i=0; i<ABSOLUTEMAXHUNTERS; i++)
    {
        if(hunters[i].active)
        {
            wattron(win, COLOR_PAIR(hunters[i].color));
            
            for(int h=0; h < hunters[i].height; h++)
             {
                for(int w=0; w < hunters[i].width; w++) 
                {
                    mvwprintw(win, (int)hunters[i].y + h, (int)hunters[i].x + w, "%c", hunters[i].templete);
                }
            }
            
            mvwprintw(win, (int)hunters[i].y - OFFBY1, (int)(hunters[i].x+(hunters[i].width/BY2)), "%d", hunters[i].bounces);
            
            wattroff(win, COLOR_PAIR(hunters[i].color));
        }
    }
}
void swallowhuntercolison(SWALLOW* s, CONFIG* cfg, HUNTER hunters[])
{
    if(s->invulnerableTimer>0)
    {
        return;
    }
    //swallow box
    int sprevx= s->x - (s->dx * s->speed);
    int sprevy= s->y - (s->dy * s->speed);
    //creating bounding box for chacking if swallow cossed with hunter
    int sleft= (sprevx < s->x) ? sprevx : s->x;//setting most left x point of x
    int sright= (sprevx > s->x) ? sprevx : s->x;//setting most left x point of x
    sright += s->width-1; //correcting on bigger model of swallow
    int stop= (sprevy < s->y) ? sprevy : s->y;
    int sbottom= (sprevy > s->y) ? sprevy : s->y;
    sbottom += s->height - 1;//conidering bigger swallow model

    for(int i = 0; i < ABSOLUTEMAXHUNTERS; i++)
    {
        if(hunters[i].active == YES)
        {
            //Hunter box
            int hprevx= hunters[i].x - (hunters[i].dx * hunters[i].speed);
            int hprevy= hunters[i].y - (hunters[i].dy * hunters[i].speed);
            //creating bounding box for chacking if Hunter picked star
            int hleft= (hprevx < hunters[i].x) ? hprevx : hunters[i].x;//setting most left x point of x
            int hright= (hprevx > hunters[i].x) ? hprevx : hunters[i].x;//setting most left x point of x
            hright += hunters[i].width-1; //correcting on bigger model of Hunter
            int htop= (hprevy < hunters[i].y) ? hprevy : hunters[i].y;
            int hbottom= (hprevy > hunters[i].y) ? hprevy : hunters[i].y;
            hbottom += hunters[i].height - 1;//conidering bigger Hunter model

            //if boxes are in the same place initialize life loss
            if (sleft <= hright && sright >= hleft && stop <= hbottom && sbottom >= htop)
            {
                s->life -= hunters[i].hunterdamage;
                s->invulnerableTimer=cfg->invulnerable;
                if(s->life<=cfg->Startlife/BY2)
                {
                    s->color=SWALLOWLOWLIFE;//changin color of swallow if life is below half
                }
            }
        }
    }
}
void hunterscaling(CONFIG* cfg,HUNTER hunters[])
{
    if (hunters->timerscaling>0) 
    {
        hunters->timerscaling--;
        if(hunters->timerscaling==0)
        {
            hunters->timerscaling=cfg->hunterscaling;           //logic for scailing hunter bounces and spawn rate with time 

                cfg->HunterBounces++;
            if(cfg->HunterRate>ABSOLUTEMINHUNTERRATE)
            {
                cfg->HunterRate-=HUNTERRATECHANGE2;
            }
        }
    }
}
//9 ALBATROS FUNCTIONS
void initAlbatros(ALBATROS* a)
{
    a->active=NO;                           //activating albatros
    a->carrying=NOTINALABATROS;
    strcpy(a->model, "<ALBATROS>");
    a->awitdh = ALBATROSMODELWIDTH; 
    a->aheight = ALBATROSMODELHIGHT;
    a->color=ALBATROSCOLOR;
}
void spawnAlbatros(ALBATROS* a,CONFIG* cfg)
{//spawnig albatros taxi
    if(a->active == NO)
    {
        if(rand()%cfg->albatrosRate==0)
        {
            a->active=YES;
            a->carrying=NOTINALABATROS;
            a->speed = cfg->albatrosSpeed;
            a->y = (rand() % (cfg->WinHight - OFFBY10)) + OFFBY5;//10 and 5 to add buffor on y axis

            if(rand()%2==SPAWNRIGHT)
            {
                a->x = OFFBY2;   //2 to spawn within screen            
                a->dx = albatrosvector;
            }
            else                                
            {
                a->x = cfg->WinWidth - OFFBY5; 
                a->dx = -albatrosvector;
            }
        }
    }
}
void moveAlbatros(SWALLOW* s,ALBATROS* a,CONFIG* cfg,HUNTER hunters[])
{//moving albatros
    if(a->active==YES)
    {
        if(a->carrying==NOTINALABATROS)         //logic for not carrying
        {
            a->x +=a->dx* a->speed;

            if(a->x<0||a->x>cfg->WinWidth)
            {
                a->active=0;
            }
            listenforcarrying(s,a,cfg,hunters);
        }
        else if(a->carrying==INALBATROS)        //logic for carrying
        {   
            serchagainifsafe(hunters,cfg,a);    //serching constatly for save space   
            float diffx = a->targex - a->x;
            float diffy = a->targety - a->y;
            float dist = sqrt(diffx*diffx + diffy*diffy);
            if(dist<2.0)
            {
                a->active=NOTINALABATROS;       //if close to the safe space swallow gets out and is invulnerable
                a->carrying=NOTINALABATROS;
                s->inAlbatros=NOTINALABATROS;
                s->invulnerableTimer=cfg->invulnerable;
                return;
            }
            a->x +=a->dx* (cfg->albatrosSpeedWhileCarrying);
            a->y +=a->dy* (cfg->albatrosSpeedWhileCarrying);        //going to save space

            s->x=a->x;
            s->y=a->y+OFFBY1;//attaching swallow under taxi
        }
    }
}
void listenforcarrying(SWALLOW* s,ALBATROS* a,CONFIG* cfg,HUNTER hunters[])
{
    //swallow box
    int sprevx= s->x - (s->dx * s->speed);
    int sprevy= s->y - (s->dy * s->speed);
    //creating bounding box for chacking if swallow cossed with albatros
    int sleft= (sprevx < s->x) ? sprevx : s->x;//setting most left x point of x
    int sright= (sprevx > s->x) ? sprevx : s->x;//setting most left x point of x
    sright += s->width-1; //correcting on bigger model of swallow
    int stop= (sprevy < s->y) ? sprevy : s->y;
    int sbottom= (sprevy > s->y) ? sprevy : s->y;
    sbottom += s->height - 1;//conidering bigger swallow model

    //Albatros box
    int aprevx= a->x - (a->dx * a->speed);
    int aprevy= a->y - (a->dy * a->speed);
    
    int aleft= (aprevx <a->x) ? aprevx : a->x;//setting most left x point of x
    int aright= (aprevx > a->x) ? aprevx : a->x;//setting most left x point of x
    aright += a->awitdh -1; //correcting on bigger model of Hunter
    int atop= (aprevy < a->y) ? aprevy : a->y;
    int abottom= (aprevy > a->y) ? aprevy :a->y;
    abottom += a->aheight - 1;//conidering bigger Hunter model

    //if boxes are in the same place initialize carrying
    if (sleft <= aright && sright >= aleft && stop <= abottom && sbottom >= atop)
    {
        a->carrying = INALBATROS;
        s->inAlbatros = INALBATROS;
        s->invulnerableTimer =INVULNERABLESWALLOWWHILECARRYING;
        serchforsafe(hunters,cfg,a);//serching for savee space
    }
}
void serchforsafe(HUNTER hunters[],CONFIG* cfg,ALBATROS* a)
{
    int safe=0;
    int attempt=0;//capted attepends for serching
    while(attempt<cappedatemp&&safe==0)
    {
        int randomx = (rand() % (cfg->WinWidth - OFFBY10)) + OFFBY5;                //selecting random x and y
        int randomy = (rand() % (cfg->WinHight - OFFBY10)) + OFFBY5;

        safe=YES;       //asuming that its safe

        for(int i = 0; i < ABSOLUTEMAXHUNTERS; i++)
        {
            if(hunters[i].active)
            {
                int diffx = randomx - hunters[i].x;
                int diffy = randomy - hunters[i].y;
                int dist = sqrt(diffx*diffx + diffy*diffy);             //checking if its realy safe

                if(dist < safedist) 
                {
                    safe = NO;          //if some hunter is close its not safe
                    break;   
                }
            }
        }
        if(safe==YES)
        {
            a->targex=randomx;
            a->targety=randomy;
            float diffx = a->targex - a->x;             //is still safe set target x and y to go and calculate vectors
            float diffy = a->targety - a->y;
            float dist = sqrt(diffx*diffx + diffy*diffy);
            if(dist!=0)
            {
                a->dx=diffx/dist;
                a->dy=diffy/dist;
            }
            break;
        }
        attempt++;
    }
    if(safe==NO)
    {
        a->targex = cfg->WinWidth / BY2;          //if no safe spot was found go to middle
        a->targety = cfg->WinHight / BY2;
    }
}
void serchagainifsafe(HUNTER hunters[],CONFIG* cfg,ALBATROS* a)
{
    int safe=YES;
    for(int i = 0; i < ABSOLUTEMAXHUNTERS; i++)
    {
        if(hunters[i].active)
        {
            int diffx = a->targex - hunters[i].x;
            int diffy = a->targety - hunters[i].y;
            int dist = sqrt(diffx*diffx + diffy*diffy);     
                                                                //chacking if still is safe
            if(dist < safedist) 
            {
                safe = NO; 
                break;   
            }
        }
    }
    if(safe==NO)                // if not search again
    {
        serchforsafe(hunters,cfg,a);
    }
}
void drawAlbatros(WINDOW* win, ALBATROS* a)
{
    if(a->active)
    {
        wattron(win, COLOR_PAIR(a->color));
        wattron(win, A_BOLD);                                   //drawing albatros
        mvwprintw(win, (int)a->y, (int)a->x, "%s", a->model); 
        wattroff(win, A_BOLD);
        wattroff(win, COLOR_PAIR( a->color));
    }
}
//10 FOG FUNCTIONS
void initFog(FOG* fog,CONFIG*cfg)
{
    fog->active=NO;
    fog->timer=0;
    fog->currentCUTX=0;
    fog->currentCUTY=0;                                                 //seting basic fog atrribiutes
    fog->targetCutX=(float)cfg->WinWidth*(cfg->fogcutProcent/PREC100);
    fog->targetCutY=(float)cfg->WinHight*(cfg->fogcutProcent/PREC100);
    fog->fogmodel='~';
}
void updateFog(SWALLOW* s,FOG* fog,CONFIG*cfg)
{
    if(fog->active==NO)         //if fog not active try to trigger the event
    {                           
        if(rand()%cfg->fogRate==0)
        {
            fog->active=1;
            fog->timer=cfg->fogDuration;
            wbkgd(s->win, COLOR_PAIR(NIGHTCOLOR));          //if event triggered than change bacground and color palet
            cfg->currentWincolor=COLOR_BLUE;
            colorchange(s,s->win,cfg);
        }
        if(fog->active==NO)
        {
            wbkgd(s->win, COLOR_PAIR(PLAY_COLOR));
            cfg->currentWincolor=LIGHTBLUE;
            colorchange(s,s->win,cfg);
            if(fog->currentCUTX>0)                          //if not triggered and some of the fog is left on screeen shrink it
            {
                fog->currentCUTX-= 0.5;
            }
            if(fog->currentCUTY>0)
            {
                fog->currentCUTY-= 0.5;
            }
        }
    }
    else if(fog->active==YES)
    {
        fog->timer--;                               //if fog is active than expand it until reaching target size
        if(fog->currentCUTX<fog->targetCutX)
        {
            fog->currentCUTX+= 0.5;
        }
        if(fog->currentCUTY<fog->targetCutY)
        {
            fog->currentCUTY+= 0.5;
        }
        if (fog->timer <= 0) 
        {
            fog->active=NO;         //if time of the fog event runes into 0 switch off fog event
        }
    }
}
void drawFog(WINDOW* win,FOG* fog,CONFIG*cfg)
{
    wattron(win, A_DIM);
    for(int y=0;y<cfg->WinHight;y++)
    {
        for(int x=0;x<(int)fog->currentCUTX;x++)
        {
            mvwprintw(win,y,x,"%c",fog->fogmodel);
        }
        for(int x=cfg->WinWidth-fog->currentCUTX;x<cfg->WinWidth;x++)
        {
            mvwprintw(win,y,x,"%c",fog->fogmodel);
        }
    }
    for(int y=0;y<fog->currentCUTY;y++)                         //drawing fog as a given model in initfog from up/down/left/right
    {
        for(int x=0;x<cfg->WinWidth;x++)
        {
            mvwprintw(win,y,x,"%c",fog->fogmodel);
        }
    }
    for(int y=cfg->WinHight-fog->currentCUTY;y<cfg->WinHight;y++)
    {
        for(int x=0;x<cfg->WinWidth;x++)
        {
            mvwprintw(win,y,x,"%c",fog->fogmodel);
        }
    }
    wattroff(win, A_DIM);
}
//11 GAME LOGIC FUNCTIONS
void entername(char* name,SCORE* scoring)
{
    int index=0;
    int ch;
    for(int i=0; i<MAXIMUMNAME-1; i++) 
        {
            name[i] = '_';//place holders
        }
        name[MAXIMUMNAME-1] = '\0';//ending string 
    nodelay(stdscr, FALSE);
    while(1)
    {
        wclear(stdscr);
        box(stdscr, 0, 0);
        mvprintw(ROWS/BY2, COLS/BY2-OFFBY2, "ENTER YOUR NAME");
        mvprintw(ROWS/BY2-OFFBY2, COLS/BY2, "%s", name);//writing current name
        mvprintw(ROWS-OFFBY2, COLS/BY2-OFFBY7, "Type letters, ENTER to confirm");
        refresh();

        ch=getch();
        if(ch==START)
        {
            if(index>0)             // if enter pressed and name is biggeer than 0 continue and remember name
            {
               break; 
            }
        } 
        if(ch==BACKSPACE)
        {
            if(index>0)
            {
                index--;                       //if backspace is pressed then erease one leter
                name[index] = '_';
            }
        }
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        {
            if (index < MAXIMUMNAME-1)
            {
                name[index]=ch;                             //if char for a to z is presed remeber it
                index++;
            }
        }
    }
    for(int i=index; i<MAXIMUMNAME-1; i++) 
    {
        name[i] = ' ';              //for empty spaces change _ to space
    }
    nodelay(stdscr, TRUE);

    strcpy(scoring->name,name);   //remember space into data struct
}
void resetGame(SWALLOW* s,CONFIG* cfg)
{         
    s->y = cfg->WinHight/BY2; 
    s->x = STARTSWALLOWX;              
    s->dx = DEFOULTDXSWALLOW;              
    s->dy = DEFOULTDYSWALLOW;              
    s->speed = cfg->MinSpeed;  
    s->width = swallowWidth;        //Reset all of swallow
    s->height = swallowHIGHT; 
    s->score = 0;           
    s->life = cfg->Startlife;
    s->quit=1;           
}
void checkWinLose(SWALLOW* s, CONFIG* cfg, STAR stars[], HUNTER hunters[], FOG* fog, ALBATROS* a,SCORE* score,WINDOW* st_win)
{
    gameoveranim(s,cfg,stars,hunters,fog,a,score,st_win);//function for end game screen
        calculatescore(score,s,cfg);
        mvwprintw(s->win, (cfg->WinHight / BY2) + OFFBY1, (cfg->WinWidth / BY2) - OFFBY10, "Your score: %d", score->score);

        wattron(s->win,A_BLINK);
        mvwprintw(s->win, (cfg->WinHight / BY2) + OFFBY10, (cfg->WinWidth / BY2) - OFFBY15, "Press any key to continue");
        wattroff(s->win,A_BLINK);

        updateRankings(score);// updating rankings

        wrefresh(s->win);
        usleep(SLEEP3000000);

        nodelay(stdscr, TRUE); 
        while(getch() != ERR);//waitingg for input do end
        nodelay(stdscr, FALSE);
        getch(); 
        nodelay(stdscr, TRUE);
}
void gameoveranim(SWALLOW* s, CONFIG* cfg, STAR stars[], HUNTER hunters[], FOG* fog, ALBATROS* a,SCORE* score,WINDOW* st_win)
{
    if(s->life==0||s->timeLeft<=0)
        {
           playfallinganimation(s, cfg, stars,hunters, fog, a);//drawing gowing down nimation if player lost
        }
        GAMEOVERaniamtion(s->win,st_win, cfg,s);//blac curatins to over screen
        wbkgd(s->win, COLOR_PAIR(ENDSCREENCOLOR));
        wbkgd(st_win, COLOR_PAIR(ENDSCREENCOLOR));
        wclear(s->win);
        mvwprintw(s->win, cfg->WinHight/BY2 -OFFBY2, (cfg->WinWidth / OFFBY2) - OFFBY10, "GAME OVER");
        if(s->score>=cfg->WinningScore)//depending on reason display apprpeite end screen
        {
            mvwprintw(s->win, cfg->WinHight / BY2, (cfg->WinWidth / BY2) - OFFBY10, "CONGRATULATIONS, YOU WON!");
            mvwprintw(s->win, (cfg->WinHight / BY2) +BY2 , (cfg->WinWidth / BY2) - OFFBY10, "Your time: %d s", (cfg->Timer-s->timeLeft));
        }
        else if(s->timeLeft<=0)
        {
            mvwprintw(s->win, cfg->WinHight / BY2, (cfg->WinWidth / BY2) - OFFBY10, "YOU RUN OUT OF TIME! TRY AGAIN");
        }
        else if(s->life==0)
        {
            mvwprintw(s->win, cfg->WinHight / BY2, (cfg->WinWidth / BY2) - OFFBY10, "YOU DIED! TRY AGAIN");
        }
}
//12 DIFFICULTY FNCTIONS
void selecDificulty(SCORE* scoring)
{
    scoring->difficulty = NORMAL;//selecting dificulty logic similar to setting ui and backend
    int ch;
    nodelay(stdscr, FALSE);
    while(1)
    {   wclear(stdscr);
        box(stdscr, 0, 0);
        mvprintw(ROWS/BY2-OFFBY5, COLS/BY2-OFFBY3 , "SELECT DIFFICULTY");
        if(scoring->difficulty==EASY)
        {
            blinkon();
        }
        mvprintw(ROWS/BY2, COLS/BY2 - OFFBY15, "   EASY   ");
        if(scoring->difficulty==EASY)
        {
            blinkoff();
        }
        if(scoring->difficulty==NORMAL)
        {
            blinkon();
        }
        mvprintw(ROWS/BY2, COLS/BY2 , "   NORMAL   ");
        if(scoring->difficulty==NORMAL)
        {
            blinkoff();
        }
        if(scoring->difficulty==HARD)
        {
            blinkon();
        }
        mvprintw(ROWS/BY2, COLS/BY2 + OFFBY15, "   HARD   ");
        if(scoring->difficulty==HARD)
        {
            blinkoff();
        }
        refresh();
        ch=getch();
        if(ch==KEY_LEFT)
        {
            scoring->difficulty--;
            if(scoring->difficulty<EASY)
            {
                scoring->difficulty=HARD;
            }
        }
        if(ch==KEY_RIGHT)
        {
            scoring->difficulty++;
            if(scoring->difficulty>HARD)
            {
                scoring->difficulty=EASY;
            }
        }
        if(ch==START)
        {
            break;
        }
    }
    nodelay(stdscr, TRUE);
}
void applaydificulty(SCORE* scoring,CONFIG*cfg,CONFIG *bcfg)
{
    loadbasicconfig(cfg, bcfg);                 //aplaying dificulty based on choosing by multiplaying based config for mult set to difficulty
    scoring->MULT=NORMAL;
    if(scoring->difficulty==EASY)
    {
        scoring->MULT=EASYMULT;
        cfg->albatrosRate*=EASYMULT;
        cfg->HunterBounces*=EASYMULT;
        cfg->HunterSpeed=(float)cfg->HunterSpeed*EASYMULT;
        cfg->HunterRate/=EASYMULT;
        cfg->StarRate*=EASYMULT;
        cfg->WinningScore*=EASYMULT;
        cfg->huntercheckingdash/=EASYMULT;
        cfg->hunterscaling/=EASYMULT;
        cfg->Startlife/=EASYMULT;
        cfg->Timer/=EASYMULT;
    }
    else if(scoring->difficulty==HARD)
    {
        scoring->MULT=HARDMULT;
        cfg->albatrosRate*=HARDMULT;
        cfg->HunterBounces*=HARDMULT;
        cfg->HunterSpeed*=HARDMULT;
        cfg->HunterRate/=HARDMULT;
        cfg->StarRate*=HARDMULT;
        cfg->WinningScore*=HARDMULT;
        cfg->huntercheckingdash/=HARDMULT;
        cfg->hunterscaling/=HARDMULT;
        cfg->Startlife/=HARDMULT;
        cfg->Timer/=HARDMULT;
    }
}
//13 RANKING FUNCTIONS
void updateRankings(SCORE* score)
{
    int count=0;
    FILE* file = fopen("ranking.txt", "r");
    if(file!=NULL)
    {
        fscanf(file, "%d", &count);
        fclose(file);                              //reading number of ranked scores
    }
   
    RANKING*rank=(RANKING*)malloc(sizeof(RANKING)*(count+1));   //alocating array for sorting

    if (rank == NULL)
    {
        return; 
    }

    file = fopen("ranking.txt", "r");
    if(file!=NULL)
    {
        int dummy;
        fscanf(file, "%d", &dummy);// dummy for skipping number on the start of the file

        for (int i = 0; i < count; i++) 
        {
            fscanf(file, "%s %d", rank[i].name, &rank[i].score);        //reading all rankings into array
        }
        fclose(file);  
    }

    if(score->score>0) 
    {
        int k = 0;
        while(score->name[k] != '\0' && k < MAXIMUMNAME-1) 
        {
            rank[count].name[k] = score->name[k];
            k++;                                            //adding at the end of the array new score if bigger than 0
        }

        rank[count].score = (int)score->score;

        count++;
    }
    
    sort(rank,count);       //sorting array

    file=fopen("ranking.txt", "w");
    if(file==NULL)
    {
        return;
    }
    fprintf(file, "%d\n", count);               //writing in  number of rankings 
    for (int i = 0; i < count; i++) 
    {
        fprintf(file, "%s %d\n", rank[i].name, rank[i].score);      //writing in all of rankinga into rankingtxt
    }
    fclose(file);
    free(rank);
}
void sort(RANKING rank[], int count)
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
            if(rank[j].score<rank[j+1].score)//simple sort algoritm by using temp veriable
            {
                RANKING temp= rank[j];
                rank[j]=rank[j+1];
                rank[j+1]=temp;
            }
        }
    }
}
void showRanking()
{
    FILE* file=fopen("ranking.txt", "r");
    if(file==NULL)
    {
        return;//opening saved ranking file
    }
    int count=0;

    wclear(stdscr);
    box(stdscr, 0, 0);
    attron(A_BOLD);
    mvprintw(ranking1, COLS/BY2 - OFFBY7, "--- HALL OF FAME ---");
    attroff(A_BOLD);
    mvprintw(ranking2, COLS/BY2 - OFFBY10, "RANK   NAME          SCORE");
    mvprintw(ranking3, COLS/BY2 - OFFBY10, "--------------------------");

    fscanf(file, "%d", &count); //reading in number of ranked scores
    
    int limit=(count<maxrankingshow) ? count : maxrankingshow;// caping number of displayed rankings to 25 or number of scores if lower

    char name[MAXIMUMNAME];
    int score;

    for (int i=0;i<limit;i++)           //printing names and scores on screan
    {
        fscanf(file, "%s %d", name, &score);
        if(i == 0) attron(COLOR_PAIR(TOP1COLOR)); 
        mvprintw(ranking4 + i, COLS/BY2 - OFFBY10, "#%2d    %-12s  %d", i+1, name, score);
        if(i == 0) attroff(COLOR_PAIR(TOP1COLOR));
    }
    fclose(file);

    mvprintw(LINES-OFFBY3, COLS/BY2 - OFFBY10, "Press any key to return");            
    refresh();
    usleep(SLEEP3000000);
    nodelay(stdscr, FALSE);     
    getch();                //waiting for some key to continue
    nodelay(stdscr, TRUE);
}
//14 SCORING CALCULATION
void calculatescore(SCORE* score,SWALLOW* s,CONFIG*cfg)
{
    if(s->score>= cfg->WinningScore)
    {
        score->score=(long)(s->life*s->score*score->MULT*s->timeLeft);//calculating score
        if(score->difficulty==HARD)
        {
            score->score*=BONUSHARDMULT;
        }
        if(score->difficulty==EASY)
        {
            score->score*=BONUEASYMULT;
        }
    }
    else
    {
        score->score=0;
    }
}
//15 AIMATION FUNCTIONS
void playfallinganimation(SWALLOW* s, CONFIG* cfg, STAR stars[], HUNTER hunters[], FOG* fog, ALBATROS* a)
{
    while(s->y < cfg->WinHight)//playing this animation until swallow is off the screen
    {
        wclear(s->win);

        drawStar(s->win, stars, cfg);
        drawHunters(s->win, hunters);
        drawAlbatros(s->win, a);
        drawFog(s->win, fog, cfg);                              //the animation when swallow lost all other actors stop in current position and swallow is droping

        s->y += fallingdown; //simple going down

        wattron(s->win, COLOR_PAIR(SWALLOWHIGHLIFE));
        wattron(s->win, A_BOLD);
        mvwprintw(s->win, (int)s->y, (int)s->x, "%s", s->model[0]);
        wattroff(s->win, A_BOLD);
        wattroff(s->win, COLOR_PAIR(SWALLOWHIGHLIFE));

        wrefresh(s->win);
        usleep(SLEEP50000); 
    }
}
void GAMEOVERaniamtion(WINDOW* win,WINDOW* st_win,CONFIG* cfg,SWALLOW* s)
{//changing screen for black color
    wbkgd(st_win, COLOR_PAIR(ENDSCREENCOLOR));      //blacking out stat win
    wclear(st_win);
    wrefresh(st_win);
    wattrset(win, COLOR_PAIR(ENDSCREENCOLOR));//setting new colors for chars space to imitate black curtaines
    
    int center = cfg->WinHight / BY2;

    for(int i = 0; i <= center; i++)
    {
        mvwhline(win, i, 0, ' ', cfg->WinWidth);        //printing from up and down until it reaches center (whole lines printing)
        
        mvwhline(win, cfg->WinHight - OFFBY1 - i, 0, ' ', cfg->WinWidth);
        
        wrefresh(win);
        usleep(SLEEP20000); //for smothnes
    }
    
    wbkgd(win, COLOR_PAIR(ENDSCREENCOLOR)); 
    wclear(win);
    wrefresh(win);
    
    usleep(SLEEP200000);//for smothnes
}
//ADDITIONAL FUNCTIONS
void blinkon()
{
    wattron(stdscr, A_REVERSE); 
    wattron(stdscr, A_BLINK);
}
void blinkoff()
{
    wattroff(stdscr, A_REVERSE);
    wattroff(stdscr, A_BLINK);
}
void colorchange(SWALLOW* s,WINDOW* status_win,CONFIG* cfg)
{
    init_pair(STAR_YELLOW_COLOR, COLOR_YELLOW, cfg->currentWincolor);
    init_pair(STAR_L_YELLOW_COLOR, LIGHTYELLOW, cfg->currentWincolor);
    init_pair(STAR_RED_COLOR, LIGHTRED, cfg->currentWincolor);
    init_pair(HUNTERCOLORSMALL, COLOR_GREEN,cfg->currentWincolor);
    init_pair(HUNTERCOLORBIG, LIGHTRED,cfg->currentWincolor);       //function for changing color demending on color of the sky(diffrent for fog)
    init_pair(SWALLOWHIGHLIFE, LIGHTWHITE, cfg->currentWincolor);
	init_pair(SWALLOWLOWLIFE, LIGHTRED, cfg->currentWincolor);
    init_pair(ALBATROSCOLOR, COLOR_WHITE, cfg->currentWincolor);
}
void colorset(SWALLOW* s,WINDOW* status_win,CONFIG* cfg)
{
    cfg->currentWincolor=LIGHTBLUE;
    // colors paterns for win setup
    init_pair(PLAY_COLOR, COLOR_WHITE, LIGHTBLUE);
	init_pair(STAT_COLOR, COLOR_WHITE, DARK_GRAY);
    // color paterns for stars
    init_pair(STAR_YELLOW_COLOR, COLOR_YELLOW, cfg->currentWincolor);
    init_pair(STAR_L_YELLOW_COLOR, LIGHTYELLOW, cfg->currentWincolor);
    init_pair(STAR_RED_COLOR, LIGHTRED, cfg->currentWincolor);
    init_pair(HUNTERCOLORSMALL, COLOR_GREEN,cfg->currentWincolor);
    init_pair(HUNTERCOLORBIG, LIGHTRED,cfg->currentWincolor);
    //color for top1
    init_pair(TOP1COLOR,LIGHTYELLOW,COLOR_BLACK);
    //color for nightfall
    init_pair(NIGHTCOLOR, COLOR_WHITE,COLOR_BLUE);
    //swallow colors
    init_pair(SWALLOWHIGHLIFE, LIGHTWHITE, cfg->currentWincolor);
	init_pair(SWALLOWLOWLIFE, LIGHTRED, cfg->currentWincolor);


    init_pair(ENDSCREENCOLOR, LIGHTWHITE, COLOR_BLACK);

    //alabtros color
    init_pair(ALBATROSCOLOR, COLOR_WHITE, cfg->currentWincolor);
    // initialization of colors
    wbkgd(s->win, COLOR_PAIR(PLAY_COLOR));       
    wbkgd(status_win, COLOR_PAIR(STAT_COLOR));  
}
void INITTIME(SWALLOW* s,CONFIG* cfg)
{
    s->timeLeft= cfg->Timer;
    s->time=time(NULL);// starting counting
    s->timeacumulator= 0.0;//acumuleiting s
}
void seedInit(CONFIG* cfg)
{
    if(cfg->Seed>0)
    {
        srand(cfg->Seed);
    }
    else
    {
        srand(time(NULL));
    }
}