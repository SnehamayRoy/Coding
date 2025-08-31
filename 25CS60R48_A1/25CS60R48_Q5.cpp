#include <iostream>
using namespace std;

void sortColors(int nums[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int nums[1000]; // adjust size if needed
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sortColors(nums, n);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << "\n";

    return 0;
}
