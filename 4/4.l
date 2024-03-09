/*definition section*/
/*define the syntactic rules*/
/*rule section*/
/*Check the syntactic rule expression, the input corresponds with the rule Expression, the expression is recognized from the syntactic analyzer*/
/*else, the expresion is unrecognized from the syntactic analyzer*/
/*post proccessing section*/
/*call the flex function (returns the input of the lexical analyzer)*/
Letters [a-zA-Z] 
Digits [1-9]
Operators [+*-/%]
Symbol {Digits}|{Letters}
Assign {Operators}{Symbol}
Expression {Letters}"="{Symbol}{Assign}+";" 
%% 
{Expression} {
    printf("Recognized expression");
}
[^\n]+ printf("Unrecognized expression");
%% 
main() {
    yylex();
}