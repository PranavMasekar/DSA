#include <bits/stdc++.h>
using namespace std;

char SmallestLetter(char letters[], int size, char target)
{
    int low, mid, high;

    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (target < letters[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (low == size)
        return letters[0];
    else
        return letters[low];
}

int main()
{
    char letters[] = {'a', 'b', 't'};
    cout << SmallestLetter(letters, 3, 't') << endl;
    return 0;
}