#include <iostream>
using namespace std;
struct Vector {
  int *m_pVect, // Pointer to the buffer
      m_nCount, // Control how many elements are actually used
      m_nMax,   // Control how many are allocated as maximum
      m_nDelta; // To control the growing
};

void Resize(int *&rpVect, int &rnMax) {
  const int delta = 10; // Used to increase the vector size
  rpVect = (int *)realloc(rpVect, sizeof(int) * (rnMax + delta));
  rnMax += delta; // The Max has to be increased by delta
}

void Insert(int *&rpVect, int &rnCount, int &rnMax, int elem) {
  if (rnCount == rnMax)     // Verify the overflow
    Resize(rpVect, rnMax);  // Resize the vector before inserting elem
  rpVect[rnCount++] = elem; // Insert the element at the end of the sequence
}