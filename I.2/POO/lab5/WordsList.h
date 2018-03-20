#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

bool cmp (const char* a, const char* b);

template <class T>
class WordsList
{
  private:
      std::vector <T> v;
  public:
    WordsList();
    void PrintWords();
    T LargestWord();
    int ContainAtLeast4Vowels();
    std::deque <T> NotStartingWithVowels();
    void DeleteMoreThan (unsigned int value);
    std::priority_queue <T, std::vector <T>, decltype (&cmp)> SortedWords();
    std::vector <T> ReversedOrder();
};
