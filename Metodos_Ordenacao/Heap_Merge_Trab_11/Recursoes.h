#ifndef RECURSOES_H_INCLUDED
#define RECURSOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// funções que integram o HeapSort e MergeSort

void swap (int*, int, int);
void moveDown(int*, int, int);
void heapSort(int*, int);
void merge(int*, int, int);
void mergeSort(int*, int, int);

#endif // RECURSOES_H_INCLUDED
