//
//  PropertyCommon.c - function definitions for property common
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#include "PropertyCommon.h"

//Calculate the return on invesement in %
void CalculateROI(PropertyCommon *common){
    
    //ROI = 100 x 12 x monthly earnings / purchase price.
    common->annualReturn = (100.0 * 12.0 * common->monthlyEarning) / common->purchasePrice;
    
}

//Calculate the current value of property
void CalculatecurrentValue(PropertyCommon *common){
    
    //current value = 12 x monthly earnings / interest rate. The interest rate is hard-coded to 5% (or 0.05).
    common->currentValue = (12.0 * common->monthlyEarning) / 0.05;
    
}

//Calculate the capital gains
void CalculateCapitalGains(PropertyCommon *common) {
    
    //capital gains = current value - purchase price.
    common->captialGains = common->currentValue - common->purchasePrice;
    
}

// For convenience, execute the calculation of ROI, current value and capital gains in one function
void AnalyzeProperty(PropertyCommon *common) {
    
    CalculateROI(common);
    CalculatecurrentValue(common);
    CalculateCapitalGains(common);
    
    
}
