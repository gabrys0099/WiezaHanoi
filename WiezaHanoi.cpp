//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 5.1
// wie¿e hanoi
//
//  WCY21IY1S1  Go³êbiowski Gabriel
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

//struktura stosu
typedef struct stos
 {
 	int priority;
 	struct stos *next;  
 }node;

//funkcja dodania ogona do wie¿y
void DodajOgon(node **head , int priority)
{
	node *newNode =(node *)malloc(sizeof(node));	
	newNode->priority=priority;
	newNode->next=NULL;
	if(*head==NULL)
	{
		*head=newNode;
	}
	else
	{
		node *tmp=*head;
		while(tmp->next !=NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=newNode;
	}
}

//Funkcja wyœwietlenia listy od g³owy

void wyswietlenieListy(node *head)
{
	cout<<endl;
	ofstream plik("wy.txt", ios::app);
	node *tmp=head;
	if(tmp==NULL)
	{
		cout<<"--puste--";
		cout<<endl;
		return;
	}
	
	do
	{
		if(tmp->priority==0)
		{
			tmp=tmp->next;
			continue;
		}
		plik<<tmp->priority<<", ";
		cout<<tmp->priority<<", ";//wypisanie na ekranie priorytetu elementu(wielkoœci klocka)
		tmp=tmp->next;
	}while(tmp!=NULL);
	plik.close();
	cout<<endl;
}

//Funkcja usuwaj¹ca element z palika

void UsunZeStosu(node ** head)
{
	if(*head!=NULL)
	{
		node *tmp1=*head, *tmp2=*head;
		while(tmp1->next!=NULL)
		{
			tmp2=tmp1;
			tmp1=tmp1->next;
		}
		if(tmp1==*head)
		{
			free(*head);
			*head=NULL;
		}
		else
		{
			tmp2->next=NULL;
			free(tmp1);
		}
		
	}
}
//funkcja wypisujaca z jakiego do jakiego palika przeniesie sie element
void przenies(int p, int q)
{
    const char palik[] = { 'A', 'B', 'C' };
    cout <<"przejscie: "<< palik[p] << " -> " << palik[q] << endl;
}

//Funkjca zarz¹zaj¹ca jakie, kiedy i gdzie przenios¹ siê elementy
void hanoi(int n, node *headA, node *headB, node *headC, int a, int b, int c)
{
	ofstream plik("wy.txt", ios::app);
    if (n > 1)
	{
		hanoi(n - 1, headA, headB, headC, a, c, b);
	}
	przenies(a, c);
    if(a==0)
    {
    	if(c==1)
    	{
    		UsunZeStosu(&headA);//usuniecie elementu z jednego palika	
    		DodajOgon(&headB, n);//dodanie na drugi
    		//wypisanie palikow
    		plik<<"wieza A: ";
			cout<<"wieza A: ";
			wyswietlenieListy(headA);
			plik<<endl<<"wieza B: ";
			cout<<endl<<"wieza B: ";
			wyswietlenieListy(headB);
			plik<<endl<<"wieza C: ";
			cout<<endl<<"wieza C: ";
			wyswietlenieListy(headC);
			cout<<"-------------nastepny ruch: --------------"<<endl;
			plik<<"-------------nastepny ruch: --------------"<<endl;
    		
		
		}
		else if (c==2)
		{
			UsunZeStosu(&headA);	
    		DodajOgon(&headC, n);
    		plik<<"wieza A: ";
			cout<<"wieza A: ";
			wyswietlenieListy(headA);
			plik<<endl<<"wieza B: ";
			cout<<endl<<"wieza B: ";
			wyswietlenieListy(headB);
			plik<<endl<<"wieza C: ";
			cout<<endl<<"wieza C: ";
			wyswietlenieListy(headC);
			plik<<"-------------nastepny ruch: --------------"<<endl;
			cout<<"-------------nastepny ruch: --------------"<<endl;
    		
		}
	}
	else if(a==1)
	{
		if(c==0)
    	{
    		UsunZeStosu(&headB);   		
    		DodajOgon(&headA, n);
    		plik<<"wieza A: ";
			cout<<"wieza A: ";
			wyswietlenieListy(headA);
			plik<<endl<<"wieza B: ";
			cout<<endl<<"wieza B: ";
			wyswietlenieListy(headB);
			plik<<endl<<"wieza C: ";
			cout<<endl<<"wieza C: ";
			wyswietlenieListy(headC);
			plik<<"-------------nastepny ruch: --------------"<<endl;
			cout<<"-------------nastepny ruch: --------------"<<endl;
    		
		}
		else if (c==2)
		{
			UsunZeStosu(&headB);
    		DodajOgon(&headC, n);
    		plik<<"wieza A: ";
			cout<<"wieza A: ";
			wyswietlenieListy(headA);
			plik<<endl<<"wieza B: ";
			cout<<endl<<"wieza B: ";
			wyswietlenieListy(headB);
			plik<<endl<<"wieza C: ";
			cout<<endl<<"wieza C: ";
			wyswietlenieListy(headC);
			plik<<"-------------nastepny ruch: --------------"<<endl;
			cout<<"-------------nastepny ruch: --------------"<<endl;
    		
		}
	}
	else if(a==2)
	{
		if(c==1)
    	{
    		UsunZeStosu(&headC);  		
    		DodajOgon(&headB, n);
    		plik<<"wieza A: ";
			cout<<"wieza A: ";
			wyswietlenieListy(headA);
			plik<<endl<<"wieza B: ";
			cout<<endl<<"wieza B: ";
			wyswietlenieListy(headB);
			plik<<endl<<"wieza C: ";
			cout<<endl<<"wieza C: ";
			wyswietlenieListy(headC);
			plik<<"-------------nastepny ruch: --------------"<<endl;
			cout<<"-------------nastepny ruch: --------------"<<endl;
		}
		else if (c==0)
		{
			UsunZeStosu(&headC);	
    		DodajOgon(&headA, n);
    		plik<<"wieza A: ";
			cout<<"wieza A: ";
			wyswietlenieListy(headA);
			plik<<endl<<"wieza B: ";
			cout<<endl<<"wieza B: ";
			wyswietlenieListy(headB);
			plik<<endl<<"wieza C: ";
			cout<<endl<<"wieza C: ";
			wyswietlenieListy(headC);
			plik<<"-------------nastepny ruch: --------------"<<endl;
			cout<<"-------------nastepny ruch: --------------"<<endl;
		}
	}
    if (n > 1)
	{
		hanoi(n - 1, headA, headB, headC, b, a, c);
	};
	plik.close();
}


int main()
{
	//implementacja g³ow palików
	stos *headA=NULL;
 	stos *headB=NULL;
 	stos *headC=NULL;
 	ofstream plik("wy.txt", ios::app);
    int n;
    cout << "Wieze Hanoi\n-----------\nLiczba krazkow: ";
    cin >> n;
    DodajOgon(&headA, 0);
    for(int i=n;i>0;i--)
    {
	DodajOgon(&headA, i);//dodanie elementów do palika pocz¹tkowego
	}
	DodajOgon(&headB, 0);
	DodajOgon(&headC, 0);
    if (n > 0)
        hanoi(n, headA, headB, headC, 0, 1, 2);//wywo³anie funkcji zarz¹dzaj¹cej przeniesieniami
    else
        cout << "Problem z liczb¹ krazkow.\n";
    //Wyœwietlenie koñcowego u³o¿enia wie¿
    plik<<"koncowe ulozenie:"<<endl;
    cout<<"koncowe ulozenie:"<<endl;
    plik<<"wieza A: ";
    cout<<"wieza A: ";
	wyswietlenieListy(headA);
	plik<<endl<<"wieza B: ";
	cout<<endl<<"wieza B: ";
	wyswietlenieListy(headB);
	plik<<endl<<"wieza C: ";
	cout<<endl<<"wieza C: ";
	wyswietlenieListy(headC);
	plik.close();
    return 0;
}
