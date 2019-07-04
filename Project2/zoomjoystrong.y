%{
	/*****************************************************************
	*This file uses the lex tokens to call on functions described in
	*the associated c file. 
	*
	*@authors Cade Baker and Megan Thomas 
	*@version March 2018
	*****************************************************************/
	#include <stdio.h>
	void yyerror(const char* msg);	
	int yylex();
%}

%error-verbose
%start image

%union { int i; char* str; float f;}

%token END
%token END_STATEMENT
%token POINT
%token LINE
%token CIRCLE
%token RECTANGLE
%token SET_COLOR
%token INT
%token FLOAT 

%type<str> END
%type<str> END_STATEMENT
%type<str> POINT
%type<str> LINE
%type<str> CIRCLE
%type<str> RECTANGLE
%type<str> SET_COLOR
%type<i> INT
%type<f> FLOAT 

%%

image:	line image
	|	point image
	|	circle image
	|	rectangle image
	|	set_color image
	|	end
;

line:		LINE INT INT INT INT END_STATEMENT
		{printf("%s %d %d %d\n", $1, $2, $3, $4, $5);

		//checks if all the values are valid 
		if ($2 < 0 || $2 > 1024)
                        yyerror("First value is invalid.");
                if ($3 < 0 || $3 > 768)
                        yyerror("Second value is invalid.");
                if ($4 < 0 || $4 > 1024)
                        yyerror("Third value is invalid.");
		if ($5 < 0 || $5 > 768)
			yyerror("Fourth value is invalid.");
		
		//if all the values are valid we call the line fincuton 
		line($2,$3,$4,$5); }
;

point:		POINT INT INT END_STATEMENT
		{ printf("%s %d %d\n", $1, $2, $3); 
		
		//checks if all values are valid 
		if ($2 < 0 || $2 > 1024)
                        yyerror("First value is invalid.");
                if ($3 < 0 || $3 > 768)
                        yyerror("Second value is invalid.");
  
		//if all values are valid we call the point function 
		point($2,$3); }
;

circle:		CIRCLE INT INT INT END_STATEMENT
		{ printf("%s %d %d %d\n", $1, $2, $3, $4);
		
		//checks if all values are valid 
		if ($2 < 0 || $2 > 1024)
                        yyerror("First value  is invalid.");
                if ($3 < 0 || $3 > 768)
                        yyerror("Second value is invalid.");
                if ($4 < 0 || $4 > 1024)
                        yyerror("Third value is invalid.");
		
		//if all values are valid we call the circle function 
		circle($2,$3,$4); }
;

rectangle:	RECTANGLE INT INT INT INT END_STATEMENT
		{ printf("%s %d %d %d %d\n", $1, $2, $3, $4, $5);
		
		//checks if all the values are valid
		if ($2 < 0 || $2 > 1024)
                        yyerror("First value is invalid.");
                if ($3 < 0 || $3 > 768)
                        yyerror("Second value is invalid.");
                if ($4 < 0 || $4 > 1024)
                        yyerror("Third value is invalid.");
		if ($5 < 0 || $5 > 768)
			 yyerror("Fourth value is invalid.");
		
		//if all values are valid we call the rectangle function 
		rectangle($2,$3,$4,$5); }
;

set_color:	SET_COLOR INT INT INT END_STATEMENT
		{ printf("%s %d %d %d\n", $1, $2, $3, $4);	
		
		//checks if the values are valid 
		if ($2 < 0 || $2 > 255)
			yyerror("First value is invalid.");
		if ($3 < 0 || $3 > 255)
			yyerror("Second value is invalid.");
		if ($4 < 0 || $4 > 255)
			yyerror("Third value is invalid.");
		
		//if all values are valid we call the set color function 
		set_color($2, $3, $4); }
;

end:		END END_STATEMENT
		{ printf("%s\n", $1); 
		//closes the display 
		finish();
		}
;

%%
int main(int argc, char** argv){
	printf("\n==========\n");
	//creates the image display 
	setup();
	//parses the file 
	yyparse();
	return 0;
}
void yyerror(const char* msg){
	//prints error message 
	fprintf(stderr, "ERROR! %s\n", msg); 
}
