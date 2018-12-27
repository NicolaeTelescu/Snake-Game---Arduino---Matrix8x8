# Snake Game Arduino Matrix8x8

!!  Snake este un joc și trebuie tratat ca atare !!
!!  Informațiile de mai jos sunt pentru jucători, fără a avea nevoie de vreo pregătire în prealabil. Cei care vor să afle detalii despre implementarea jocului trebuie să intre în contact cu autorul jocului !!


## Informații despre joc

### Numele jocului
Inițial, jocul ar fi trebuit să se numească "The Real Snake" deoarece erau în plan mai multe îmbunătățiri care trebuiau aduse jocului, dar în final a rămas doar "Snake". Cei care vor dori să îl cunoască pe Snake vor vedea scris numele lui pe ecranul de început, deci Snake are parte de o mică prezentare.

### Cine este Snake ?
Snake este un șerpișor, un strămoș al marelui șarpe Anaconda Verde și al vestitului Boa cel Negru, care din cauza dimensiunilor reduse a fost adus pe tărâmul Arduino în căutarea merelor roșii pentru a-și recâștiga puterea și încrederea de care are nevoie pentru a se întoarce acasă.

### Ce trebuie să facă Snake ?
Snake își dorește să înfulece cât mai multe mere ca să se facă mare, să treacă prin primele etape ale vieții și să ajungă la dimensiunile strămoșilor lui. El a auzit că în România se găsesc cele mai gustoase și mai hrănitoare mere și pentru acest lucru are nevoie de ajutorul vostru. Credeți că îl puteți ajuta pe Snake să devină un adevărat șarpe în pofida dificultăților care vor apărea pe parcursul vieții sale ? Sau în cursa pentru putere și pentru bunăstare veți uita că viața lui este mai importantă decât orice altceva ?

### Care este sfârșitul vieții lui Snake ?
Snake trebuie să mănânce 100 de mere ca să crească și să se călească îndeajuns pentru a se întoarce în ținuturile natale. Atunci va putea să plece liniștit și încrezător din lumea Arduino. Pentru asta, el trebuie să treacă prin 6 etape ale vieții reprezentate ca niște acte dintr-o piesă de teatru întrucât la sfârșitul fiecărui nivel, și din stânga și din dreapta, se trage cortina. Dacă reușește să treacă de nivelul 6, atunci va ieși victorios din această lume și se va întoarce acasă. Dacă nu reușește să treacă de toate etapele, atuni viața lui se sfârșește mai devreme decât ar fi trebuit, iar corpul lui va rămâne aici pentru totdeauna.

### Cum stabilim decesul lui Snake ?
Înainte de a muri, Snake se va strădui să mai trăiască și-l vom vedea câteva clipe chinuindu-se, însă din cauza cozii mușcate nu se va mai putea târî. Îl vom vedea cum apare și dispare de pe hartă ca și cum s-ar zbate pentru viața lui, însă fără succes. Cortina o să fie trasă... Snake n-a reușit să își îndeplinească scopul...

### Cum stabilim reușita lui Snake ?
Snake va dispărea de pe ecran în semn că a plecat mai departe, în ținuturile natale, iar numele lui va domni pe ecran, rememorându-l de fiecare dată când se va aprinde jocul.


## Cu ce probleme s-a confruntat Snake până să înțeleagă această lume ?

### Întoarcerea
La început, Snake se micșora ca să se poată întoarce și trecea prin el însuși, însă acest lucru reprezenta o mare problemă întrucât, în lumea Arduino, chiar dacă totul este posibil, unele reguli trebuie urmate cu strictețe. Așa că el a învățat că trebuia să știe unde a fost capul ultima dată ca să știe care a fost ultima poziție și nu se mai întoarcă în acea parte. O altă problemă a fost că în cazul în care se întorcea, atunci el știa că trebuie să înainteze, dar uita să mănânce mărul concentrându-se numai la mutare.

### Găsirea merelor
Unele mere se găseau pe Snake, iar altele apăreau de la începutul jocului fix în gura lui Snake, iar el nu știa de ce se mărește singur, dar cum noi trebuie să îl învățăm să se miște, nu să primească totul ușor, a trebuit să generez merele într-un mod corect și aleator.

### Cunoașterea lui Snake
Snake nu a știut dintotdeauna cum să fie prezentabil. La început își scria numele prea subțire, după scria prea încet, câteodată prea repede, iar alteori nu se prezenta elegant. Pe parcurs și-a scris numele mai îngroșat ca să fie mai lizibil, și-a găsit un interval de timp care să fie cât mai plăcut ochiului în care să își deruleze numele, iar la sfârșit a învățat să își scrie numele astfel încât când citește, jucătorul să aibă senzația de continuitate al textului. Așa a devenit mai plăcut oamenilor.

### Piesele lumii lui Snake
Îndrumătorul lui Snake are nevoie de o poziție cât mai confortabilă pentru a se juca, iar pentru acest lucru a trebuit să inversez modul de primire a coordonatelor pentru ca firele de care este legat Joystick-ul să fie în sus și să nu incomodeze degetele jucătorului.

### Spațiul lumii lui Snake este limitat
A trebuit să eliberez cât mai multă memorie, iar ce s-a putut, am afișat prin cod cu formule.


## Parcursul vieții
Lumea lui Snake este o lume intensă, cu multe aventuri și cu multe probleme pe care le va întâmpina. Lumea nu trebuie să fie plictisitoare și nimeni nu trebuie să aștepte prea mult ca Snake să treacă la nivelul următor, nici măcar el, ci totul să se deruleze repede dacă îl conduci pe Snake într-un mod cât mai abil la mere.

Mai jos avem etapele prin care trebuie Snake să treacă. Mai mult de-atât, avem toate informațiile despre fiecare etapă din viața lui. Ne vor ajuta oare ele să trecem mai ușor de dificultăți dacă vom ști problemele de la început sau vor fi doar niște simple informații ? Să nu uităm că fiecare dintre noi avem vieți diferite și chiar dacă știm problemele de la începutul vieții, nu știm cum să le rezolvăm întotdeauna, precum și Snake va avea întotdeauna merele dispuse diferit, de la un îndrumător la altul, fără să îl ajute prea mult informațiile despre etapele vieții.

Nivel 1 -> viteză 300, intensitate :&nbsp;normală, mod : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; zi, lungime : 16 <br>
Nivel 2 -> viteză 250, intensitate :&nbsp;normală, mod : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; zi, lungime : 19 <br>
Nivel 3 -> viteză 200, intensitate : variabilă, mod : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; zi, lungime : 21 <br>
Nivel 4 -> viteză 150, intensitate : variabilă, mod : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; zi, lungime : 18 <br>
Nivel 5 -> viteză 150, intensitate : variabilă, mod : noapte, lungime : 17 <br>
Nivel 6 -> viteză 100, intensitate : variabilă, mod : noapte, lungime : &nbsp;8 <br>


## Problemele vieții

### Culoarea lui Snake
Când Snake va începe să se acomodeze cu lumea Arduino, el va începe să vadă viața diferit de la un măr la altul, sau mai bine zis, de la o experiență la alta. Fiecare măr mâncat îl va învăța un lucru pe care jucătorul îl va observa prin schimbarea culorii. Când Snake are o culoare prea intensă atunci putem spune că Snake a năpârlit.

### Noaptea ( dark mode )
Pentru că și în lumea lui Snake există lumină și întuneric, este normal să existe și zi și noapte. De aceea, în cea de-a patra parte a vieții lui se va face întuneric, iar Snake se va vedea cu greu printre reflexia razelor lunii.

### Marcarea unei noi etape din viață
Apare un măr pe hartă care are o frecvență mai mică de apariție simbolizând că nu trebuie să se mai grăbească căci mai este un singur pas pentru a trece mai departe. După ce mănâncă și ultimul măr, este tras înăuntru pentru nivelul următor, Snake repezindu-se în portal după ce a ajuns în el, cortina trăgându-se.

### Coada cozii
Ultima pozitie a lui Snake o elimin înainte de a aplica mutarea curentă ca să nu apară problema de a muri pe o singura linie, avand 8 cerculețe lungime și să mor în linie, ci jocul să continue.


## Super-puterile lui Snake

Pentru a câștiga trebuie să cunoști secretele lumii. Snake trebuie ținut în frâu pentru că e cu ochii doar la mancare, dar poate fi ajutat, la nevoie, cu mărirea vitezei ca să ajungă mai repede în lumea lui.

### Viteza lui Snake
Cand înaintează, Snake are viteza mărită. Această mărire variază în funcție de nivel : cu cât avansezi în nivel și îți crește automat viteza, cu atât și mărirea vitezei lui Snake scade ca să fie o mărire cât mai echilibrată. Altfel, și-ar mări prea mult viteza la sfârșit sau ar fi prea mică mărirea vitezei la început dacă ar fi o mărire de viteză constantă.

### Căpăstru
O altă unealtă folositoare de a-l conduce pe Snake este frână. În loc să se întoarcă el frânează ca și cum îndrumătorul i-ar pune un căpăstru și l-ar trage. În acest mod, jucătorul obține mai mult timp de gândire pentru mutarea următoare.

### Solzii de aur ai lui Snake
Pentru că lui Snake îi place senzația de netezime ( eng. "smooth" ) și pentru adevărații jucătorii de Snake care au nevoie de condițiile cele mai bune... pardon, pentru comoditatea celor care vor să îl ajute pe Snake, am creat niște solzi de aur astfel încat Snake să poată primi din timp comenzile, iar solzii lui să alunece mai ușor în direcția indicată, nu doar atunci când ajunge la o intersecție de drumuri.
Exemplu : când îndrumătorul indică o direcție ( primeste coordonate ), el apasă pe joystick cel puțin 10 milisecunde, însă, din cauză că în lumea lui Snake se primesc instrucțiunile la fiecare milisecundă ( poza loop cu highlight primesteCoordonate ), trebuie să preiau comanda jucătorului la un interval fixat de timp. Așadar, Snake va prelua comenzile pentru mișcarea lui abia după ce a trecut jumătate din timpul poziției de staționare ca să nu se întâmple cumva, din greșeală, ca instructorul lui să îi trimită doua mișcări în același timp și să îl facă pe Snake să prindă mai multă viteză decât ar trebui ( poză primeste coordonate cu millis + viteza / 2 ). La intervalul de timp stabilit, Snake se va mișca automat în partea în care i-a spus jucătorul în timp ce el stătea pe loc. În acest mod, ghidul lui Snake poate să își aleagă direcția în care se va duce Snake din timp, acordându-i astfel un mare avantaj care va face jocul mai plăcut și starea jucătorului mai confortabilă. Nu va trebui să mai stea tensionat și strsat ca să mute "la timp", ci într-un mod cât mai avantajos pentru mutările următoare. Jocul trebuie să fie bazat cât mai mult pe inteligență și pe strategie, nu numai pe reacții. (poză cum ar fi fost fără solzii de aur - explicație )

### Simțul de orientare al lui Snake
Când începe un nou nivel, Snake are două secunde să observe terenul și să vadă mărul ca să se pregătească în ce direcție s-o apuce.


## Îmbunătățiri viitoare

### Se lasă seara
Pentru modul de "dark mode" trebuia să afișez ca într-un spital părăsit unde nu mai merge lumina, un fel de stingere de bec cu probleme, ca în clădirile afectate de o calamitate.

### Fitness Snake
Pentru că Snake trebuie menținut în formă, atunci când Snake face mai mult de 5 schimbări de direcție șerpuit, fără să lase spații, asemănător pozei în care face 4 șerpuiri consecutiv ( exemplu Șerpuire ), datorită flexibilității și a sportului el va pierde miligramele în plus, mai precis lungimea cozii se va reduce. El va putea pierde în greutate... pardon, în lungime, doar dacă are mai mult de 10 cerculețe lungime pentru că altfel este îndeajuns de sănătos.

### Cu cât mai repede, cu atât mai bine
Scorul poate fi modificat să fie în raport cu timpul, adică, să se adauge și un bonus de (60 - secundele în care Snake termină nivelul).

### Împlinirea
Cand se trece la nivelul următor, ar trebui să apară o spirală din portalul lui Snake în semn că etapa vieții s-a terminat cu bine, iar matricea rămâne aprinsă pentru câteva secunde, cum și Snake trece împlinit către următoarea etapă a vieții lui.

### Citirea scorului
Scorul ar trebui reținut pe matrice până se apasă butonul și se revine la meniul principal. Ideea este că scorul nu trebuie să dispară pentru persoanele care vor dori să arate și altora recordul bătut de ei.

### Generarea mărului
Pentru pretențioși, mărul trebuie să se genereze mai departe cu cel puțin două linii și două coloane față de Snake ca să nu crească dintr-o dată și să nu se creadă că este un defect.

### Sunetele făcute de Snake
Un sunet ar trebui să indice bucuria lui Snake că a găsit mărul, dar și o melodie ar trebui să marcheze suferința lui Snake înainte de a-și da duhul.

## Îmbunătățiri propuse, dar irealizabile

### Creatorul lumii
Lumea ar trebui să îi afișeze celui care l-a ghidat pe Snake prin viață un mesaj de mulțumire sau de victorie și tot lui să i se arate cine a fost Creatorul jocului - Joc făcut de Telescu Nicolae, însă cum spațiul lumii Arduino este limitat, această caracteristică nu va fi pusă în plan prea curând.

### Portalul către următorul nivel
Portalul ar fi fost reprezentat de 8 puncte, din care cel din interior sa licăre, iar celelalte din jur să rămână aprinse, în afară de un singur punct prin care este așteptat Snake să intre, dar nu se știe dacă la o lungime mai mare a lui Snake se poate așeza într-o poziție bună portalul.

### Disco Snake
La fiecare măr mâncat să ai o intensitate nouă a fiecărui LED aprins, însă LED-urile se aprind toate cu aceeași intensitate. S-ar fi putut ca la fiecare mișcare să fie o altă intensitate, nu numai la mâncatul merelor, dar atunci ar fi atras prea mult atenția îndrumătorului, de la mere, la culorile lui Snake. Ar fi fost frumos ca Snake să se metamorfozeze într-un joc de intensități. Ăla da șarpe ! Mândri ar fi fost străbunii lui.

### Snake fantomă
Cand utilizatorul ar fi apăsat pe buton, lui Snake i s-ar fi micșorat intensitatea și ar fi putut trece peste el însuși peste cel mult două ziduri fără să se mănânce și astfel, fără să moară.

## Componentele lumii lui Snake :
* Matrice 8x8 Display
* MAX7219 Driver pentru conectarea Matricei
* Joystick ( pentru șerpuiri )
* Breadboard ( yummy... )
* Mini breadboard
* Fire / cabluri
* Rezistor 100k
* Condensator 10 uF
* Condensator 0.1 uF ( 100nF )
* Cablu Arduino USB

## O secvență din viața lui Snake : [Video](https://drive.google.com/drive/folders/15kbSbUFtFvKrWLTEElFbbPPkjcsxlSLo?usp=sharing)

## Dețin drepturi de autor !

## For english, press 2. I mean, to be continued.
