//
//  RealEstateCompany.h
//  Real Estate Company
//
//  Created by Dayson Dong on 2021-10-21.
//

#ifndef RealEstateCompany_h
#define RealEstateCompany_h

#define NUM_PROPERTY 5
#include "Property.h"


typedef struct {
    
    char name[MAX_STR];
    char address[MAX_STR];
   
    Apartment apartments[NUM_PROPERTY];
    Townhouse townhouses[NUM_PROPERTY];
    SemiDetachedHouse semiDetached[NUM_PROPERTY];
    
    
} RealEstateCompany;


void SumMonthlyEarnings(RealEstateCompany *company);
void SumReturnOnInvestment(RealEstateCompany *company);
void SumCurrentValue(RealEstateCompany *company);
void SumCapitalGains(RealEstateCompany *company);



#endif /* RealEstateCompany_h */
