//
//  Property.c - function definitions for differernt types of properties: Apartment, Townhouse, SemiDetachedHouse
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#include "Property.h"

// Calculate the monthly earnings of an apartment
void CalculateApartmentMonthlyEarnings(Apartment * apt) {
    
    //monthly earnings = monthly rent - monthly condo fees.
    apt->common.monthlyEarning = apt->common.monthlyRent - apt->monthlyCondoFees;
    
}

// Calculate the monthly earnings of a townhouse
void CalculateTownhouseMonthlyEarnings(Townhouse * th) {
    
    //monthly earnings = monthly rent - monthly utilities - monthly condo fees - monthly property tax.
    th->common.monthlyEarning = th->common.monthlyRent - th->monthlyUtilities - th->monthlyCondoFees - th->monthlyPropertyTax;
    
    
}

// Calculate the monthly earnings of a semi-detached house
void CalculateSemiDetachedMonthlyEarnings(SemiDetachedHouse * semi){
    
    //monthly earnings = monthly rent - monthly utilities - monthly property tax.
    semi->common.monthlyEarning = semi->common.monthlyRent - semi->monthlyUtilities - semi->monthlyPropertyTax;
    
    
}
