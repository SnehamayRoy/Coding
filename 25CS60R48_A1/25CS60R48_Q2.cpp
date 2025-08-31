#include <iostream>
using namespace std;

struct Node
{
    int subset[20]; // max subset size n <= 20
    int size;
};

struct Queue
{
    Node data[10000]; // adjust size for large n
    int front, rear;

    Queue()
    {
        front = 0;
        rear = 0;
    }

    void enqueue(Node x)
    {
        data[rear++] = x;
    }

    Node dequeue()
    {
        return data[front++];
    }

    bool isEmpty()
    {
        return front == rear;
    }
};

void generateSubsets(int n, int k)
{
    Queue Q;
    Node empty;
    empty.size = 0;
    Q.enqueue(empty);

    while (!Q.isEmpty())
    {
        Node S = Q.dequeue();
        int l = S.size;
        int m = (l == 0 ? 0 : S.subset[l - 1]); // max element

        if (l == k)
        {
            for (int i = 0; i < l; i++)
            {
                cout << S.subset[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            for (int i = m + 1; i <= n; i++)
            {
                Node newSet;
                newSet.size = l + 1;
                for (int j = 0; j < l; j++)
                    newSet.subset[j] = S.subset[j];
                newSet.subset[l] = i;
                Q.enqueue(newSet);
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    generateSubsets(n, k);
    return 0;
}
