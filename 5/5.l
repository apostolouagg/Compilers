%{
 #include <stdio.h>
 int flag = 0; //metraei ta shmeia
 int i = 0; //metrhths
 int j = 0; //metrhths
 int x1 = 0; //pairnei ton arithmo pou steilame sth sunarthsh Shape()
 int ret = 0; //pairnei auto pou epistrefei h Shape()
 char *s = " "; //pointer pou einai isos me " " (to xrhsimopoioume gia na doume an uparxoun kena sto input tou xrhsth)
%}
Alphabet [A-H]
Point "point"" "*{Alphabet}{1}
Straight_Line "straight line"" "*{Alphabet}{2}
Triangle "triangle"" "*{Alphabet}{3}
Square "square"" "*{Alphabet}{4}
Pentagon "pentagon"" "*{Alphabet}{5}
Hexagon "hexagon"" "*{Alphabet}{6} 
Heptagon "heptagon"" "*{Alphabet}{7}
Octagon "octagon"" "*{Alphabet}{8}
%%
{Point} {
  printf("This is a point");
}
{Straight_Line} {
  ret = Shape(2);
  if(ret == 2){
    printf("This is a straight line");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Triangle} {
  ret = Shape(3);
  if(ret == 3){
    printf("This is a triangle");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Square} {
  ret = Shape(4);
  if(ret == 4){
    printf("This is a square");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Pentagon} {
  ret = Shape(5);
  if(ret == 5){
    printf("This is a pentagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Hexagon} {
  ret = Shape(6);
  if(ret == 6){
    printf("This is a hexagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Heptagon} {
  ret = Shape(7);
  if(ret == 7){
    printf("This is a heptagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Octagon} {
    ret = Shape(8);
  if(ret == 8){
    printf("This is an octagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
[^\n]+ printf("Unrecognized expression");
%%
main() {
  yylex();
}

/* Βάζουμε το flag = 0 για να μην κρατάει τις προηγούμενες τιμές. Το x1 παίρνει την τιμή που στείλαμε στη συνάρτηση.
   Αντιγράφουμε το yytext σε ένα *yycopy για ευκολία, διότι το yytext έχει περιορισμένες δυνατότητες ως προς τις συγκρίσεις.
   Μετά με 2 επαναλήψεις τρέχουμε το input του χρήστη από πίσω προς τα μπρος και περιορίζουμε τον αριθμό των επαναλήψεων με
   βάση τον αριθμό των σημείων (που δίνουμε στη Shape(), πχ για τρίγωνο δίνουμε τον αριθμό 3 γιατί έχει 3 σημεία) έτσι ώστε να
   κοιτάμε μόνο τα σημεία που έβαλε ο χρήστης και όχι όλο το input, και για να συγκρίνουμε τα γράμματα μεταξύ τους και να ελέγχει
   αν είναι ίδια ή όχι. Το flag αυξάνεται όταν υπάρχει αντιστοιχία γραμμάτων και δεν υπάρχουν κενά. Μετά τις επαναλήψεις ελέγχουμε
   αν το flag (δηλαδή ο αριθμός των ίδιων γράμματων) είναι ίσο με το x1 (δηλαδη τον αριθμό των σημείων που δώσαμε στη συνάρτηση με
   βάση το σχήμα που έγραψε ο χρήστης). Αν είναι true (δηλαδή ο αριθμός των σημείων που πρέπει να έχει το σχήμα είναι ίδιος με τον
   αριθμό των σημείων που έγραψε ο χρήστης), τότε επιστρέφει το flag και το input είναι σωστό, αλλιως επιστρέφει 0 και το input
   είναι λάθος.*/

int Shape(int x){
  flag = 0; 
  x1 = x;
  char *yycopy = strdup(yytext);
  for(i = yyleng - 1; i >= yyleng - x1; --i )
   {
     for(j = yyleng - 1; j >= yyleng - x1; --j )
     {
        if(yycopy[i] == yycopy[j] && yycopy[i] != *s)
       {
         flag++;
       }
     }
   }

   if(flag==x1)
   {
    return flag;
   }
   else
   {
     return 0;
   }
}