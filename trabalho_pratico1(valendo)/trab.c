#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Link do repositório: https://github.com/RDSM243/AED1/tree/main/trabalho_pratico1(valendo)

//Calcula a posição do robo de acordo com seus movimentos e retorna o resultado em bool
bool judgeCircle( char *moves ) {
    int x = 0, y = 0; // Coordenadas iniciais

    // Percorre a string de movimentos
    for( int i = 0; moves[i] != '\0'; i++ ) {
        // Atualiza as coordenadas de acordo com o movimento atual
        switch( moves[i] ) {
            case 'R': x++; break; // Direita
            case 'L': x--; break; // Esquerda
            case 'U': y++; break; // Cima
            case 'D': y--; break; // Baixo
        }
    }

    // Verifica se o robô retornou para a posição inicial
    return ( x == 0 ) && ( y == 0 );
}

int main() {
    char *moves = NULL;
    char move;
    int num_moves = 0;

    printf( "\nR = Direita\nL = Esquerda\nU = Cima\nD = Baixo" );
    printf( "\nDigite a sequencia de movimentos do Robo: " );
    
    while( true ){

        move = getchar();

        // Sai do loop
        if( move == '\n' ){
            break;
        }

        num_moves++;

        moves = realloc( moves, num_moves * sizeof(char) );
    
        moves[ num_moves - 1 ] = move;
    }
    
    bool resultado = judgeCircle( moves );

    printf( "O robô retornou para o ponto de origem? %s\n", resultado ? "Sim" : "Nao" );

    free( moves );

    return 0;
}
