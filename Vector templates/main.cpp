#include <iostream>
using namespace std;
template <typename Type> class CVector {
private:
  Type *m_pVect;        // Pointer to the buffer
  int m_nCount,         // Control how many elements are actually used
      m_nMax,           // Control the number of allocated elements
      m_nDelta;         // To control the growing
  void Init(int delta); // Init our private variables, etc
  void Resize();        // Resize the vector when occurs an overflow

public:
  CVector(int delta = 10); // Constructor
  void Insert(Type &elem); // Insert a new element
};

// Class CVector implementation
template <typename Type> CVector<Type>::CVector(int delta) { Init(delta); }
template <typename Type> void CVector<Type>::Insert(Type &elem) {
  if (m_nCount == m_nMax)     // Verify the overflow
    Resize();                 // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}