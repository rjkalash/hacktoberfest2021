#include <iostream>
using namespace std;
struct eleCount {
    int e;
    int c;
};
void moreThanNdK(int arr[], int n, int k)
{
    if (k < 2)
        return;
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < k - 1; j++)
        {
            if (temp[j].e == arr[i])
            {
                temp[j].c += 1;
                break;
            }
        }
        if (j == k - 1) {
            int l;
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].c == 0)
                {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
            if (l == k - 1)
                for (l = 0; l < k-1; l++)
                    temp[l].c -= 1;
        }
    }
    for (int i = 0; i < k - 1; i++)
    {
        int ac = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
}
int main()
{
    cout << "First Test\n";
    int arr1[] = { 4, 5, 6, 7, 8, 4, 4 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);
    cout << "\nSecond Test\n";
    int arr2[] = { 4, 2, 2, 7 };
    size = sizeof(arr2) / sizeof(arr2[0]);
    k = 3;
    moreThanNdK(arr2, size, k);
    cout << "\nThird Test\n";
    int arr3[] = { 2, 7, 2 };
    size = sizeof(arr3) / sizeof(arr3[0]);
    k = 2;
    moreThanNdK(arr3, size, k);
    cout << "\nFourth Test\n";
    int arr4[] = { 2, 3, 3, 2 };
    size = sizeof(arr4) / sizeof(arr4[0]);
    k = 3;
    moreThanNdK(arr4, size, k);
    return 0;
}
