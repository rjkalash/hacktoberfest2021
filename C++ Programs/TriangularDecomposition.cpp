#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
   cout << "\t Triangular decomposition Method\n";
   cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
   int n, i, k, j, p;
   float a[10][10], l[10][10] = { 0 }, u[10][10] = { 0 }, sum, b[10], z[10] = { 0 }, x[10] = { 0 };
   //clrscr();
   cout << "Enter the order of matrix ! ";
   cin >> n;
   cout << "Enter all coefficients of matrix : ";
   for (i = 1; i <= n; i++)
   {
       cout << "\nRow " << i << "  ";
       for (j = 1; j <= n; j++)
           cin >> a[i][j];
   }
   cout << "Enter elements of b matrix" << endl;
   for (i = 1; i <= n; i++)
       cin >> b[i];
   //********** LU decomposition *****//
   for (k = 1; k <= n; k++)
   {
       u[k][k] = 1;
       for (i = k; i <= n; i++)
       {
           sum = 0;
           for (p = 1; p <= k - 1; p++)
               sum += l[i][p] * u[p][k];
           l[i][k] = a[i][k] - sum;
       }

       for (j = k + 1; j <= n; j++)
       {
           sum = 0;
           for (p = 1; p <= k - 1; p++)
               sum += l[k][p] * u[p][j];
           u[k][j] = (a[k][j] - sum) / l[k][k];
       }
   }
   //******** Displaying LU matrix**********//
   cout << endl << endl << "LU matrix is " << endl;
   for (i = 1; i <= n; i++)
   {
       for (j = 1; j <= n; j++)
           cout << l[i][j] << "  ";
       cout << endl;
   }
   cout << endl;
   for (i = 1; i <= n; i++)
   {
       for (j = 1; j <= n; j++)
           cout << u[i][j] << "  ";
       cout << endl;
   }

   //***** FINDING Z; LZ=b*********//
   for (i = 1; i <= n; i++)
   {                                        //forward subtitution method
       sum = 0;
       for (p = 1; p < i; p++)
           sum += l[i][p] * z[p];
       z[i] = (b[i] - sum) / l[i][i];
   }
   //********** FINDING X; UX=Z***********//

   for (i = n; i > 0; i--)
   {
       sum = 0;
       for (p = n; p > i; p--)
           sum += u[i][p] * x[p];
       x[i] = (z[i] - sum) / u[i][i];
   }
   //*********** DISPLAYING SOLUTION**************//
   cout << endl << "Set of solution is" << endl;
   for (i = 1; i <= n; i++)
       cout << endl << x[i];

   _getch();
   return 0;
}
