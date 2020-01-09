#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include "parking.h"
#include "parking.cpp"

using namespace std;

int main(int argc, char** argv) {	
	//allocate vectors to store time and change (money)
	vector<int> time;
	vector<int> change;	
	if ( argc < 2 || argc > 6)
	   cout << "The number of input arguments has to be between one and five!" << endl;
	
	// Testing function calculate_fee()
	float hours = std::stof(argv[1]);
	cout<<"\nFor "<<hours<<" hour(s) of parking, the charge is: ";
	cout<<calculate_fee(hours)<<" Euro(s)"<<endl;
	
	// Testing function calculate_parkingtime()
	float cash =std::stof(argv[2]);
	cout<<"\nFor "<<cash<<" Euro(s) the parking time is: ";
    time = calculate_parking_time(cash);
	for (int i = 0; i < 4; i++) {
		cout << time[i];
		if(i == 0){
			cout<<"m ";
		}
		else if(i == 1){
			cout<<"h ";
		}
		else if(i == 2){
			cout<<"d ";
		}
		else{
			cout<<"y";
		}
	}
	cout<<endl;
	
	// Testing function convert_to_coins()
	cash =std::stof(argv[3]);
	cout<<"\nExchanging "<<cash<<" Euro(s) into coins: \n";
    change = convert_to_coins(cash);
	for (int i = 0; i < 8; i++) {
		cout << change[i];
		if(i == 0){
			cout<<"x2Euro ";
		}
		else if(i == 1){
			cout<<"x1Euro ";
		}
		else if(i == 2){
			cout<<"x50Cent ";
		}
		else if(i == 3){
			cout<<"x20Cent ";
		}
		else if(i == 4){
			cout<<"x10Cent ";
		}
		else if(i == 5){
			cout<<"x5Cent ";
		}
		else if(i == 6){
			cout<<"x2Cent ";
		}
		else if(i == 7){
			cout<<"x1Cent";
		}
	}
	cout<<endl;
	
	// Actual application based on function bill_customer()
	// The function bill_customer() calls calculate_fee() and convert_to_coins()
	hours=std::stof(argv[4]);
	cash =std::stof(argv[5]);
	cout<<"\nYou parked for "<<hours<<" hour(s) and paid "<<cash<<" Euro(s) your change/charge is: \n" ;
	change = bill_customer(hours,cash);
	for (int i = 0; i < 8; i++) {
		cout << change[i];
		if(i == 0){
			cout<<"x2Euro ";
		}
		else if(i == 1){
			cout<<"x1Euro ";
		}
		else if(i == 2){
			cout<<"x50Cent ";
		}
		else if(i == 3){
			cout<<"x20Cent ";
		}
		else if(i == 4){
			cout<<"x10Cent ";
		}
		else if(i == 5){
			cout<<"x5Cent ";
		}
		else if(i == 6){
			cout<<"x2Cent ";
		}
		else if(i == 7){
			cout<<"x1Cent";
		}
	}
	cout << endl;
	
	return 0;
}
