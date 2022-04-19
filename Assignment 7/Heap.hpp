/*
bool comp(T a, T b) -> (a > b) -----------> Min Heap
bool comp(T a, T b) -> (a < b) -----------> Max Heap
*/

template <class T, bool comp(T, T)>
class Heap
{
public:
    T *heap;
    int size = 0, filled = 0;
    Heap(int n)
    {
        heap = new T[n];
        size = n;
    }
    void insert(T n)
    {
        filled = filled + 1;
        heap[filled - 1] = n;
        int i = filled - 1;
        while (i >= 0)
        {
            int parent = (i - 1) / 2;
            if (comp(heap[parent], heap[i]))
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void heapify(int n, int i)
    {
        int parent = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n and comp(heap[parent], heap[l]))
        {
            parent = l;
        }

        if (r < n and comp(heap[parent], heap[r]))
        {
            parent = r;
        }

        if (parent != i)
        {
            swap(heap[i], heap[parent]);
            heapify(n, parent);
        }
    }
    T top()
    {
        return heap[0];
    }
    void deleteRoot()
    {
        T last = heap[filled - 1];
        heap[0] = last;
        filled = filled - 1;
        heapify(filled, 0);
    }
    ~Heap()
    {
        delete heap;
    }
};
