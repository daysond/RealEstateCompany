//
//  RealEstateCommon.h
//  Real Estate Company
//
//  Created by Dayson Dong on 2021-10-21.
//

#ifndef RealEstateCommon_h
#define RealEstateCommon_h

#define MAX_STR 255
#define INTEREST_RATE 0.05

#include <stdio.h>

typedef struct{
    
    char address[MAX_STR];
    int numOfRooms;
    int numOfBathrooms;
    double purchasePrice;
    double monthlyRent;
    double monthlyEarning;
    double annualReturn;
    double currentValue;
    double captialGains;
    
} RealEstateCommon;

//return on investment (percent) = 100 x 12 x monthly earnings / purchase price.
void CalculateROI(RealEstateCommon *common);

//current value = 12 x monthly earnings / interest rate. The interest rate is hard-coded to 5% (or 0.05).
void CalculatecurrentValue(RealEstateCommon *common);

//capital gains = current value - purchase price.
void CalculateCapitalGains(RealEstateCommon *common);

#endif /* RealEstateCommon */
