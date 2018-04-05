#include "MyClass.h"

Procesator::~Procesator()
{
    //chiar daca este virtual pur, trebuie implementat fiindca va fi apelat dupa destructorul clasei derivate
}

void ListaParagrafe::Add (string sir)
{
    v.push_back (sir);
}

vector<string>::iterator ListaParagrafe::begin()
{
    return v.begin();
}

vector<string>::iterator ListaParagrafe::end()
{
    return v.end();
}

void ProcesatorNumaraCuvinte::Proceseaza (string sir)
{
    char* c_sir = new char [sir.length() + 1];
    strcpy (c_sir, sir.c_str());
    char* p = strtok (c_sir, ".?!, ");
    while (p != nullptr)
    {
        string aux = p;
        ++m[aux];
        p = strtok (nullptr, ".?!, ");
    }
    delete[] c_sir;
}

void ProcesatorNumaraCuvinte::Print()
{
    for (map <string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << ", ";
    }
    cout << "\n";
}

ProcesatorNumaraCuvinte::~ProcesatorNumaraCuvinte()
{
    //nu este nevoie de nicio eliberare de memorie, aceasta a fost eliberata pe parcurs
}

void ProcesatorNumaraPropozitii::Proceseaza (string sir)
{
    char* c_sir = new char [sir.length() + 1];
    strcpy (c_sir, sir.c_str());
    char *p = strtok (c_sir, ".?!");
    while (p != nullptr)
    {
        ++NumarPropozitii;
        p = strtok (nullptr, ".!?");
    }
    delete[] c_sir;
}

void ProcesatorNumaraPropozitii::Print()
{
    cout << NumarPropozitii << " propozitii" << "\n";
}

ProcesatorNumaraPropozitii::~ProcesatorNumaraPropozitii()
{
    //nu este nevoie de nicio eliberare de memorie, aceasta a fost eliberata pe parcurs
}
