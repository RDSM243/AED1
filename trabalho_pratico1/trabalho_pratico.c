#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Você esta subindo uma escada. Cada vez voce pode subir 1 ou 2 degraus
//De quantas maneiras diferentes você pode chegar no topo ?

int main( void ){

    int degraus = -1, aux1 = 0, aux2 = 1, metodos = 0;
    char resposta;

   while( true ){
        printf( "\nDigite o numero de degraus da escada(de 1 a 45): " );
        scanf( "%d", &degraus );

        while( degraus < 1 || degraus > 45 ){
            printf( "\nNumero invalido ! Digite o numero de degraus da escada(de 1 a 45): " );
            scanf( "%d", &degraus );
        }

        for( int i = 0; i < degraus; i++ ){
            metodos = aux1 + aux2;
            aux1 = aux2;
            aux2 = metodos;
        }

        printf( "\nVocê pode subir a escada de %d formas diferentes.\n", metodos );

        printf( "Deseja reiniciar o programa(Y/N) ? " );
        
        scanf( "%s", &resposta );

        if ( resposta == 'N' || resposta == 'n' ) exit(1);
   }
    return 0;
}