#include <list>
#include <string>
#include <iostream>
using namespace std;

class Zwierze {
private:
    string gatunek;
public:
    Zwierze(string gatunek) : gatunek(gatunek) {}
    string getGatunek() { return gatunek; }
    void setGatunek(string gatunek) { this->gatunek = gatunek; }
};

class Ssak : public Zwierze {
public:
    Ssak(string gatunek) : Zwierze(gatunek) {}
};

class Ptak : public Zwierze {
public:
    Ptak(string gatunek) : Zwierze(gatunek) {}
};

template <typename T>
class Wybieg {
private:
    list<T*> zwierzeta;
public:
    void dodajZwierze(T* zwierze) { zwierzeta.push_back(zwierze); }
    void usunZwierze(T* zwierze) { zwierzeta.remove(zwierze); }
    int liczbaZwierzat() { return zwierzeta.size(); }
    void wyswietlZwierzeta(){
        for(auto zwierze: zwierzeta){
            cout<<zwierze->getGatunek()<<endl;
        }
    }
};
