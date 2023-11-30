#include <string>
#include<list>
#include <algorithm>
#include <iostream>

using namespace std;

void spinners() {
    long long a, b, c, n = 0, st = 0, end;
    cin >> a >> b >> c;
    end = c + 2;
    n = (end + st) / 2;
    if (a + b > c)
        cout << 0;
    else {
        while (a + b * n > c || a + b * (n + 1) <= c) {
            if (a + b * n >= c) {
                end = n + 1;
                n = (end + st) / 2;
            }
            else {
                st = n - 1;
                n = (end + st) / 2;
            }
        }
        cout << n;
    }
}

void notspinners() {
    int n, m, ans_x = 0, ans_y = 0;
    cin >> n >> m;
    for (int x = 0; x < n; x++)
        ans_x += n - x;
    for (int y = 0; y < m; y++)
        ans_y += m - y;
    cout << ans_x * ans_y;
    /*int n, m;
    cin >> n >> m;
    cout << (n * (n + 1) / 2 * m * (m + 1) / 2);*/
}

string puck(int a[], int k = 0, string s = "", int sm = 0) {
    if (k == 9 and sm == 1989)
        return s;
    else if (k < 9) {
        return puck(a, k + 1, s + "+" + to_string(a[k]), sm + a[k]) != "pen" ? puck(a, k + 1, s + "+" + to_string(a[k]), sm + a[k]) : puck(a, k + 1, s + "-" + to_string(a[k]), sm - a[k]);
    }
    return "pen";
}

void baza80() {
    int numbers[9] = { 12894, 4193, 9510, 8653, 4381, 2546, 1158, 8645, 2587 };
    cout << puck(numbers);
}

int a[100];

void dec(int n, int m, int i, int k) {
    if (k == 0) {
        if (n == 1) {
            int j;
            for (j = 0; j < i; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else
        {
            if (n % m == 0)
            {
                a[i] = m;
                dec(n / m, m, i + 1, k);
            }

            if (m > 2) {
                dec(n, m - 1, i, k);
            }
        }
        return;
    }
    else {
        if (n == 1 && i == k) {
            int j;
            for (j = 0; j < i; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else
        {
            if (n % m == 0)
            {
                a[i] = m;
                dec(n / m, m, i + 1, k);
            }

            if (m > 2) {
                dec(n, m - 1, i, k);
            }
        }
        return;
    }
}

void baza90() {
    int n, k;
    cin >> n >> k;
    dec(n, n, 0, k);
}

int main()
{
    //spinners();
    //notspinners();
    //baza80();
    baza90();
}