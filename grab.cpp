#include <iostream>
#include <cctype>
#include <iomanip>
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



double cashback(const string &member ,const double &total_fare ){
    string member_id []= {"NONE","SILVER","GOLD","PLATINUM"};
    double cashbackRate[]={0,0.02,0.05,0.08};
    int n =4;

  for(int i =0 ; i<n ; i++){
    if(member == member_id[i]){
        return total_fare * cashbackRate[i];
    }

  }
 throw runtime_error("Try again");


}

int main(){

	string ride, member;
	double base, perKm,total_fare;



    cout << "======================================" << endl;
    cout << "    Welcome to Grab Fare Calculator" << endl;
    cout << "======================================" << endl;
    cout << "Available rides: GRABCAR | GRABBIKE | GRABPREMIUM" << endl;
    cout << "=================================================" << endl;
    cout << "Available member: NONE | SILVER | GOLD | PLATINUM" << endl;
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

    cout << "Enter membership tier (NONE / SILVER / GOLD / PLATINUM): ";
    cin >> member;

    for (int i = 0; i < member.length(); i++) {
        member[i] = toupper(member[i]);
    }

try{
    total_fare = base *perKm;
	double cashbackAmount = cashback(member , total_fare);



    cout << "\n=========== Fare Details =============" << endl;
    cout << "Car type    : " << ride << endl;
    cout << "Base fare   : RM " <<fixed<<setprecision(2)<< base << endl;
    cout << "Per km rate : RM " <<fixed<< perKm <<setprecision(2)<< endl;
    cout<<  "Membership:"<<member<<endl;
    cout<<  "Cashback : RM"<<cashbackAmount<<fixed<<setprecision(2)<<endl;
    cout<<  "Final Cost: RM"<<total_fare - cashbackAmount<<fixed<<setprecision(2)<<endl;
    cout << "--------------------------------------" << endl;
    cout << "Example total (base × per km) : RM" << base * perKm <<setprecision(2)<< endl;
    cout << "======================================" << endl;

        }catch(const exception &e){
        cout << "Error: " <<e.what()<<endl;
        cout << "Please enter a valid membership tier next time." << endl;
    }

	return 0;
}
