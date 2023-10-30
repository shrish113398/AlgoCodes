// For finding the intersection of the rectangles, the following gives the endpoints of the diagonal :

//     X5 = max(X1, X3)

//         Y5 = max(Y1, Y3)

//             X6 = min(X2, X4)

// Y6 = min(Y2, Y4)

// For the rectangle to exist, X5 ≤ X6 and Y5 ≤ Y6.

// Area of union of rectangles would be: Sum of area of rectangles - Area of intersection of rectangles

// Time Complexity per test case: O(1)

#include <bits/stdc++.h>
                using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS int t = 1;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        int a1 = max(x1, x3), b1 = max(y1, y3);
        int a2 = min(x2, x4), b2 = min(y2, y4);
        int ari = 0;
        if (a1 <= a2 && b1 <= b2)
        {
            ari = (a2 - a1) * (b2 - b1);
        }
        int ar1 = (x2 - x1) * (y2 - y1);
        int ar2 = (x4 - x3) * (y4 - y3);
        cout << ari << " " << ar1 + ar2 - ari << "\n";
    }
    return 0;
}