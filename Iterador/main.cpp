#include <iostream>
#include <list>
#include <vector> // sin .h

using namespace std;

template <typename Container>
void Write(Container &ds, ostream &os) {
    // Utilizamos typename para acceder a tipos dependientes
    typename Container::iterator iter = ds.begin();
    for (; iter != ds.end(); ++iter)
        os << *iter << "\n";
}

int main(int argc, char *argv[]) {
    list<float> mylist;
    vector<float> myvector;

    // Insertar valores flotantes en los contenedores
    for (int i = 0; i < 10; i++) {
        mylist.push_back(static_cast<float>(i));
        myvector.push_back(static_cast<float>(i + 50));
    }

    // Imprimir los valores de los contenedores
    Write(mylist, cout);
    Write(myvector, cout);

    return 0;
}