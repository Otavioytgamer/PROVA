#include <iostream>
using namespace std;

int main() {
    float precos[50];
    
    cout << "Digite o preco de 50 produtos:\n";
    for(int i = 0; i < 50; i++) {
        cout << "Produto " << i+1 << ": ";
        cin >> precos[i];
    }
    
    cout << "\nLista de precos:\n";
    for(int i = 0; i < 50; i++) {
        cout << "Produto " << i+1 << ": R$ " << precos[i] << endl;
    }
    
    return 0;
}