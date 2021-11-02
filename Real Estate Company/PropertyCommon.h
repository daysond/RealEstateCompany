//
//  PropertyCommon.h - declarations for PropertyCommon: common charateristics of different types of properties.
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#ifndef PropertyCommon_h
#define PropertyCommon_h

#define MAX_STR 255
//#define INTEREST_RATE 0.05

#include <stdio.h>

typedef struct{
    
    char address[MAX_STR];
    int numOfRooms;
    int numOfBathrooms;
    double purchasePrice;
    double monthlyRent;
    double monthlyEarning;
    float annualReturn; // Return on investment, ROI, unit is %.
    double currentValue;
    double captialGains;
    
} PropertyCommon;

//Essential Functions: declarations may be deleted to keep these function for internal use only
void CalculateROI(PropertyCommon *common);
void CalculatecurrentValue(PropertyCommon *common);
void CalculateCapitalGains(PropertyCommon *common);

//Master function that executes the above 3 functions (calculate ROI, Current Value and Capital Gains)
void AnalyzePropertyData(PropertyCommon *common);

#endif /* PropertyCommon */
