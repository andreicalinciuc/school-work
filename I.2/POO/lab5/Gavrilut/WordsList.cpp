#include "WordsList.h"

bool cmp (const char* a, const char* b)
{
    unsigned int sizeA = strlen (a);
    unsigned int sizeB = strlen (b);
    unsigned int n = std::min (sizeA, sizeB);
    for (unsigned int i = 0; i < n; ++i)
    {
        char auxA = a[i]; if (auxA >= 'A' && auxA <= 'Z') auxA = auxA - 'A' + 'a';
        char auxB = b[i]; if (auxB >= 'A' && auxB <= 'Z') auxB = auxB - 'A' + 'a';
        if (auxA < auxB) return 0;
        if (auxA > auxB) return 1;
    }
    return sizeA > sizeB;
}

template <class T>
WordsList<T>::WordsList()
{
    const unsigned int BufferSize = 100;
    char *s = new char[BufferSize]; 
    FILE *file = fopen ("data.in", "r");
    while (fgets (s, BufferSize, file) != NULL)
    {
        unsigned int n = strlen(s);
        if (s[n-1] == '\n') s[n-1] = 0;
        v.push_back (s);
        s = new char[BufferSize];
    }
    fclose (file);
}

template <class T>
void WordsList <T>::PrintWords()
{
    for (typename std::vector <T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        printf ("%s\n", *it);
    }
}


template <class T>
T WordsList <T>::LargestWord()
{
    unsigned int maxim = 0;
    unsigned int BufferSize = 100;
    char* result = new char[BufferSize];
    for (typename std::vector <T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        unsigned int n = strlen (*it);
        if (n > maxim)
        {
            maxim = n;
            strcpy (result, *it);
        }
    }
    return result;
}

template <class T>
std::deque <T> WordsList <T>::NotStartingWithVowels()
{
    std::deque <T> result;
    for (typename std::vector <T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (strchr ("aeiouAEIOU", (*it)[0]) == 0)
        {
            result.push_back (*it);
        }
    }
    return result;
}

template <class T>
void WordsList <T>::DeleteMoreThan (unsigned int value)
{
    for (typename std::vector <T>::iterator it = v.begin(); it != v.end(); )
    {
        if (strlen (*it) > value)
        {
            it = v.erase (it);
        }
        else
        {
            ++it;
        }
    }
}

template <class T>
std::priority_queue <T, std::vector <T>, decltype (&cmp)> WordsList <T>::SortedWords()
{
    std::priority_queue <T, std::vector <T>, decltype (&cmp)> result (cmp);
    for (typename std::vector <T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        result.push (*it);
    }
    return result;
}

template <class T>
std::vector <T> WordsList <T>::ReversedOrder()
{
    std::vector <T> result;
    std::stack <T> aux;
    for (typename std::vector <T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        aux.push (*it);
    }
    while (!aux.empty())
    {
        result.push_back (aux.top());
        aux.pop();
    }
    return result;
}

template class WordsList <const char*>;
