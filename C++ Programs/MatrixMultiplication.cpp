#include <iostream>

using namespace std;

int main() {
  int matriks1[10][10], matriks2[10][10], hasil[10][10];
  int i, j, k, m, n, p, q, jumlah = 0;
  cout << "Enter the number of rows of the first matrix: ";
  cin >> m;
  cout << "Enter the number of columns of the first matrix: ";
  cin >> n;

  cout << "Enter the number of rows of the second matrix: ";
  cin >> p;
  cout << "Enter the number of columns of the second matrix: ";
  cin >> q;

  if(n != p){
    cout << "Matrices cannot be multiplied by each other.\n";
  } else {

    cout << "Insert the first matrix element: \n";
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        cin >> matriks1[i][j];
      }
    }

    cout << "Enter the second matrix element: \n";
    for(i = 0; i < p; i++){
      for(j = 0; j < q; j++){
        cin >> matriks2[i][j];
      }
    }

    for(i = 0; i < m; i++){
      for(j = 0; j < q; j++){
        for(k = 0; k < p; k++){
          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
        hasil[i][j] = jumlah;
        jumlah = 0;
      }
    }

    cout << "Matrix multiplication result: \n";
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        cout << hasil[i][j] << "\t";
      }
      cout << endl;
    }

  }

  return 0;
}
