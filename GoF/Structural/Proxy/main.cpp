#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VeryLargeBox {

    vector <string> Content;
    int xpos, ypos;

public:
    VeryLargeBox(int x, int y) {

        cout << "Now the main class is instantiated." << endl;
        Content.push_back("VeryLargeObject1");
        Content.push_back("VeryLargeObject2");
        Content.push_back("VeryLargeObject3");
        xpos = x;
        ypos = y;
    }

    vector <string> getContent() {

        cout << "Showing content." << endl;
        return Content;

    }

    void replaceBox(int x, int y) {


        xpos = x;
        ypos = y;
        cout << "Now the coordinates of box are: " << xpos << ", " << ypos << endl;

    }

};

class BoxProxy {
    int xpos, ypos;
    VeryLargeBox* BoxPointer;

public:
    BoxProxy() {
        xpos = 0;
        ypos = 0;
        BoxPointer = 0;
         cout << "Now the proxy class is instantiated." << endl;
    }

    BoxProxy(int x, int y) {

        xpos = x;
        ypos = y;
        BoxPointer = 0;
         cout << "Now the proxy class is instantiated." << endl;
    }

    ~BoxProxy() {
        delete BoxPointer;
    }

    vector <string> getContent() {
        if(!BoxPointer) BoxPointer = new VeryLargeBox(xpos, ypos);
        return BoxPointer->getContent();
    }

    void replaceBox(int x, int y) {

        cout << "Changing the coordinates in proxy class." << endl;

        xpos = x;
        ypos = y;
        if(BoxPointer) BoxPointer->replaceBox(x,y);
    }

};

int main()
{
    BoxProxy BoxObject;

    BoxObject.replaceBox(3,4);
    BoxObject.getContent();
    BoxObject.replaceBox(2,5);

    return 0;
}

