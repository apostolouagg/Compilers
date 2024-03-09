// Pikrakis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	cout << "DOSE SYMBOLOSEIRA: ";
	string symbseira;
	cin >> symbseira; //εισαγει ο χρηστης τη συμβολοσειρα σε αυτη τη μεταβλητη
	int something = symbseira.size(); //στη μεταβλητη something βαζουμε το μεγεθος της συμβολοσειρας
	stack <char> s; //οριζουμε στοιβα s
	bool check = true; //boolean που θα μας βοηθησει να μαθουμε αν η συμβολοσειρα ξεκιναει με x ή οχι
	int counterx = 0; //μετραει τα x
	int countery = 0; //μετραει τα y
	if (symbseira[0] == 'x') //αν η συμβολοσειρα ξεκιναει με x
	{
		cout << "to proto grama einai x , ara synexizeme \n ";
		for (int i = 0; i < something; i++) //ξεκινα επαναληψη και παιρνουμε ενα ενα τα στοιχεια της συμβολοσειρας με τη βοηθεια του i
		{
			if (symbseira[i]=='x'||symbseira[i]=='y') //ελεγχουμε αν τα στοιχεια της συμβολοσειρας ειναι x ή y
			{
				cout << "to symbolo einai x h y ,synexizoyme \n ";
				if(symbseira[i]=='x') //αν ειναι x
				{
					s.push(symbseira[i]); //εισαγωγη στοιχειου x στη στοιβα
					counterx++; //μετρητης x που αυξανεται κατα 1
					cout << "to symbolo einai x ara prosththete sto stack\n ";
				}
				else //αν ειναι y 
				{
					cout << "to symbolo einai y ,";
					countery++; //μετρητης y που αυξανεται κατα 1
					if(!s.empty()) //αν η συμβολοσειρα δεν ειναι αδεια
					{
						s.pop(); //αφαιρει στοιχειο απο τη στοιβα
						cout << "afairethike to x \n";
					}
					else //αν η συμβολοσειρα ειναι αδεια
					{
						cout << "den yparxei x, kai afoy den yparxei x den einai egkyro \n";
						break; /* δεν γινεται να διαγραφει στοιχειο αν η στοιβα ειναι αδεια, επομενως τα x ειναι λιγοτερα απο τα y,
							      οποτε βγαινουμε απο την επαναληψη, η συμβολοσειρα δεν ειναι εγκυρη */
					}
				}
			
			}
			else
			{
				cout << "Lathos eisagogi , h symboloseira den einai egkirei \n";
				break; /*το εκαστοτε στοιχειο στη συμβολοσειρα δεν ειναι ουτε x ουτε y επομενως βγαινουμε απο την επαναληψη,
					     η συμβολοσειρα δεν ειναι εγκυρη */
			}
		}
	}
	else
	{
		cout << "to proto symbolo den einai x, ara mh apodekth \n ";
		check = false; //η συμβολοσειρα δεν ξεκιναει με x αρα το check γινεται false, η συμβολοσειρα δεν ειναι εγκυρη
	}

	if(s.empty() && (counterx == countery) && check) /* αν η στοιβα ειναι αδεια, τα x ειναι ισα με τα y και η check ειναι true
													    (δηλαδη η συμβολοσειρα ξεκιναει με x), τοτε η συμβολοσειρα ειναι αποδεκτη */
	{
		cout << "Egine apodekth";
	}
	else //αν τα παραπανω δεν ισχουν η συμβολοσειρα δεν ειναι αποδεκτη
	{
		cout << "mh apodekth";
	}
	
	
	
}

/*xyxyxyxyxyxyyxyxyxyxyxyxxxxyyy 
 *ta bazoyme me thn seira sto stack kai kanoyme ta parakato 
 *{x    if x counterx++
 *y    if y countery++
 *countery>counterx break cout lathos}
 *.....
 *counterx==countery{
 *cout sosto
 *}
 *else{cout lathos}
 *
 * 
 */