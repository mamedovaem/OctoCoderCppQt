#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

 class Confectionery {

public:
    Confectionery::Confectionery() { }

 //   virtual Confectionery* clone()=0;
   // virtual void initialize(string, string)=0;

};

class CandyBar: public Confectionery {
    string glaze;
    string filling;

public:
    CandyBar() {}
    CandyBar(const CandyBar& obj) {
    }
    ~CandyBar() {}

    CandyBar clone() {

        return *this;

    }
    void initialize(string gl, string fl)
    {
    glaze = gl;
    filling = fl;
    }

};

class HardCandy: public Confectionery {

    string flavour;

public:

    HardCandy() {}
    HardCandy(const HardCandy& obj) {
    }

    HardCandy clone()
    {
        return *this;
    }

    void initialize(string fl) {

        flavour = fl;
    }
};

class PrototypeManager {

public:
     map <string, CandyBar> BarPrototype;
     map <string, HardCandy> CandyPrototype;

    PrototypeManager() {

  //      BarPrototype = new map <string, CandyBar>;
  //      CandyPrototype = new map <string, HardCandy>;
    }

    void addPrototype(string name, CandyBar obj) {

        BarPrototype[name] = obj;
    }

    void addPrototype(string name, HardCandy obj) {

        CandyPrototype[name] = obj;
    }



    void deletePrototype(string name) {
         map <string, CandyBar>::iterator it1;
       map <string, HardCandy>::iterator it2;

        for(it1=BarPrototype.begin(); it1!=BarPrototype.end(); it1++)
            if((*it1).first==name) {
                BarPrototype.erase(it1);
                break;
            }
        for(it2=CandyPrototype.begin(); it2!=CandyPrototype.end(); it2++)
            if((*it2).first==name) {
                CandyPrototype.erase(it2);
                break;
            }
    }

    void getPrototypesList() {

       map <string, CandyBar>::iterator it1;
       map <string, HardCandy>::iterator it2;

       for(it1=BarPrototype.begin(); it1!=BarPrototype.end(); it1++)
           cout << (*it1).first <<endl;
       for(it2=CandyPrototype.begin(); it2!=CandyPrototype.end(); it2++)
           cout << (*it2).first <<endl;

    }

 };

int main()
{
    PrototypeManager mngr;

    CandyBar b1, b2, b3;
    HardCandy c1, c2, c3;

    b1.initialize("chocolate", "strawberry");
    b2.initialize("green tea", "green tea");
    b3.initialize("chocolate", "truffle");

    c1.initialize("coffee");
    c2.initialize("cherry");
    c3.initialize("mint");

    mngr.addPrototype("StrawberryBar", b1);
    mngr.addPrototype("GreenTeaBar", b2);
    mngr.addPrototype("TruffleBar", b3);
    mngr.addPrototype("CoffeeCandy", c1);
    mngr.addPrototype("CherryCandy", c2);
    mngr.addPrototype("MintCandy", c3);

    mngr.getPrototypesList();

    vector <CandyBar> CandyBarBox(30);
    vector <HardCandy> HardCandyBox(30);

    int i = 0;

    for(; i<10; i++) {
        CandyBarBox[i]=mngr.BarPrototype["StrawberryBar"].clone();
        HardCandyBox[i]=mngr.CandyPrototype["CoffeeCandy"].clone();
    }
    for(; i<20; i++) {
        CandyBarBox[i]=mngr.BarPrototype["GreenTeaBar"].clone();
        HardCandyBox[i]=mngr.CandyPrototype["CherryCandy"].clone();
    }
    for(; i<30; i++) {
        CandyBarBox[i]=mngr.BarPrototype["TruffleBar"].clone();
        HardCandyBox[i]=mngr.CandyPrototype["MintCandy"].clone();
    }

    char c;
    cin >> c;

    return 0;
}


