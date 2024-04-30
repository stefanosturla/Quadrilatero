#include<iostream>

#include "CRectangle.h"
#include "CRhombus.h"

/*polimorfismo è una delle caratteristiche fondamentali 
dell'ereditarietà*/
/*nuova parola chiave: virtual, se io nella classe base chiamo una
funzione 'f2' con la parola chiave virtual, allora significa che ci
potrebbe essere una classe derivata che ha anche essa una funzione 
'f2' che fa delle cose diverse.
Questo è il primo esempio di poliformismo. Cioè la funzione 'f2' ha 
un significato diverso se chiamata nella classe padre oppure nella classe
figlio.
Una funzione virtuale assume un comportamento diverso a seconda di 
dove è*/
/*Questo meccanismo della funzione virtuale che ha un comportamento 
diverso in base a dove si trova, nel nostro esempio può essere usato
per la funzione area*/
/*se io metto virtual davanti a una funzione, la classe derivata che
la vuole implementare deve usare proprio la stessa funzione: con lo
stesso nome e la stessa lista parametri, altrimenti si tratta di due
funzioni diverse*/
int main() {

	Quadrilateral *A, *B, *C; /*ho dichiarato tre puntatori alla classe quadrilatero
	/*il vantaggio di chiamare un puntatore alla classe padre è
	la flessibilità*/
	float s1,s2,s3,s4;
	/*creo due rettangoli e un rombo*/
	Rectangle rectA(10,5);
	Rectangle rectB(3,7);
	Rhombus rhoC(2,1);
	
	A = &rectA; /*in questa riga ho A che è un puntatore
	alla classe quadrilatero e gli dico che deve puntare
	ad un indirizzo di memoria che è di tipo rettangolo.
	Quindi in generale un puntatore della classe padre 
	può puntare un oggetto della classe figlio.
	Questo perchè quando io dichiaro un oggetto di tipo 
	rettangolo in realtà io dichiaro un oggetto di tipo 
	rettangolo che contiente anche tutta la parte del 
	quadrilatero (un oggetto figlio contiene anche tutto
	quello che eredita dalla classe padre)*/
	B = &rectB;
	C = &rhoC;

	cout << endl;
	cout << "**** quadrilateral A ****" << endl;
	A->Dump(); /*quale dump viene chiamata? Del quadrilatero o del rettangolo?
	Abbiamo A che è di tipo quadrilatero e punta ad un rettangolo
	Quindi quale dump viene chiamata?
	Viene chiamata la dump del quadrilatero, perchè comunque A è un puntatore
	a un oggetto quadrilatero*/
	
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral C ****" << endl;
	C->Dump(); 
	cout << "**** ***** ****" << endl;
	
	cout << endl;
	cout << "**** rectangle A ****" << endl;
	rectA.Dump();  /*invece in questo caso viene chiamata
	la dump del rettangolo*/
	cout << "**** ***** ****" << endl;
	cout << "**** rectangle B ****" << endl;
	rectB.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** rectangle C ****" << endl;
	rhoC.Dump(); 
	cout << "**** ***** ****" << endl;
	
	rectA = rectB; 
	/*qui viene chiamato l'overload dell'operatore uguale*/
	/*Ora i puntatori A e B puntano alla stessa cosa?
	No!!. A continua a puntare al rettangolo A e B punta al
	rettangolo B, quindi puntano a due oggetti diversi
	che sono però uguali nei contenuti*/
	
	cout << endl;
	cout << "**** quadrilateral A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	rectB.SetWidth(12);
	cout << endl;
	cout << "**** quadrilateral A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	B->GetSides(s1,s2,s3,s4);
	/*in questo caso va bene perchè B è un quadrilatero e la
	GetSides è una funzione che fa parte delle proprietà del
	quadrilatero*/
	cout << "rectangle B - sides:" << s1 << " " << s2 << " "<< s3 << " "<< s4 << endl; 
	
	C->GetSides(s1,s2,s3,s4);
	cout << "rhombus C - sides:" << s1 << " " << s2 << " "<< s3 << " "<< s4 << endl;
	
	rhoC.SetDiagL(8);
	C->GetSides(s1,s2,s3,s4);
	cout << "rhombus C - sides:" << s1 << " " << s2 << " "<< s3 << " "<< s4 << endl;

//	C->GetArea(); 
/*la riga sopra commentata non compila perchè la funzione GetArea non è
presente nel quadrilatero*/
	
		
	
	return 0;

}