#include <iostream>

using namespace std;

void swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool generate(int* a, int n)
{
    int j = n - 2; 
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false;
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;
    while (l < r)
        swap(a, l++, r--);
    return true;
}

bool perestanovki(int* a, int n) {
    for (int i = 0; i < n; i++)
        if (i == a[i])
            return true;
    return false;
}

int main()
{
    int n, ans = 1;
    cin >> n;
    int* urna = new int[n];
    for (int i = 0; i < n; i++)
        urna[i] = i;
    while (generate(urna, n))
        if (perestanovki(urna, n))
            ans++;
    cout << ans;
}