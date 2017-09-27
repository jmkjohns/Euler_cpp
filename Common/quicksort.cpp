#define CREATESORT(_TYPE_) \
void sort( _TYPE_ *array, bool (*compare)(_TYPE_, _TYPE_), int start, int end ) { \
if (end - start > 0) { \
_TYPE_ *swapPtr = array + start; \
_TYPE_ *curPtr = array + start; \
_TYPE_ *pivot = array + end; \
_TYPE_ tmp; \
while (curPtr < array + end ) { \
if (compare( *curPtr, *pivot)) { \
tmp = *curPtr; \
*curPtr = *swapPtr; \
*swapPtr = tmp; \
swapPtr++; } \
curPtr++; } \
tmp = *swapPtr; \
*swapPtr = *pivot; \
*pivot = tmp; \
sort( array, compare, start, (swapPtr - array) - 1 ); \
sort( array, compare, (swapPtr - array) + 1, end ); } }
