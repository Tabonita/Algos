#include <heapsort/heapsort.hpp>

void exchange (int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void sink (std::vector <int> & array, int k, int n)
{
    int son;
    while (1)
    {
        int leftChildIndex = 2 * k + 1;
        int rightChildIndex = 2 * k + 2;
        if (leftChildIndex > n)
        {
            break;
        }
        else if (rightChildIndex <= n)
        {
            if (array.at(leftChildIndex) < array.at(rightChildIndex))
            {
                son = leftChildIndex;
            }
            else
            {
                son = rightChildIndex;
            }
        }
        else
        {
            son = leftChildIndex;
        }
        if (array.at(k) > array.at(son))
        {
            exchange(array.at(k), array.at(son));
            k = son;

        }
        else
        {
            break;
        }
    }

}

void heap_sort(std::vector <int> & array)
{
    if (array.size() > 1)
    {
        int n = array.size();
        for (int i = n/2; i >= 0; i--)
        {
            sink (array,i,n);
        } 
        for (int k = n; k > 0; k--)
        {
            exchange(array.at(0),array.at(k));
            sink(array,0, k - 1);
        }

    }

}