/*
Convertitore Euro Dollaro
Autore: Giorgio Battaglia
Creato il: 27/01/2020
Versione: 0.0.1
*/
#include <iostream>

double CONVAL = 1.1;
double value = 0;
bool conversion = false;

using namespace std;

bool convert(double value) {
    if(value<=0) {
        cout << "Attenzione! Il valore inserito e' errato...";
        cout << "Il valore inserito e': " << value << " euro" << endl;
        return false;
    } else {
        cout << "Il corrispettivo in dollari e': " << value*CONVAL << "$" << endl;
        return true;
    }
    return false;
}

int main() {
    while(conversion == false){
        cout << "Inserire il valore in euro da convertire: ";
        cin >> value;

        conversion = convert(value);
    }
    return 0;
}