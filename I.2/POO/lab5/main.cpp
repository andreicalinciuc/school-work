#include "WordsList.h"

using namespace std;

int main()
{
    WordsList <const char*> a;
    
    printf ("1:\n");
    a.PrintWords();
    

    printf ("\n\n2:\n");
    printf ("%s\n", a.LargestWord());
    

    printf ("\n\n3:\n");
    deque <const char*> deq = a.NotStartingWithVowels();
    while (!deq.empty())
    {
        printf ("%s\n", deq.front());
        deq.pop_front();
    }
    

    printf ("\n\n4:\n");
    a.DeleteMoreThan (5);
    a.PrintWords();


    printf ("\n\n5:\n");
    priority_queue <const char*, vector <const char*>, decltype (&cmp)> pq  = a.SortedWords();
    while (!pq.empty())
    {
        printf ("%s\n", pq.top());
        pq.pop();
    }


    printf ("\n\n6:\n");
    vector <const char*> vect = a.ReversedOrder();
    for (vector <const char*>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
        printf ("%s\n", *it);
    }
}
