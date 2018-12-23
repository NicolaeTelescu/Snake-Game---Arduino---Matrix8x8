#include "LedControl.h"
LedControl matrice = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, Numarul DRIVER-ului

// instructiuni pentru driver matrice :
// pinul 12 este conectat la MAX7219 - pin 1
// pinul 11 este conectat la CLK - pin 13
// pinul 10 este conectat la LOAD - pin 12
// numarul driverului este 1 pentru ca folosim un singur MAX7219

#define BUTTON_JOYSTICK 2
#define PIN_JOYSTICK_X A0
#define PIN_JOYSTICK_Y A1

// afisare cifre
bool cifre[8][40] = 
{
    {0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,0,0,1,1,0},
    {1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,1,0,0,1},
    {1,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1},
    {1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,0,1,1,1},
    {1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1},
    {1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0,1},
    {0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,1,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

// afisare Level
bool level[8][52] = 
{
    {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
};

// afisare --Snake-- inainte de inceperea jocului
bool snakeScris[6][8][8] =
{
  {
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
  },
  {
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
  },
  {
    {1,1,0,0,0,0,1,1},
    {1,1,1,0,0,0,1,1},
    {1,1,1,1,0,0,1,1},
    {1,1,0,1,1,0,1,1},
    {1,1,0,0,1,1,1,1},
    {1,1,0,0,0,1,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
  },
  {
    {0,0,1,1,1,1,0,0},
    {0,0,1,1,1,1,0,0},
    {0,0,1,0,0,1,0,0},
    {0,0,1,0,0,1,0,0},
    {0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
  },
  {
    {1,1,0,0,0,1,1,1},
    {1,1,0,0,0,1,1,1},
    {1,1,0,0,1,1,0,0},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,1,0,0,0},
    {1,1,1,0,1,1,0,0},
    {1,1,0,0,0,1,1,1},
    {1,1,0,0,0,1,1,1},
  },
  {
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {1,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
  },
};

// matrice care imi indica unde se afla Snake ca sa stiu cand se mananca singur
bool whereIsSnake[8][8] =
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

struct point2D
{
  unsigned char x, y;
};


bool redPoint = 0; // semafor de aprindere si stingere LED mancare Snake
char x = 0, y = 0; // pozitia actuala
char x1 = -1, y1 = -1; // pozitia pe care o alege jucatorul in timp ce Snake sta pe loc
char xPoint = 6, yPoint = 7; // pozitie mancare Snake
point2D coadaLuiSnake[64]; // coordonatele lui Snake
char lungime = 1; // lungimea lui Snake
bool seJoaca = 0; // indicator daca se afiseaza sau se joaca pe matrice
bool aprindeJoc = 1; // cum sa fie facuta afisarea, aprinzandu-se LED-urile sau stingandu-se ( a se vedea Dark mode )
unsigned char scor = 1; // scorul jucatorului
unsigned char nivel = 1; // nivelul curent
unsigned char demo = 0; // Daca as avea valoarea 14, atunci nivelele s-ar termina mai repede, ca o varianta demo.
unsigned short viteza = 0; // viteza lui Snake
unsigned short frana = 0; // capastrul lui Snake
unsigned short licarire = 100; // timpul pentru licarirea marului

unsigned long timeForPlaying = 500; // moment mutare Snake
unsigned long timePoint = 500; // moment aprindere mar
 
void setup()
{
  randomSeed(analogRead(A5)); // pin care nu merge
  Serial.begin(9600); // initializare Serial Monitor
  
  initializareButonJoystick();
  initializareMatrice();
  initializareJoc();
}

void initializareButonJoystick()
{
  pinMode(BUTTON_JOYSTICK, INPUT);
  digitalWrite(BUTTON_JOYSTICK, HIGH);
}

void initializareMatrice()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  matrice.shutdown(0, false); // inchid salvarea bateriei si pornesc display-ul 
  matrice.setIntensity(0, 1); // setez intensitatea LED-urilor ( intre 0 si 15 valori posibile)
  matrice.clearDisplay(0); // sterg tot ce este pe ecran ca sa il curat
}

void initializareJoc()
{
  matrice.clearDisplay(0);
  matrice.setIntensity(0, 1);
  seJoaca = 0;
  lungime = 1;
  scor = 1;
  nivel = 1;
  viteza = 300;
  aprindeJoc = 1;
  frana = 0;
  licarire = 100;
  x1 = -1;
  y1 = -1;
  x = 0;
  y = 0;
  coadaLuiSnake[0].x = 0;
  coadaLuiSnake[0].y = 0;
  coadaLuiSnake[1].x = 0;
  coadaLuiSnake[1].y = 7; // ca sa poata prezice urmatoarea pozitie
  
  for (int i = 0 ; i < 8 ; i++)
    for (int j = 0 ; j < 8 ; j++)
      whereIsSnake[i][j] = 0;
}

void initializareNivel()
{
  unsigned char nivel1 = nivel, scor1 = scor, aprindeJoc1 = aprindeJoc;
  initializareJoc();
  
  seJoaca = 1;
  scor = scor1;
  nivel = nivel1;
  aprindeJoc = aprindeJoc1;
}

// pentru Dark mode -> trebuie sa stiu ce inseamna sa aprind si sa sting un LED pentru ca se pot inversa notiunile
void aprindeLed(unsigned char x, unsigned char y)
{
  matrice.setLed(0, x, y, aprindeJoc);
}

void stingeLed(unsigned char x, unsigned char y)
{
  matrice.setLed(0, x, y, 1 - aprindeJoc);
}

// pentru AFISARE, nu pentru oprire joc. Nu genereaza blocaje globale nejustificate
void asteapta(unsigned long timp)
{
  unsigned long timpActual = millis();
  while (timp + timpActual > millis());
}

void licarireLED(int x, int y)
{
  if (timePoint + licarire < millis())
  {
    timePoint = millis();
    if (redPoint == 0)
    {
      aprindeLed(x,y);
      redPoint = 1;
    }
    else
    {
      stingeLed(x,y);
      redPoint = 0;
    }
  }
}

// inainte de a incepe jocul, afiseaza Snake pe ecran
void afiseazaSnake()
{
  bool opreste = 0;
  for (unsigned char k = 0 ; k < 7 * 9 - 2 && !opreste ; k++)
  {
    if (digitalRead(BUTTON_JOYSTICK) == 0) // daca s-a apasat butonul atunci se va incepe jocul
    {
      opreste = 1;
      seJoaca = 1;
      matrice.clearDisplay(0);
    }
    else
    {
      for (unsigned char i = 0 ; i < 8 ; i++)
        for (unsigned char j = 0 ; j < 8 ; j++)
        {
          if ((j + k) / 10 == 6)
            matrice.setLed(0, i, j, true);
          else
          {
            if ((j + k) % 10 < 8 && snakeScris[(j + k) / 10][i][(j + k) % 10] == 1)
              matrice.setLed(0, i, j, true);
            else
              matrice.setLed(0, i, j, false);
          }
        }
    }
    asteapta(65);
  }
  asteapta(200);
}

// pentru fiecare nivel in parte afisez level 'nivel' ( cifra )
void afiseazaLevel()
{
  matrice.clearDisplay(0);
  for (unsigned char k = 0 ; k < 58 ; k++)
  {
    for (unsigned char i = 0 ; i < 8 ; i++)
      for (unsigned char j = 0 ; j < 8 ; j++)
      {
        if (k <= 44)
        {
          if (level[i][j + k] == 1)
            matrice.setLed(0, i, j, true);
          else
            matrice.setLed(0, i, j, false);
        }
        else
        {
          if (cifre[i][4 * nivel + j] == 1 && j < 4)
            matrice.setLed(0, i, j + 8 - (k - 44), true);
          else
            matrice.setLed(0, i, j + 8 - (k - 44), false);
        }
      }
    asteapta(65);
  }
  asteapta(200);
  matrice.clearDisplay(0);
}

void stingeMatricea()
{
  for (unsigned char i = 0 ; i < 8 ; i++)
    for (unsigned char j = 0 ; j < 8 ; j++)
    {
      stingeLed(i,j);
    }
}

void aprindeSnake()
{
  if (nivel == 2)
  for (char i = lungime - 1 ; i >= 0 ; i--) // Greseala pe care ne-a mai spus-o o singura data domnul Alexe :)). TRebuie char, nu unsigned char
  {
    aprindeLed(coadaLuiSnake[i].x, coadaLuiSnake[i].y);
  }
}

unsigned char adauga(unsigned char a)
{
  if (a == 7) return 0;
  return a + 1;
}

unsigned char scade(unsigned char a)
{
  if (a == 0) return 7;
  return a - 1;
}

unsigned char mutare(unsigned char x, unsigned char y, unsigned char xAnt, unsigned char yAnt)
{
  if (x == xAnt && y == yAnt) return 0; // Ai ramas pe loc
  if (x == adauga(xAnt) && y == yAnt) return 1; // Nord
  if (x == xAnt && y == adauga(yAnt)) return 2; // Est
  if (x == scade(xAnt) && y == yAnt) return 3; // Sud
  if (x == xAnt && y == scade(yAnt)) return 4; // Vest
}

unsigned char mutareInv(unsigned char x, unsigned char y, unsigned char xAnt, unsigned char yAnt)
{
  // Nu va intra niciodata pe if-ul urmator din cauza ca mutareInv se refera la mutarea anterioara, iar eu memorez pozitiile unde s-a miscat Snake
  // if (x == xAnt && y == yAnt) return 0; // Ai ramas pe loc
  
  if (x == adauga(xAnt) && y == yAnt) return 3; // invNord = Sud
  if (x == xAnt && y == adauga(yAnt)) return 4; // invEst = Vest
  if (x == scade(xAnt) && y == yAnt) return 1; // invSud = Nord
  if (x == xAnt && y == scade(yAnt)) return 2; // invVest = Est
}

point2D prevestire(unsigned char x, unsigned char y, unsigned char xAnt, unsigned char yAnt)
{
  point2D mutare;
  mutare.x = x;
  mutare.y = y;
  if (x == adauga(xAnt) && y == yAnt) mutare.x = adauga(x); // Nord
  if (x == xAnt && y == adauga(yAnt)) mutare.y = adauga(y); // Est
  if (x == scade(xAnt) && y == yAnt) mutare.x = scade(x); // Sud
  if (x == xAnt && y == scade(yAnt)) mutare.y = scade(y); // Vest
  return mutare;
}

// pentru inceputul jocului, cand se afiseaza o numaratoare inversa
void afiseazaUnaCifra(unsigned char x)
{
  matrice.clearDisplay(0);
  for (unsigned char i = 0 ; i < 8 ; i++)
    for (unsigned char j = 0 ; j < 4 ; j++)
    {
      if (cifre[i][4 * x + j] == 1)
        matrice.setLed(0, i, j + 2, true);
      else
        matrice.setLed(0, i, j + 2, false);
    }
  asteapta(1000);
  matrice.clearDisplay(0);
}

// pentru scor
void afiseazaDouaCifre(unsigned char x, unsigned char y)
{
  matrice.clearDisplay(0);
  for (unsigned char i = 0 ; i < 8 ; i++)
    for (unsigned char j = 0 ; j < 4 ; j++)
    {
      if (cifre[i][4 * x + j] == 1)
        matrice.setLed(0, i, j, true);
      else
        matrice.setLed(0, i, j, false);
    }
  for (unsigned char i = 0 ; i < 8 ; i++)
    for (unsigned char j = 0 ; j < 4 ; j++)
    {
      if (cifre[i][4 * y + j] == 1)
        matrice.setLed(0, i, j + 4, true);
      else
        matrice.setLed(0, i, j + 4, false);
    }
  asteapta(5000);
  matrice.clearDisplay(0);
}

// primeste coordonatele Joystick-ului dupa ce a trecut jumatate din timpul unei stationari
void primesteCoordonateJoyStick()
{
  if (timeForPlaying + viteza / 2 < millis())
  {
    int JoyStickX = analogRead(PIN_JOYSTICK_X);
    int JoyStickY = analogRead(PIN_JOYSTICK_Y);
  
    int schimbat = 0; // schimbat pozitie Joystick
    // sunt mult mai usor de vazut valorile decat sa le pun alte nume de variabila
    if (JoyStickX < 200)
    {
      x1 = scade(x);
      y1 = y;
      schimbat = 1;
    }
    if (JoyStickX > 700)
    {
      x1 = adauga(x);
      y1 = y;
      schimbat = 1;
    }
    if (JoyStickY < 200 && schimbat == 0)
    {
      x1 = x;
      y1 = adauga(y);
    }
    if (JoyStickY > 700 && schimbat == 0)
    {
      x1 = x;
      y1 = scade(y);
    }
  }
}

void actualizeazaCoordonatePrimite()
{
  // primesc pozitia pe care a ales-o jucatorul in timp ce Snake statea pe loc, dar doar daca a ales jucatorul o mutare
  if (!(x1 == -1 && y1 == -1))
  {
    x = x1;
    y = y1;
  }
  x1 = -1;
  y1 = -1;
}

// inainteaza Snake automat, in cazul in care el statea pe loc
void inainteazaSnake()
{
  point2D mutare;
  mutare = prevestire(coadaLuiSnake[0].x,coadaLuiSnake[0].y,coadaLuiSnake[1].x,coadaLuiSnake[1].y);

  x = mutare.x;
  y = mutare.y;

  mutareObisnuita();
}

// trebuie sa ii actualizez toate coordonatele lui Snake in functie de cum se misca ( ii adaug pozitia unde s-a mutat si o sterg pe ultima care s-a stins )
void actualizeazaCoadaSnake()
{
  // Nu trebuia lungime - 1 pentru ca am nevoie si de ultima mutare a lui Snake, chiar daca a fost stinsa, dar cred ca am nevoie de ea numai cand maresc lungimea
  for (int i = lungime ; i >= 1 ; i--) 
  {
    coadaLuiSnake[i].x = coadaLuiSnake[i - 1].x;
    coadaLuiSnake[i].y = coadaLuiSnake[i - 1].y;
  }
  coadaLuiSnake[0].x = x;
  coadaLuiSnake[0].y = y;
}

//   dupa ce a murit il afisez pe Snake cum se zbate sa mai traiasca,
// dar dupa ce se vede infrant si nu se mai poate misca atunci afisez performanta pe care a reusit-o, mai precis scorul, singura bucurie
void afiseazaSnakeMort()
{
  for (int j = 0 ; j <= 10 ; j++)
  {
    for (int i = 0 ; i < lungime ; i++)
    {
      if (j % 2 == 1)
        aprindeLed(coadaLuiSnake[i].x, coadaLuiSnake[i].y);
      else
        stingeLed(coadaLuiSnake[i].x, coadaLuiSnake[i].y);
    }
    asteapta(300);
  }
}

void actualizeazaVitezaSiFrana()
{
  frana = 0;
  switch (nivel)
  {
    case 1 : viteza = 300;
             break;
    case 2 : viteza = 250;
             break;
    case 3 : viteza = 200;
             break;
    case 4 : viteza = 150;
             break;
    case 5 : viteza = 150;
             break;
    case 6 : viteza = 100;
             break;
  }
}

// il mut pe Snake pe x si y, acolo unde s-au actualizat coordonatele
void mutareObisnuita()
{ 
  // ultima pozitie a lui Snake o elimin inainte de a muta undeva ca sa nu apara bug-ul de a muri pe o singura linie
  whereIsSnake[coadaLuiSnake[lungime - 1].x][coadaLuiSnake[lungime - 1].y] = 0;
  
  verificaDacaAiMurit();
  if (seJoaca == 1)
  { 
    whereIsSnake[x][y] = 1;
    
    stingeLed(coadaLuiSnake[lungime - 1].x, coadaLuiSnake[lungime - 1].y);
    aprindeLed(x,y);
  
    actualizeazaCoadaSnake();
  }
}

void verificaDacaAiMurit()
{
  if (whereIsSnake[x][y] == 1) // ai pierdut jocul :))
  {
    // anunta ca esti un pierzator !
    afiseazaSnakeMort();

    // afiseaza GameOver -> nu mai am memorie...

    // afiseaza Scor
    afiseazaDouaCifre(scor / 10, scor % 10);
    initializareJoc(); // resetez toate variabilele
  }
}

void genereazaMar()
{
  while (whereIsSnake[xPoint][yPoint] == 1) // genereaza un mar care sa nu fie pe Snake
  {
    xPoint = random(0,7);
    yPoint = random(0,7);
  }
}

void adunaScor()
{
  scor++;
}

void licarireMar()
{
  unsigned char lungime1 = lungime;
  lungime++;
  
  if (potCresteNivelul())
    licarire = 500;
  else licarire = 100;
  
  lungime = lungime1;
}

void intensitateMatrice()
{
  if (nivel >= 3)
    matrice.setIntensity(0, random(0,nivel * 2)); // Intensitatea poate sa fie maxim 10, deci voi pune 15 pentru portal
}

void darkMode()
{
  if (nivel == 5 && aprindeJoc == 1) // dark mode
    aprindeJoc = 0;
}

// inainte de a trece la un nou nivel, il afisez pe Snake ca in Zuma, grabit sa descopere o noua lume, un nou nivel
void stingeLinSnake()
{
  for (char i = lungime - 1 ; i >= 1 ; i--)
  {
    stingeLed(coadaLuiSnake[i].x, coadaLuiSnake[i].y);
    asteapta(200);
  }
}

// dupa ce moare Snake se termina spectacolul, deci trag copertina :). S-a terminat piesa dramatica in care Snake moare la final, sau se termina cate un act ( nivel )
void invaluireEcran()
{
  for (unsigned char k = 0 ; k < 4 ; k++)
  {
    for (unsigned char i = 0 ; i < 8 ; i++)
    {
      matrice.setLed(0, i,     k, true);
      matrice.setLed(0, i, 7 - k, true);
    }
    asteapta(100);
  }
  asteapta(1000);
  for (unsigned char k = 0 ; k < 4 ; k++)
  {
    for (unsigned char i = 0 ; i < 8 ; i++)
    {
      matrice.setLed(0, i,     k, false);
      matrice.setLed(0, i, 7 - k, false);
    }
    asteapta(100);
  }
  asteapta(500);
}

void urmatorulNivel()
{
  stingeLinSnake();
  lungime = 1;
  nivel++;

  initializareNivel();
  actualizeazaVitezaSiFrana();

  darkMode();

  invaluireEcran();
  afiseazaLevel();
  stingeMatricea(); // mi-am adus aminte : la darkMode trebuie sa o sting "aprinzandu-o"
  aprindeSnake();
  matrice.setLed(0, xPoint, yPoint,  aprindeJoc);
  
  asteapta(2000);
}

// cand pot creste nivelul
bool potCresteNivelul()
{
  switch (nivel)
  {
    case 1 : return (lungime == 16 - demo); break; // cu toate ca nu am nevoie de break, le pun ca sa fie la vedere
    case 2 : return (lungime == 19 - demo); break;
    case 3 : return (lungime == 21 - demo); break;
    case 4 : return (lungime == 18 - demo); break;
    case 5 : return (lungime == 17 - demo); break;
    case 6 : return (lungime ==  8 - demo); break;
  }
}

// returnez viteza pe care trebuie sa o am la fiecare nivel
unsigned char vitezaScazuta()
{
  switch (nivel)
  {
    case 1 : return 150; break; // cu toate ca nu am nevoie de break, le pun ca sa fie la vedere
    case 2 : return 130; break;
    case 3 : return 100; break;
    case 4 : return 70; break;
    case 5 : return 60; break;
    case 6 : return 50; break;
  }
}

void SnakeAMuscatMomeala()
{
  lungime++;
  
  intensitateMatrice();
  genereazaMar();
  licarireMar();
  adunaScor();
  
  if (potCresteNivelul())
    urmatorulNivel();
}

void loop()
{
  if (seJoaca == 0)
  {
    afiseazaSnake();
    if (seJoaca == 1)
    {
      afiseazaLevel();
      afiseazaUnaCifra(3);
      afiseazaUnaCifra(2);
      afiseazaUnaCifra(1);
      matrice.setLed(0, 0, 0,  aprindeJoc);
      timeForPlaying = millis();
    }
  }
  else
  {
    licarireLED(xPoint,yPoint);
    primesteCoordonateJoyStick(); // daca misc JoyStick-ul atunci mi se actualizeaza si coordonatele lui Snake
    
    if (timeForPlaying + viteza + frana < millis())
    {
      timeForPlaying = millis(); // schimb timpul numai daca am mutat
      actualizeazaCoordonatePrimite();
      actualizeazaVitezaSiFrana();

      // daca a apasat inainte, atunci ii marim viteza la urmatoarea miscare
      if (mutare(x,y,coadaLuiSnake[0].x,coadaLuiSnake[0].y) == mutare(coadaLuiSnake[0].x,coadaLuiSnake[0].y,coadaLuiSnake[1].x,coadaLuiSnake[1].y))
        viteza -= vitezaScazuta();

      // daca a ramas aceeasi mutare, adica nu ai miscat JoyStickul, atunci Snake trebuie sa inainteze
      if (mutare(x,y,coadaLuiSnake[0].x,coadaLuiSnake[0].y) == 0)
        inainteazaSnake();
        
      else // daca ai miscat Joystick-ul
      {
        // daca nu a facut o miscare interzisa, adica daca nu s-a intors si are lungimea mai mare decat 1
        if (mutare(x,y,coadaLuiSnake[0].x,coadaLuiSnake[0].y) != mutareInv(coadaLuiSnake[0].x,coadaLuiSnake[0].y,coadaLuiSnake[1].x,coadaLuiSnake[1].y) || lungime == 1)
          mutareObisnuita();
        
        else // daca s-a intors, atunci ii punem frana, dar el tot inainteaza
        {
          inainteazaSnake();
          frana = 200;
        }
      }
      
      // daca Snake a ajuns in punctul unde era marul
      if (x == xPoint && y == yPoint)
        SnakeAMuscatMomeala();
    }
  }
}
