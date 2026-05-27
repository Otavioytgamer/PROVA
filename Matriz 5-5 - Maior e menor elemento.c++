#include <iostream>
using namespace std;

int main() {
    int mat[5][5], maior, menor;
    
    cout << "Digite os valores da matriz 5x5:\n";
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> mat[i][j];
    
    maior = menor = mat[0][0];
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) {
            if(mat[i][j] > maior) maior = mat[i][j];
            if(mat[i][j] < menor) menor = mat[i][j];
        }
    
    cout << "\nMaior elemento: " << maior << endl;
    cout << "Menor elemento: " << menor << endl;
    
    return 0;
}