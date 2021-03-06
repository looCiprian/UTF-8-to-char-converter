//
//  utf-8Function.c
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc/malloc.h>
#include <stdbool.h>


/**
 Controlla se è UTF-8 (check if it is UTF-8)

 @param c carattere da controllare
 @return true se è UTF-8
 */
bool isUTF8(char c){
    
    if (((c >> 7) & 1)==1) {                        //Controllo se il primo bit è 1
        return true;
    }
    return false;
    
}


/**
 Legge caratteri UTF-8 (read only UTF-8 char)

 @param c carattere da leggere
 @return 1° e 2° byte uniti (leggere relazione per la spiegazione)
 */
char readUtf8(char c){
    
    char firstByte=c;
    firstByte &= ~(1 << 7);                     //Imposto a 0 il primo bit
    firstByte &= ~(1 << 6);                     //Imposto a 0 il secondo bit
    firstByte=firstByte<<6;                     //Shifto gli ultimi due bit inprima posizione
    
    char secondc=getchar();
    char secondoByte=secondc;
    secondoByte &= ~(1 << 7);                   //Imposto a 0 il primo bit del secondo byte
    
    secondc=firstByte+secondoByte;              //Sommo i byte
    
    return secondc;

}

/**
 Stampa caratteri UTF-8 (print ONLY "special" char generated by "readUtf8" function, you can check with "isUTF8" function)

 @param c carattere da stampare 
 */
void printUtf8(char c){
    char primoByte=0;
    char secondoByte=0;

    if( ((c >> 6) & 1) ==1)primoByte=-61;
    if ( ((c >> 6) & 1) ==0)primoByte=-62;
    
    secondoByte=c;
    secondoByte |= 1 << 7;
    secondoByte &= ~(1 << 6);
    putchar(primoByte);
    putchar(secondoByte);
}
