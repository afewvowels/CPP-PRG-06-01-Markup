//
//  main.cpp
//  PRG-6-1-Markup
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//
//  Write a program that asks the user to enter an item's wholesale cost and its markup
//  percentage. It should then display the item's retail price. For example:
//  If an item's wholesale cost is 5.00 and its markup percentage is 100 percentage, then the
//  item's retail price is 10.00.
//  If an item's wholesale cost is 5.00 and its markup percentage is 50 percent, then the
//  item's retail price is 7.50.
//  The program should have a function named calculateRetail that receives the
//  wholesale cost and the markup percentage as arguments and returns the retail price
//  of the item.
//
//  Input validation: Do not accept negative values for either the wholesale cost of the item
//  or the markup percentage.


#include <iostream>
#include <iomanip>

using namespace std;

float calculateRetail(float, float);
float returnDeicmalPercentage(float);

int main()
{
    float fltItemWholesaleCost,
          fltItemMarkupPercentage,
          fltItemTotalCost;
    
    // Configure decimal precision for dollar output
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "Please enter the item's wholesale cost:\n";
    cin >> fltItemWholesaleCost;
    
    while(!cin || fltItemWholesaleCost <= 0.0f || fltItemWholesaleCost > 100.0f)
    {
        cout << "Please enter an item wholesale cost\n"
        << "greater than $0.00 and less than $100.00:\n";
        cin.clear();
        cin.ignore();
        cin >> fltItemWholesaleCost;
    }
    
    cout << "Please enter the item's markup as a percentage from 0%-100%:\n";
    cin >> fltItemMarkupPercentage;
    while(!cin || fltItemMarkupPercentage <= 0.0f || fltItemMarkupPercentage >= 1000.0f)
    {
        cout << "Please enter a markup percentage between\n"
             << "0% and 1000%:\n";
        cin.clear();
        cin.ignore();
        cin >> fltItemMarkupPercentage;
    }
    
    fltItemTotalCost = calculateRetail(fltItemWholesaleCost, fltItemMarkupPercentage);
    
    cout << "With an item cost of $" << fltItemWholesaleCost << endl
         << "and a markup percentage of " << fltItemMarkupPercentage << "%\n"
         << "the retail price is $" << fltItemTotalCost;
    
    return 0;
}
/*
 This function takes the item cost and markup percentage then passes
 the markup percentage to returnDemicalPercentage() to convert
 the whole number percentage to a decimal for use with multiplication.
 The function then calculates the amount of markup with the decimal
 percentage and the input fltCost. Then it adds the markup to
 fltCost to determine the item's total cost, then returns the item's
 total cost to the main function
 */
float calculateRetail(float fltCost, float fltMarkup)
{
    float fltTotalCost,
    fltMarkupAmount,
    fltPercentageDecimal;
    
    fltPercentageDecimal = returnDeicmalPercentage(fltMarkup);
    
    fltMarkupAmount = fltPercentageDecimal * fltCost;
    
    fltTotalCost = fltMarkupAmount + fltCost;
    
    return fltTotalCost;
}
/*
 This function takes a whole number percentage and returns
 a decimal value by dividing the input by 100 and returning
 the new value.
 */
float returnDeicmalPercentage(float fltPercentWhole)
{
    float fltPercentDeicmal;
    
    fltPercentDeicmal = fltPercentWhole / 100.0f;
    
    return fltPercentDeicmal;
}

