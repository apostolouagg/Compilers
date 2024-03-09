// pikarakis thema 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	string s = "E";
	
	int steps = 0;//Bhmata poy exoyn ginei
	bool done = false;
	int maxr;//sto maxr bazoyme thn megisti timh poy mporei na parei to r ston kanona toy A etsi oste na termazite to programa
	int r;//sto r bazoume to random
	while (!done)//to done to allazoyme se false opou o kanonas prosteti mh termatiko
	{
		srand(time(nullptr));
		
		done = true;//Ypothetoyme oti teleionei se afti thn epanalipsi 
		if (s.find('E') != string:: npos)//Elegxoyme an uyparxei (to find gyrnaei -1 and den brethei)
		{
			s.replace(s.find('E'), 1, "(Y)");//allazoyme to E se (Y) symfona me ton proto kanona
			cout << s<<endl;//emafanizoyme thn proti allagi 
			steps++;//afxanoyme ta vhmata poy exoyn ginei
			done = false;
		}
		if (s.find('Y')!=string::npos)
		{
			s.replace(s.find('Y'), 1, "AB");//Allazoyme to Y se AB symfona me ton 2o kanona 
			cout << s<<endl;
			steps++;
			done = false;
		}
		if (s.find('A')!=string::npos)
		{
			if (steps <= 20)// An exei perasei ta 100 steps tote den afinei thn deyterh periptosh toy kanona poy odigei sto na mhn teleionei 
			{
				maxr = 2;//mporei na 
			}
			else
			{
				maxr = 1;
			}
			r = rand() % maxr + 1;
			if (r ==1)
			{
				s.replace(s.find('A'), 1, "n");//
				cout << s<<endl;
				steps++;
			}
			else
			{
				s.replace(s.find('A'), 1, "E");
				cout << s<<endl;
				steps++;
				done = false;
			}
		}
		if (s.find('B') != string::npos)
		{
			r = rand() % 3 + 1;//den mas enoxlei kamia apo tis periptoseis giati oles odigoyn se kapoio shmeio se termatismo
			if (r==1)
			{
				s.replace(s.find('B'), 1, "-Y");
				cout << s << endl;
				steps++;
				done = false;
			}
			else if(r==2)
			{
				s.replace(s.find('B'), 1, "+Y");
				cout << s << endl;
				steps++;
				done = false;
			}
			else
			{
				s.replace(s.find('B'),1,"");
				cout << s << endl;
				steps++;
			}
		}
	}
	
}	

