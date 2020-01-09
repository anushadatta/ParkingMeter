// definitions of delcared functions in parking.h

#include"parking.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
//#include <cmath.h>    use if round() floor() not included in <math.h>

using namespace std;

double calculate_fee(double parking_hours)
{
    double fee= 0; 
    
    //to account for time slots other than multiples of 30 or 60 minutes
    double rounded_parking_hours;
    
    // first 30 minutes of parking are free of cost
    if(parking_hours<=0.5)
        return fee;
    
    // $1 = 30 minutes, for time range (0.5 hours, 4 hours]
    else if(parking_hours<=4.0)
    {
        rounded_parking_hours = round(parking_hours);
        fee= rounded_parking_hours/0.5;

        if(rounded_parking_hours < parking_hours)
            return fee;
        else
            return fee - 1;
    }

    // $1.5 = 60 minutes, for time range (4 hours, inf hours)
    else
    {
        rounded_parking_hours = round(parking_hours);

        fee= (rounded_parking_hours-4) * 1.5; 

        if(rounded_parking_hours < parking_hours)
            return fee + 7 + 1.5;
        else
            return fee + 7;
    }
    
}

 vector<int> calculate_parking_time(double cash)
 {
    vector<int> time= {0,0,0,0};

    // first 30 minutes of parking are free of cost
    if(cash <= 0)
    {
        time[0]= 30;
    }
    
    // $1 = 30 minutes, for cash range ($0,$8.5)
    else if(cash < 8.5)
    {   
        // edge case: 4 hours of parking time provided for cash range of [$7, $8.5)
        if(cash >= 8)
            cash = cash - 1;
        
        int minutes = floor(cash)*30 + 30;

        time[1] = floor(minutes/60);
        minutes = minutes - time[1]*60;
        time[0]= minutes;
    }

    // $1.5 = 60 minutes, for cash range [$8.5, $inf)
    else
    {
        // calculating hours
        // initial $7 for 4 hours under different pricing scheme 
        double hours = ((cash-7) / 1.5) + 4; 

        // time greater than or equal to one year
        if(hours >= 8760)
        {
            // finding number of years
            time[3] = int(floor(hours/8760.0));
            hours = hours - (time[3]*8760);

        }

        // time greater than or equal to one day 
        if(hours >= 24)
        {
            // finding number of days
            time[2] = int(floor(hours/24.0));
            hours = hours - (time[2]*24);
        }

        // finding number of hours
        time[1] = floor(hours);   
        
    }
    
    return time;

 }

 vector<int> convert_to_coins(double return_amount)
 {  
    vector<int> coins= {0,0,0,0,0,0,0,0};

    // calculating amount in cents
    // round() prevents calculation inaccuracies from internal binary no. representation
    double amount_in_cents = round(return_amount * 100.0);

    // 2 euro coins
    coins[0] = floor(amount_in_cents/200);
    amount_in_cents= amount_in_cents - (coins[0]*200);

    // 1 euro coins
    coins[1] = floor(amount_in_cents/100);
    amount_in_cents= amount_in_cents - (coins[1]*100);

    // 50 cent coins
    coins[2] = floor(amount_in_cents/50);
    amount_in_cents= amount_in_cents - (coins[2]*50);

    // 20 cent coins
    coins[3] = floor(amount_in_cents/20);
    amount_in_cents= amount_in_cents - (coins[3]*20);

    // 10 cent coins
    coins[4] = floor(amount_in_cents/10);
    amount_in_cents= amount_in_cents - (coins[4]*10);

    // 5 cent coins
    coins[5] = floor(amount_in_cents/5);
    amount_in_cents= amount_in_cents - (coins[5]*5);

    // 2 cent coins
    coins[6] = floor(amount_in_cents/2);
    amount_in_cents= amount_in_cents - (coins[6]*2);

    // 1 cent coins
    coins[7] = amount_in_cents;

    return coins;
 }

 vector<int> bill_customer(double parking_hours, double amount)
 {  
    vector<int> bill;
    double change;

    // calculate money required
    double fee = calculate_fee(parking_hours);

    // calculate difference between provided and required amounts of money
    change = amount - fee;

    bill = convert_to_coins(change);

    return bill;
 }



