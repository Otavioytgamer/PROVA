#include <iostream>
using namespace std;

int main() {
    int vetor[10];
    
    cout << "Digite 10 numeros:\n";
    for(int i = 0; i < 10; i++) {
        cin >> vetor[i];
    }
    
    cout << "\nNumeros pares do vetor: ";
    for(int i = 0; i < 10; i++) {
        if(vetor[i] % 2 == 0) {
            cout << vetor[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}