#include <bubble/bubble_sort.hpp>

void bubbleSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator it1 = begin;
    std::vector<int>::iterator it2 = it1;
    int size = end-begin;
    if (size > 1)
    {
        int tmp;

        while(it1!=end)
        {
            it2 = it1+1;
            while(it2!=end)
            {
                if (*(it2) > *(it1))
                {
                    tmp = *(it2);
                    *(it2) = *(it1);
                    *(it1)= tmp;
                }
                it2++;

            }
            it1++;
        }

    }

}