//
//  Property.h - declarations for different property types: Apartment, Townhouse, SemiDetachedHouse
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#ifndef Property_h
#define Property_h

#include "PropertyCommon.h"

// MARK: - Types of properties: Apartment: apt, Townhouse: th, Semi-Detached House: semi

enum propertyTypes {apt = 0,
                    th = 1,
                    semi = 2 };

//MARK: -DECLARATIONS FOR APARTMENT

typedef struct{
    //Common: sturct of charateristics shared by differernt types of properties
    PropertyCommon common;
    
    double monthlyCondoFees;
    
} Apartment;

void CalculateApartmentMonthlyEarnings(Apartment *apt);



//MARK: -DECLARATIONS FOR TOWNHOUSE

typedef struct{
    //Common: sturct of charateristics shared by differernt types of properties
    PropertyCommon common;
    
    double monthlyUtilities;
    double monthlyCondoFees;
    double monthlyPropertyTax;
    
} Townhouse;

void CalculateTownhouseMonthlyEarnings(Townhouse *th);



//MARK: -DECLARATIONS FOR SEMIDETACHED HOUSE

typedef struct{
    //Common: sturct of charateristics shared by differernt types of properties
    PropertyCommon common;
    
    double monthlyUtilities;
    double monthlyPropertyTax;
    
} SemiDetachedHouse;

void CalculateSemiDetachedMonthlyEarnings(SemiDetachedHouse *semi);


#endif /* Property_h */
