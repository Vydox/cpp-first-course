#include <iostream>
#include <string.h>
#include <ctype.h>


using namespace std;

char* change_sub(char* string, unsigned int pos, unsigned int len, char* sub1, char* sub2, unsigned int max);

char* decomp_str(char* s_d);

int main()
{   
    const unsigned int max = 80;
    char s[max], sub1[max], sub2[max];
    int pos, len;

    /*cout << "Enter string: ";
    cin.getline(s, max);

    cout << "Enter substring: ";
    cin.getline(sub2, max);

    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter length: ";
    cin >> len;

    change_sub(s, pos, len, sub1, sub2, max);
    cout << s << endl;
    */
    ////////////////////////////////////////////

    char s_d[max];
    cout << "Enter string to be decompressed: ";
    cin.getline(s_d, max);
    decomp_str(s_d);
    cout << s_d;
}


char* change_sub(char* string, unsigned int pos, unsigned int len, char* sub1, char* sub2, unsigned int max) 
{
    //Вылучэнне падрадка
    unsigned i, j;
    for (i = pos, j = 0; i < (pos + len) && i < strlen(string); i++, j++)
        sub1[j] = string[i];
    sub1[j] = '\0';
    
    //Выдаленне падрадка
    char* s = strstr(string, sub1);
    if (s != NULL)
    {
        unsigned n = s - string;
        unsigned j = strlen(sub1);
        unsigned k = strlen(string) - j;
        for (unsigned i = n; i <= k; i++)
            string[i] = string[i + j];
    }

    //Устаўка падрадка
    unsigned m, n, l = strlen(sub2), k = strlen(string);
    if (l + k <= max && pos <= k)
    {
        for (m = k; m >= pos && m >= 0; m--)
            string[m + l] = string[m];

        string[l + k + 1] = '\0';

        for (m = pos, n = 0; m < pos + l; m++, n++)

            string[m] = sub2[n];
    }

    return string;
}

char* decomp_str(char* s_d) {
    int n;
    char s[100], sub[100], a;

    for (int i = 0; i < strlen(s_d); i++)
    {
        if (isdigit(s_d[i]) != 0) {
            n = int(s_d[i]);
            a = s_d[i + 1];
            sub[100] = s_d[i] + s_d[i + 1];
            for (int i = 0; i < n; i++)
            s[i] = a;
        
            s[n] = '\0';


            char* s = strstr(s_d, sub);
            if (s != NULL)
            {
                unsigned n = s - s_d;
                unsigned j = strlen(sub);
                unsigned k = strlen(s_d) - j;
                for (unsigned i = n; i <= k; i++)
                    s_d[i] = s_d[i + j];
            }

            unsigned m, n, l = strlen(s), k = strlen(s_d);
            if (l + k <= strlen(s_d) && i <= k)
            {
                for (m = k; m >= i && m >= 0; m--)
                    s_d[m + l] = s_d[m];

                s_d[l + k + 1] = '\0';

                for (m = i, n = 0; m < i + l; m++, n++)

                    s_d[m] = sub[n];
            }
        }

        

    }

    return s_d;
}