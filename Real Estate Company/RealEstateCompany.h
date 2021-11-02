//
//  RealEstateCompany.h - declarations of real estate company
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#ifndef RealEstateCompany_h
#define RealEstateCompany_h

#define NUM_PROPERTY 5
#define NUM_PROPERTY_TYPES 3

#include "Property.h"
#include <string.h>

typedef struct {
    
    char name[MAX_STR];
    char address[MAX_STR];
    
    // Index for below arrays: 0: apartment, 1: townhouse 2: semi-detached house
    double sumOfMonthlyEarnings[NUM_PROPERTY_TYPES]; // List of monthly earning of different property types
    double sumOfROI[NUM_PROPERTY_TYPES]; // List of ROI of different property types
    double sumOfCurrentValue[NUM_PROPERTY_TYPES]; // List of current value of different property types
    double sumOfCapitalGains[NUM_PROPERTY_TYPES]; // List of capital gains of different property types
    
    Apartment apartments[NUM_PROPERTY]; // list of apartments that the company owns
    Townhouse townhouses[NUM_PROPERTY]; // list of townhouses that the company owns
    SemiDetachedHouse semiDetached[NUM_PROPERTY]; // list of Semi-detached houses that the company owns
    
    
} RealEstateCompany;

//Essential Functions: declarations may be deleted to keep these function for internal use only
void SumMonthlyEarnings(RealEstateCompany *company);
void SumReturnOnInvestment(RealEstateCompany *company);
void SumCurrentValue(RealEstateCompany *company);
void SumCapitalGains(RealEstateCompany *company);

//Fcuntion that calculates earnings, ROI, current value and captital gains for EACH and ALL of the properties that the company owns.
void AnalyzeProperties(RealEstateCompany *company);

//Funtion that excutes the sum functions, sum up the earnings, ROI, current value and captital gains for each TYPE of properties that the company owns
void CalculatePerformance(RealEstateCompany *company);

//Funtion that prints out a brief performance report for EACH TYPE of the properties
void ShowPerformance(const RealEstateCompany *company);


#endif /* RealEstateCompany_h */
