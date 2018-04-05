#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ListaParagrafe
{
    vector <string> v;
  public:
    void Add (string);
    vector<string>::iterator begin();
    vector<string>::iterator end();
};

class Procesator
{
  public:
    virtual void Proceseaza (string) = 0;
    virtual void Print() = 0;
    virtual ~Procesator() = 0;
};

class ProcesatorNumaraCuvinte : public Procesator
{
    map <string, int> m;
  public:
    void Proceseaza (string);
    void Print();
    ~ProcesatorNumaraCuvinte();

};

class ProcesatorNumaraPropozitii : public Procesator
{
    unsigned int NumarPropozitii = 0;
  public:
    void Proceseaza (string);
    void Print();
    ~ProcesatorNumaraPropozitii();
};
