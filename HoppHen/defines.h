#include <QtDebug>

#define W_WIDTH			600
#define W_HEIGHT		800

//Player
#define P_WIDTH			50
#define P_HEIGHT		50
#define P_START_POS_X	((W_WIDTH / 2) - (P_WIDTH / 2))
#define P_START_POS_Y	(W_HEIGHT - 200) //Ändra till något lämpligt
#define P_DAMP_INTERVAL	0.2

//Platform
#define PF_WIDTH		100 //Tog från c#-projektet 
#define PF_HEIGHT		20
#define PF_NUM_OF_PLATFORMS 30


//Enemy
#define E_WIDTH			200 //Sätt utifrån bildstorlek
#define E_HEIGHT		100
#define E_START_POS_X	((W_WIDTH / 2) - (E_WIDTH / 2))
#define E_START_POS_Y	E_HEIGHT //Gör att den spawnar precis utanför skärmen
#define E_PADDING		50 //px från väggen byter den håll
#define E_DAMP_INTERVAL	0.2
#define E_NUM_OF_ENEMIES 2

//Background
#define BG_WIDTH		600
#define BG_HEIGHT		2000
#define BG_MINPOS		-1200	
#define BG_MAXPOS		0

//Ground
#define GROUND_WIDTH	W_WIDTH
#define GROUND_HEIGHT	300
#define GROUND_START_Y	700
#define GROUND_START_X	0

//Shot
#define S_WIDTH			15
#define S_HEIGHT		45


#define MOVE_WORLD		1