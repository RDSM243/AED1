/*
====================
RomanToInt

Recebe numeros como uma string e os converte em numeros romanos
====================
*/

int RomanToInt( char * s ) {
    
    int quant = 0, len = strlen( s );
    
    for ( int i = 0 ; i < len ; i++ ) {
        if ( s[i] == 'I' ) {
            if( ( i+1 > len ) ) quant++;
            else {
                if( s[ i+1 ] == 'V' || s[ i+1 ] == 'X' ) quant--;
                else quant++;
            }
        }
        else if ( s[i] == 'V' ) quant += 5;
        else if ( s[i] == 'X' ) {
            if ( ( i+1 > len ) ) quant += 10;
            else {
                if( s[i+1] == 'L' || s[i+1] == 'C' ) quant -= 10;
                else quant += 10;
            }
        }
        else if( s[i] == 'L' ) quant += 50;
        else if( s[i] == 'C' ) {
            if ( ( i+1 > len ) ) quant += 100;
            else {
                if ( s[i+1] == 'D' || s[i+1] == 'M' ) quant -= 100;
                else quant += 100;
            }
        }
        else if ( s[i] == 'D' ) quant += 500;
        else if ( s[i] == 'M' ) quant += 1000;
    }
    
    return quant;
}   