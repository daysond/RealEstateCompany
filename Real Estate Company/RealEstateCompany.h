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


typedef struct {
    
    char name[MAX_STR];
    char address[MAX_STR];
    
    double sumOfMonthlyEarnings[NUM_PROPERTY_TYPES]; // monthly earning in array for different property types, 0: apartment, 1: townhouse 2: semi-detached house
    double sumOfROI[NUM_PROPERTY_TYPES]; // ROI in array for different property types, 0: apartment, 1: townhouse 2: semi-detached house
    double sumOfCurrentValue[NUM_PROPERTY_TYPES]; // Current value in array for different property types, 0: apartment, 1: townhouse 2: semi-detached house
    double sumOfCapitalGains[NUM_PROPERTY_TYPES]; // Capital gains in array for different property types, 0: apartment, 1: townhouse 2: semi-detached house
    
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
void analyzePropertiesForCompany(RealEstateCompany *company);

//Funtion that excutes the sum functions, sum up the earnings, ROI, current value and captital gains for each TYPE of properties that the company owns
void CalculatePerformance(RealEstateCompany *company);

//Funtion that prints out a brief performance report for EACH TYPE of the properties
void ShowPerformance(RealEstateCompany company);


#endif /* RealEstateCompany_h */
