#include <iostream>
#include <string>

using namespace std;

class Girl;

class Memento {
    Memento(string clr1, string clr2, string clr3) {

        Eyelashes = clr1;
        Lips = clr2;
        Nails = clr3;
    }

private:
    friend class Girl;
    string Eyelashes;
    string Lips;
    string Nails;
};

class Girl {

public:
    Girl() {
        EyelashesColour = "none";
        LipsColour = "none";
        NailsColour = "none";

        SaveState = 0;
    }

  //  ~Girl() {
    //    delete SaveState;
    //}

    void ApplyMascara(string clr) {
        EyelashesColour = clr;
    }

    void ApplyLipStick(string clr) {
        LipsColour = clr;
    }

    void ApplyNailPolish(string clr) {
        NailsColour = clr;
    }

    void GetPresentState () {

        cout << "Girl's eyelashes' colour is " << EyelashesColour << endl;
         cout << "Girl's lips' colour is " << LipsColour << endl;
         cout << "Girl's nails' colour is " << NailsColour << endl << endl;

    }

    void CreateMemento() {

        SaveState = new Memento(EyelashesColour, LipsColour, NailsColour);

    }

    void GetStateFromMemento() {
        if(SaveState) {
        EyelashesColour = SaveState->Eyelashes;
        LipsColour = SaveState->Lips;
        NailsColour = SaveState->Nails;
      }
        else cout << "Cannot restore previous state." << endl;
    }

private:
    string EyelashesColour;
    string LipsColour;
    string NailsColour;

    Memento* SaveState;


};

int main()
{
    Girl Anna;

    Anna.ApplyLipStick("pink");
    Anna.ApplyMascara("black");
    Anna.ApplyNailPolish("yellow");
    Anna.GetPresentState();

    Anna.CreateMemento();

    Anna.ApplyMascara("brown");
    Anna.ApplyNailPolish("blue");
    Anna.GetPresentState();

    Anna.GetStateFromMemento();
    Anna.GetPresentState();

    return 0;
}

