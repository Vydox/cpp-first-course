#include <math.h>
#include <iostream>  
#include <iomanip>
#include <stdlib.h> 
#include <time.h>


using namespace std;

int main()
{
    const int n = 5, m = 5;
    int a[n][m];

    srand(time(NULL));
    for (int i = 0; i < n; i++)   
        for (int j = 0; j < m; j++) 
            a[i][j] = rand() % 100;

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++)    
            cout << setw(3) << a[i][j];  
        cout << endl; 
    }

    cout << endl;


    
       /*for (int j = 0; j <= n; j++) {
            int max = a[n - 1][j];
            int index_max = j;
            for (int k = j + 1; k < n; k++)
                if (*(*(a + (n - 1)) + k) > max) {

                    max = a[n - 1][k];
                    index_max = k;


                }
            a[n - 1][index_max] = a[n - 1][j];
            a[n - 1][j] = max;
        
       }*/

    


    for (int j = 1; j <= n; j++) {
        for (int j = 1; j <= n; j++) {
            if (*(*(a + (n - 1)) + (j - 1)) < *(*(a + (n - 1)) + (j))) {
                for (int i = 0; i < n; i++) {
                    int x = a[i][j - 1];
                    a[i][j - 1] = a[i][j];
                    a[i][j] = x;

                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(3) << a[i][j];
        cout << endl;
    }

}



/**(*(a + (n - 1)) + (j - 1))
* (&a[n - 1][j - 1])*/