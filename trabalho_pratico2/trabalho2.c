#include <stdio.h>

int countStudents( int* students, int studentsSize, int* sandwiches, int sandwichesSize ) {
    int count[2] = {0}; 

    for ( int i = 0; i < studentsSize; i++ ) {
        count[students[i]]++;
    }

    for ( int i = 0; i < sandwichesSize; i++ ) {
        if ( count[sandwiches[i]] > 0 ) {
            count[sandwiches[i]]--;
        } else {
            break;
        }
    }

    return ( count[0] + count[1] );
}

int main() {
    int students[] = {0, 1, 0, 1};
    int sandwiches[] = {0, 1, 1, 0};
    int studentsSize = 4;
    int sandwichesSize = 4;

    int unableToEat = countStudents( students, studentsSize, sandwiches, sandwichesSize );
    printf( "\nNumero de estudantes que nao podem comer: %d\n", unableToEat );

    return 0;
}