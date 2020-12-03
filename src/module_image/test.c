#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {
    
    FILE * inputFile;
    
    argc--;   argv++;
    
    if ( argc == 0 ) {
        printf( "Usage: sample filename...\n" );
        exit( 0 );
    }
    
    inputFile = fopen( argv[0], "a" );
    if ( inputFile == NULL ) {
        fprintf( stderr, "Cannot open file %s\n", argv[0] );
        exit( 0 );
    }
    
    fprintf( inputFile, "Appending a new message in the file\n" );

    fclose( inputFile );
        
    return 0;
}