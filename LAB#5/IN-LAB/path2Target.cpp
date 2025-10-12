#include <iostream>
using namespace std;

void pointerMaze(int *arr, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int *p = arr;
    int index = 0;
    cout << "Path: ";

    while (true)
    {
        cout << index;

        if (index < 0 || index >= n)
        {
            cout << "\nExit reached successfully." << endl;
            break;
        }

        if (visited[index])
        {
            cout << " -> ...\nLoop detected." << endl;
            break;
        }

        visited[index] = true;

        int nextIndex = *(p + index);
        if (nextIndex < 0 || nextIndex >= n)
        {
            cout << " -> " << nextIndex << endl;
            cout << "Exit reached successfully." << endl;
            break;
        }

        cout << " -> " << nextIndex << " ";
        index = nextIndex;
    }

    delete[] visited;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> *(arr + i);

    pointerMaze(arr, n);

    delete[] arr;
    return 0;
}
