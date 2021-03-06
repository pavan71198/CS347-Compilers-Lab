#include "lex.h"
#include <stdio.h>
#include <stdlib.h>
#include "name.h"
#include <ctype.h>
#include <error.h>
#include <string.h>

char yytext[] =" "; /* Lexeme */
int yyleng   = 0;  /* Lexeme length. */
int yylineno = 0;  /* Line number*/

extern FILE *codefile;

int lex(void){

	static char input_buffer[1024]; /* Input line being taken */
	char        *current;
	current = yytext + yyleng;

	while(1){       
		while(!*current ){
			if (!fgets(input_buffer, 1020, codefile)){
				*current = '\0';
				return EOI;
			}
			else{
				current = input_buffer;
			}
			++yylineno;
			while(isspace(*current))
				++current;
		 }
		for(; *current; ++current){
			/* Get the next token */
			yytext = current;
			yyleng = 1;
			switch( *current ){
				case ';':
					return SEMI;
				case '+':
					return PLUS;
				case '-':
					return MINUS;
				case '*':
					return MULT;
				case '/':
					return DIV;
				case '(':
					return LP;
				case ')':
					return RP;
				case '<':
					return LT;
				case '>':
					return GT;
				case '=':
					return EQEQ;
				case ':': 
					{	
						current++;
						if (*current=='='){
							return EQU;
						}
						else{
							fprintf(stderr, "Error in :=");
							return -1;
						}
					}
				case '\n':
				case '\t':
				case ' ' :
					return -1;
			  default:
				if(!isalnum(*current))
					fprintf(stderr, "Not alphanumeric <%c>\n", *current);
				else{
					while(isalnum(*current))
						++current;
					yyleng = current - yytext;
					char temp_str[yyleng+1];
					temp_str[yyleng] = '\0';
					strncpy(temp_str, yytext, yyleng);
					if (!strcmp(temp_str, "if")){
						return IF;
					}
					else if (!strcmp(temp_str, "then")){
						return THEN;
					}
					else if (!strcmp(temp_str, "while")){
						return WHILE;
					}
					else if (!strcmp(temp_str, "do")){
						return DO;
					}
					else if (!strcmp(temp_str, "begin")){
						return BEGIN;
					}
					else if (!strcmp(temp_str, "end")){
						return END;
					}
					else{
						return NUM_OR_ID;
					}
				}
				return -1;
			}
		}
	}
}


static int Lookahead = -1; /* Lookahead token  */

int match(int token){
	/* Return true if "token" matches the
		current lookahead symbol.                */

	if(Lookahead == -1)
		Lookahead = lex();

	return token == Lookahead;
}

void advance(void){
/* Advance the lookahead to the next
	input symbol.                               */

	 Lookahead = lex();
}
