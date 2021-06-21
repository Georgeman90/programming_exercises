/*
-----------------------------------------------------------
-
-- Crea un algoritmo che:
-
--- data una lista L di numeri
--- dato un numero k
-
--- restituisce TRUE se
--- k è la somma di due numeri in L
-
-
-- Bonus: fallo con una sola passata
-----------------------------------------------------------
*/


// includes ---------------------------

#include <stdbool.h>
#include <stdio.h>  //printf()
#include <stdlib.h> //malloc()



// type definitions -------------------

typedef  unsigned int  Number;

#define  invalidNumber  0


struct list_ {
	Number n;
	struct list_* next;
};
typedef  struct list_  list;
typedef  list*         LIST;

#define  invalidListElement  (LIST) NULL

LIST newListElement( void );

void destroyList( LIST );

unsigned int getListLenght( LIST );

void printList( LIST );



// functions definitions --------------

LIST generateMyList( void );

bool isSumOfTwoNumbers( LIST, Number );  // algoritmo -----



// main -------------------------------

int main() {
	
	
	Number k = 0;
	
	
	LIST myList = generateMyList();  if( myList == invalidListElement ) return -1;
	
	
	printList( myList );
	
	do {
		
		printf("\nDimmi un numero k: ");
		scanf("%u", &k);
		
		if( isSumOfTwoNumbers( myList, k ) ) printf("\n SI : %u e' la somma di due numeri nella lista.\n", k);
		
		else                                 printf("\n NO : %u non e' la somma di due numeri nella lista.\n", k);
		
	} while( k != 0 );
	
	
	destroyList( myList );
	
	return 0;
}



// functions body ---------------------

bool isSumOfTwoNumbers( LIST L, Number k ) {
	
	
	const unsigned int hashTableSize = 1000;
	
	Number* hashTable = (Number*) calloc( hashTableSize, sizeof(Number) ); if( hashTable == NULL ) return false;
	
	
	for( LIST element = L; element != invalidListElement; element = element->next ) {
		
		if( hashTable[( element->n ) % hashTableSize] == 1 ) return true;
		
		hashTable[( k - element->n ) % hashTableSize] = 1;
		
	}
	
	
	free(hashTable);
	
	return false;
}

LIST generateMyList( void ) {
	
	LIST outputList = newListElement();
	
	LIST element1 = outputList;
	element1->n = 15;
	element1->next = newListElement();
	
	LIST element2 = element1->next;
	element2->n = 32;
	element2->next = newListElement();
	
	LIST element3 = element2->next;
	element3->n = 44;
	element3->next = newListElement();
	
	LIST element4 = element3->next;
	element4->n = 12;
	element4->next = newListElement();
	
	LIST element5 = element4->next;
	element5->n = 9;
	element5->next = newListElement();
	
	LIST element6 = element5->next;
	element6->n = 5;
	element6->next = newListElement();
	
	LIST element7 = element6->next;
	element7->n = 22;
	element7->next = newListElement();
	
	LIST element8 = element7->next;
	element8->n = 6;
	element8->next = newListElement();
	
	LIST element9 = element8->next;
	element9->n = 16;
	
	return outputList;
}



// list management --------------------

LIST newListElement( void ) {
	
	LIST element = (LIST) malloc(sizeof(list));
	
	if( element != invalidListElement) {
		
		element->n = invalidNumber;
		element->next = invalidListElement;
	}
	
	return element;
}

void destroyList( LIST inputList ) {
	
	LIST element = inputList;
	
	LIST next_element = element;
	
	
	while( next_element != invalidListElement ) {
		
		next_element = element->next;
		
		free(element);
		
		element = next_element;
	}
	
}

unsigned int getListLenght( LIST inputList ) {
	
	unsigned int lenght = 0;
	
	LIST element = inputList;
	
	
	while( element != invalidListElement ) {
		
		lenght++;
		
		element = element->next;
		
	}
	
	return lenght;
}

void printList( LIST inputList ) {
	
	LIST element = inputList;
	
	
	while( element != invalidListElement ) {
		
		printf(" %d ", element->n);
		
		element = element->next;
	}
	
	printf("\n");
}

