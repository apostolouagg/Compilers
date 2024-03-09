// PikrakisAskisi2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    queue<string> prodtree;
    prodtree.push("S");
    string treetemp;
    stack<string> stanl;//stack for the analysis
    stanl.push("$S");//adding the first element
    map <string, string> table = {
        {"S(","(X)"},           //use of map for the grammar rule table
        {"X(","YZ"},
        {"Xa","YZ"},
        {"Xb","YZ"},
        {"Y(","S"},
        {"Ya","a"},
        {"Yb","b"},
        {"Z)","e"},
        {"Z*","*X"},
        {"Z+","+X"},
        {"Z-","-X"}
    };
    string inp;
    cin >> inp;//user input 
    inp.append("$");//adding $at the end of the input 
    char x;//x character during analysis
    char a;//a -//-
    int pos=0;//used so as not to need to delete something from the original input 
    string prod;//for the productions
    string tempS="";//a temporary string used for many different scenarios
    string tempS2 = "";
	while(inp.length()-1!=pos)//this runs as long as we havent reached the end of the string 
	{
        x = stanl.top()[stanl.top().length() - 1];//setting x as the right most character in the top of the stack
        a = inp[pos];//setting a as the "left most" character in the input
		if (x =='('||x==')'||x== 'a'||x=='b'||x=='*'||x=='+'||x=='-'||x=='$')//check for if stack character is a terminal
		{
			
            if (x != '$' && x == a)//1st rule
            {
                pos++;
                tempS = stanl.top();//svzoyme to proto tis sthbas analisis
                tempS.pop_back();//aferoyme to telefteo symbolo 
                stanl.push(tempS);//to janaprosthetoyme sthn syba analisis
                tempS = "";//reset the temporary string 
            }
            else if (x==a&&a=='$')//2nd rule.Using break cause its over and is accepted
            {
                cout << "apodekto!";
                break;
            }
            
		}
        else if(x=='S'||x=='X'||x=='Y'||x=='Z')//an den einai termatiko
        {
	        tempS+= stanl.top()[stanl.top().length() - 1];//sthn oysia soyzoyme to x 
            tempS += inp[pos];//kai to a
        	try//3rd rule   
        	{
        		
                prod.append(table.at(tempS));//tsekarei to table an to brei kai den yparxei exception isxyei o tritos kanonas kai to sozei sthn metablhth poy einai h paragogh
                
                reverse(prod.begin(), prod.end());// thn anapodogyrizoyme gia na mpei anapoda,opos prepei
                tempS2 = stanl.top();//bazoyme to teleftaio ths stoiba analysis
                tempS2.pop_back();//aferoume to teleftaio char
                if (prod != "e") {//tsekaroyme an einai to e (keno)
                    tempS2.append(prod);//prosthetoyme sto temps2 to prod 
                    reverse(prod.begin(), prod.end());//to gyrname pali sto kanoniko
					treetemp= prodtree.back();//to bazoyme se mia metablhth
                    prodtree.push(treetemp.replace(prodtree.back().find(stanl.top()[stanl.top().length() - 1]), 1, table.at(tempS)));//allazoyme sto temptree afto poy allaje kata thn paragogh 
                }
                else//an einai e
                {
                    treetemp = prodtree.back();//idia diadikasia
                    prodtree.push(treetemp.erase(prodtree.back().find(stanl.top()[stanl.top().length() - 1]), 1));//edo aferoyme apla afto poy eixe san paragogh to keno 
                }
                stanl.push(tempS2);//bazoyme sthn sthba analysis afto poy bgalame
                treetemp = "";//kanoyme resey ola ta strings poy peirajame
                prod = "";
                tempS = "";
                tempS2 = "";
        	}catch(exception e)//4th rule (an brethei exception tote den yparxei paragogi kai teleionei me mh apodekth symboloseira)
        	{
                cout << "Mh apodekth ";
                break;
        	}
			
		}
		cout << stanl.top()<<"\n";//kanoyme print to bhma
	}
	while(!prodtree.empty())//oso den einai adeio gia to dentro 
	{
        if (prodtree.size() > 1) {//oso den einai to teleftaio apla trexei kai bazei to belaki 
            cout << prodtree.front() << "=>";
        }
        else//allios gia to teleftaio den bazei belaki
        {
            cout << prodtree.front();
        }
        prodtree.pop();//bggazei afto pou ektypose
	}
}

