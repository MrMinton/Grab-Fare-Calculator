#include <iostream>
#include <cctype>
using namespace std;

bool cartype(const string& ride, double &base, double &perKm){
	string cartype[] = {"GRABCAR", "GRABBIKE", "GRABPREMIUM"};
	double baseFare[] = {3.0, 2.0, 5.0};
	double perKmFare[] = {1.5, 1.0, 2.0};

	int n = 3;

	for (int i =0 ; i < n; i++){
		if (ride == cartype[i]){
			base = baseFare[i];
			perKm = perKmFare[i];
			return true;
		}
	}
	cout<< "Please enter a valid choice!"<<endl;
	return false;
	
}

int main(){

	string ride;
	double base, perKm;


    cout << "======================================" << endl;
    cout << "    Welcome to Grab Fare Calculator" << endl;
    cout << "======================================" << endl;
    cout << "Available rides: GRABCAR | GRABBIKE | GRABPREMIUM" << endl;
    cout << "--------------------------------------" << endl;
	
	while (true) {
		cout << "Enter ride type (GRABCAR / GRABBIKE / GRABPREMIUM): ";
        cin >> ride;

		for (int i = 0 ; i < ride.length(); i++){
			ride[i] = toupper(ride[i]);
		};

		if (cartype(ride, base, perKm)){
			break;
		}
    }

	cartype(ride,base,perKm);

    cout << "\n=========== Fare Details =============" << endl;
    cout << "Car type    : " << ride << endl;
    cout << "Base fare   : RM " << base << endl;
    cout << "Per km rate : RM " << perKm << endl;
    cout << "--------------------------------------" << endl;
    cout << "Example total (base × per km) : RM" << base * perKm << endl;
    cout << "======================================" << endl;

	return 0;
};