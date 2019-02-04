#include "name.h"
#include "lex.h"
#include "name.h"
#include <stdio.h>
#include <error.h>

void statements()
{
    /* 
        statements -> statements statement 
                    | statement
    */
    while (!match(EOI)){
        statement();
    }
}

void statement()
{
    /*
        statement -> ID := expression;
                    | IF expression THEN statement
                    | WHILE expression DO statement
                    | BEGIN statements END
                    | expression;
    */
    if (match(NUM_OR_ID)){
        if( !legal_lookahead( EQU, 0 ) )
	        return;
        advance();
        expression();
    }
    else if(match(IF)){
        if (!legal_lookahead(THEN, 0))
            return;
        advance();
        expression();
        if (match(THEN)){
            statement();
        }
    }
    else if(match(WHILE)){
        if (!legal_lookahead(DO, 0))
            return;
        advance();
        expression();
        if (match(DO)){
            statement();
        }
    }
    else if(match(BEGIN)){
        if (!legal_lookahead(END, 0))
            return;
        advance();
        expression();
        while (!match(END)){
            statement();
        }
    }
    else{
        expression();
    }
    if (match( SEMI ))
    {
        advance();
    }
    else
    {
        fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
    }
}

void expression()
{
    /* expression  -> expression=expression
                    | expression<expression
                    | expression>expression
                    | term expression'

     * expression' -> PLUS term expression'
     *              | MINUS term expression'
     *              |  epsilon
     */

    if( !legal_lookahead( NUM_OR_ID, LP, 0 ) )
	return;

    if (legal_lookahead ( LT, GT, EQEQ)){
        expression();
        if (match(LT) || match(GT) || match(EQEQ))
        {
            advance();
            expression();
        }
    }
    else{
        term();
        while(match(PLUS) || match(MINUS))
        {
            advance();
            term();
        }
    }
}

void term()
{
    /*
        term -> factor term'
        term' -> MULT factor term'
                | DIV factor term'
                | epsilon
    */
    if( !legal_lookahead( NUM_OR_ID, LP, 0 ) )
	return;

    factor();
    while( match(MULT) || match(DIV))
    {
        advance();
        factor();
    }
}

void factor()
{   
    /*
        factor -> NUM_OR_ID
                | LP expression RP
    */

    if( !legal_lookahead( NUM_OR_ID, LP, 0 ) )
	return;

    if( match(NUM_OR_ID) )
        advance();

    else if( match(LP) )
    {
        advance();
        expression();
        if( match(RP) )
            advance();
        else
            fprintf( stderr, "%d: Mismatched parenthesis\n", yylineno );
    }
    else
	fprintf( stderr, "%d: Number or identifier expected\n", yylineno );
}

#include <stdarg.h>

#define MAXFIRST 16
#define SYNCH	 SEMI

int	legal_lookahead(int first_arg, ... )
{
    /* Simple error detection and recovery. Arguments are a 0-terminated list of
     * those tokens that can legitimately come next in the input. If the list is
     * empty, the end of file must come next. Print an error message if
     * necessary. Error recovery is performed by discarding all input symbols
     * until one that's in the input list is found
     *
     * Return true if there's no error or if we recovered from the error,
     * false if we can't recover.
     */

    va_list  	args;
    int		tok;
    int		lookaheads[MAXFIRST], *p = lookaheads, *current;
    int		error_printed = 0;
    int		rval	      = 0;

    va_start( args, first_arg );

    if( !first_arg )
    {
	if( match(EOI) )
	    rval = 1;
    }
    else
    {
	*p++ = first_arg;
	while( (tok = va_arg(args, int)) && p < &lookaheads[MAXFIRST] )
	    *p++ = tok;

	while( !match( SYNCH ) )
	{
	    for( current = lookaheads; current < p ; ++current )
		if( match( *current ) )
		{
		    rval = 1;
		    goto exit;
		}

	    if( !error_printed )
	    {
		fprintf( stderr, "Line %d: Syntax error\n", yylineno );
		error_printed = 1;
	    }

	    advance();
	}
    }

exit:
    va_end( args );
    return rval;