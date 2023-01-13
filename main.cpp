//Zadanie 3
#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class Para {
private:
    T left;
    T right;

public:
    // Konstruktor parametryczny
    Para(T leftValue, T rightValue) : left(leftValue), right(rightValue) {}

    // Gettery
    T getLeft() { return left; }
    T getRight() { return right; }

    // Sety
    void setLeft(T value) { left = value; }
    void setRight(T value) { right = value; }

    // Metoda swap
    void swap() {
        T temp = left;
        left = right;
        right = temp;
    }

    // Metoda toString
    string toString() {
        if (is_same<T, string>::value) {
            stringstream ss;
            ss << "Left: " << left << ", Right: " << right;
            return ss.str();
        } else {
            stringstream ss;
            ss << "Left: " << left << ", Right: " << right;
            return ss.str();
        }
    }
    
	 // Metoda max
    T max() {
        return left > right ? left : right;
    }
};

int main() {
    // Przyk³ad dzia³ania dla par liczb ca³kowitych
    Para<int> intPair(1, 2);
    cout << intPair.toString() << endl; // Left: 1, Right: 2
    intPair.swap();
    cout << intPair.toString() << endl; // Left: 2, Right: 1
	cout << "Max: " << intPair.max() << endl; // max
	
    // Przyk³ad dzia³ania dla par liczb zmiennoprzecinkowych
    Para<double> doublePair(1.1, 2.2);
    cout << doublePair.toString() << endl; // Left: 1.1, Right: 2.2
    doublePair.swap();
    cout << doublePair.toString() << endl; // Left: 2.2, Right: 1.1
	cout <<  "Max: " << doublePair.max() << endl; // max

    // Przyk³ad dzia³ania dla pary tekstów
     Para<string> stringPair(string("hello"), string("world"));
    cout << "Left: " + stringPair.getLeft() + ", Right: " + stringPair.getRight() << endl;
    stringPair.swap();
    cout << "Left: " + stringPair.getLeft() + ", Right: " + stringPair.getRight() << endl;
    cout <<  "Max: " << stringPair.max() << endl; // max
    
	return 0;
}
