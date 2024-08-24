#include <iostream>
using namespace std;
typedef float (*operaciones)(float, float);
float sumar(float x, float y) { return x + y; }
float restar(float x, float y) { return x - y; }
float multiplicar(float x, float y) { return x * y; }
float dividir(float x, float y)
{
  if (y == 0) 
  {
    cout << "Error: No se puede dividir por cero." << endl;
    return 0;
  }
  return x / y;
}

int main() {
  operaciones operaciones[] = {&::sumar, &::restar, &::multiplicar, &::dividir};
  float num1, num2, resultado;
  int opcion;
  cout << "Elige una operación:\n0) Sumar  1) Restar  2) Multiplicar  3) "
          "Dividir: ";
  cin >> opcion;
  cout << "Introduce el primer número: ";
  cin >> num1;
  cout << "Introduce el segundo número: ";
  cin >> num2;

  if (opcion >= 0 && opcion <= 3) {
    resultado = operaciones[opcion](num1, num2);
    cout << "El resultado es: " << resultado << endl;
  } else {
    cout << "Opción no válida." << endl;
  }

  return 0;
}