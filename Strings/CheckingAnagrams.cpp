#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int H[26] = {0}, i;

    for (i = 0; a[i] != '\0'; i++)
    {
        H[a[i] - 97]++;
    }

    for (i = 0; b[i] != '\0'; i++)
    {
        H[b[i] - 97]--;

        if (H[b[i] - 97] < 0)
        {
            cout << "Not anagram";
            break;
        }
        
    }
    if (b[i] == '\0')
        {
            cout << "Anagram";
        }
    return 0;
}