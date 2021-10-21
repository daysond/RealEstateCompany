//
//  Property.h
//  Real Estate Company
//
//  Created by Dayson Dong on 2021-10-21.
//

#ifndef Property_h
#define Property_h

#include "RealEstateCommon.h"

//MARK: -DECLARATIONS FOR APARTMENT

typedef struct{
    
    RealEstateCommon common;
    double monthlyCondoFees;
    
    
} Apartment;

void CalculateApartmentMonthlyEarnings(Apartment * apt);



//MARK: -DECLARATIONS FOR TOWNHOUSE

typedef struct{
    
    RealEstateCommon common;
    
    double monthlyUtilities;
    double monthlyCondoFees;
    double monthlyPropertyTax;
    
} Townhouse;

void CalculateTownhouseMonthlyEarnings(Townhouse * th);



//MARK: -DECLARATIONS FOR SEMIDETACHEDHOUSE

typedef struct{
    
    RealEstateCommon common;
    
    double monthlyUtilities;
    double monthlyPropertyTax;
    
} SemiDetachedHouse;

void CalculateSemiDetachedMonthlyEarnings(SemiDetachedHouse * semi);


#endif /* Property_h */
