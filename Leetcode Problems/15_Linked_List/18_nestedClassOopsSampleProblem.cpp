

#include <iostream>
using namespace std;


//___________________________________________________________________________________________________________________________________________
/*
---1
Here we have seen some nested class (nested struct is also valid in c++) class inside class.

if we create nested class and the inner class is private then can we create its object and access its members from main funtion
Ans: ❌ NO — if a nested (inner) class is private, you cannot create its object or access its members from main().

*/

//___________________________________________________________________________________________________________________________________________


class Car
{

public:
    class Engine
    {
        public:
            int horsepower;

            Engine(int hp)
            {
                horsepower = hp;
            }

            void start()
            {
                cout<<"engine start with"<<horsepower<<" hp "<<endl;
            }
    };
    
    string brand;
    Engine engine;

    Car(string b, int hp) : brand(b), engine(hp) {} 
    void drive()
    {
        cout << brand << " is driving" << endl;
        engine.start();
    }

};

int main()
{
    Car myCar("Maruti", 800);
    myCar.drive();

    Car::Engine spareEngine(300);
    spareEngine.start();

}

//___________________________________________________________________________________________________________________________________________
/*
---2
We can create constructor of inner class but to set the value or pass the value to it we need to pass it through outer class's constructor
if we want to pass the value in inside class only and not in the main() function.

*/

//___________________________________________________________________________________________________________________________________________

#include <iostream>
using namespace std;

class Car {
public:
    class Engine {
    public:
        int horsepower;

        Engine(int hp) {
            horsepower = hp;
        }

        void start() {
            cout << "engine start with " << horsepower << " hp" << endl;
        }
    };

    string brand;
    Engine engine;   // ✅ only declaration 
    // Engine engine(20);   // This is wrong. If you have to do like this then you should pass value to constructor from main function 
    // after creating object there. Also If a data member has no default constructor, it MUST be initialized in the initializer list

    // ✅ Construct Engine here
    Car(string b, int hp) : brand(b), engine(hp) {}

    void drive() {
        engine.start();
    }
};

int main() {
    Car c("Tesla", 200);
    c.drive();

    Car::Engine engine2(20); // this is correct because passing from main function.
}

