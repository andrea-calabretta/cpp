Per compilare un programma del genere con diversi file, abbiamo diverse opzioni:

1) COMPILARE TUTTO IN UNA VOLTA:

g++ main.cpp classes.cpp library.cpp -o mylibrary

PRO: li compilo in un colpo solo
CONTRO: se io cambio qualcosa, anche solo dentro un solo file, lui ricompila sempre tutto anche se non è necessario.

2) COMPILARE UN FILE ALLA VOLTA E POI LINKARLI TRA LORO:

g++ -c classes.cpp
g++ -c clibrary.cpp
g++ -c main.cpp

g++ main.o library.o classes.o -o mylibrary

PRO: se modifico solo qualcosa, ricompilo solo quello che ho modificato e poi linko a quello precedente che già era compilato
CONTRO: devo fare una compilazione separata per ogni file
CONTROMISURA: usare il comando "make"

il make non fa altro che automatizzare le operazioni di compilazione. Si aspetta che nella nostra cartella ci sia un file "Makefile" che abbiamo creato noi e che definisce le regole di compilazione.

Vediamo com'è fatto questo Makefile:

mylibrary: main.cpp library.cpp classes.cpp classes.hh library.hh
  g++ -o milabrary main.cpp library.cpp classes.cpp -I.

mylibrary è il nome della regola (non è tanto importante quale sia questo nome) ma significa cheogni volta che viene modificato almeno un file che seguono i due punti, lui esegue il comando alla riga successiva.

In questo modo il compilatore si accorge automaticamente dove sono state le variazioni sui file su cui ho lavorato.
