//
//  RealEstateCompany.c - funtion definitions for real estate company
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#include "RealEstateCompany.h"
#include <string.h>
//Sum up the monthly earnings for each apartment, townhouse and semi-detached house.
void SumMonthlyEarnings(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
        //Sum up earnings for each apartment. apt = 0
        company->sumOfMonthlyEarnings[apt] += company->apartments[i].common.monthlyEarning;
        //Sum up earnings for each townhouse. th = 1
        company->sumOfMonthlyEarnings[th] += company->townhouses[i].common.monthlyEarning;
        //Sum up earnings for each semi-detached house. semi = 2
        company->sumOfMonthlyEarnings[semi] += company->semiDetached[i].common.monthlyEarning;
        
    }
}

//Sum up the ROI for each apartment, townhouse and semi-detached house.
void SumReturnOnInvestment(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
        //Sum up ROI for each apartment. apt = 0
        company->sumOfROI[apt] += company->apartments[i].common.annualReturn;
        //Sum up ROI for each townhouse. th = 1
        company->sumOfROI[th] += company->townhouses[i].common.annualReturn;
        //Sum up ROI for each semi-detached house. semi = 2
        company->sumOfROI[semi] += company->semiDetached[i].common.annualReturn;
        
    }
    
}

//Sum up the current value for each apartment, townhouse and semi-detached house.
void SumCurrentValue(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
        //Sum up the current value apartment. apt = 0
        company->sumOfCurrentValue[apt] += company->apartments[i].common.currentValue;
        //Sum up the current value towhhouse. th = 1
        company->sumOfCurrentValue[th] += company->townhouses[i].common.currentValue;
        //Sum up the current value semi-detached house. semi = 2
        company->sumOfCurrentValue[semi] += company->semiDetached[i].common.currentValue;
    }
}

//Sum up the capital gains for each apartment/townhouse/semi-detached house.
void SumCapitalGains(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
        //Sum up the capital gains for apartment. apt = 0
        company->sumOfCapitalGains[apt] += company->apartments[i].common.captialGains;
        //Sum up the capital gains for towhhouse. th = 1
        company->sumOfCapitalGains[th] += company->townhouses[i].common.captialGains;
        //Sum up the capital gains for semi-detached house. semi = 2
        company->sumOfCapitalGains[semi] += company->semiDetached[i].common.captialGains;
    }
}

//Calaulate earnings, current values and capital gains for each apartment, townhouse and semi-detached house
void analyzePropertiesForCompany(RealEstateCompany *company) {
    
    //Go through different type of properties, apartment: apt->0 townhouse: th->1 semi-detached house: semi->2
    for(int j = 0; j < NUM_PROPERTY_TYPES; j++) {
        //Go through each property of the same type
        for (int i = 0; i < NUM_PROPERTY; i++) {
        
            switch (j) { //switch on property type
                    
                case apt: //0, apartment
                    //1.calculate earnings
                    CalculateApartmentMonthlyEarnings(&company->apartments[i]);
                    //2.calculate ROI, current Value and Capital gain
                    AnalyzeProperty(&company->apartments[i].common);
                    break;
                    
                case th: //1, townhouse
                    //1.calculate earnings
                    CalculateTownhouseMonthlyEarnings(&company->townhouses[i]);
                    //2.calculate ROI, current Value and Capital gain
                    AnalyzeProperty(&company->townhouses[i].common);
                    break;
                    
                case semi://2, semi-detached house
                    //1.calculate earnings
                    CalculateSemiDetachedMonthlyEarnings(&company->semiDetached[i]);
                    //2.calculate ROI, current Value and Capital gain
                    AnalyzeProperty(&company->semiDetached[i].common);
                    break;;
                default:
                    break;
            }
        }
    }
}

//For convenience, sum up the monthly earnings, ROI, current value and captital gains in one function
void CalculatePerformance(RealEstateCompany *company) {
    
     SumMonthlyEarnings(company);
     SumReturnOnInvestment(company);
     SumCurrentValue(company);
     SumCapitalGains(company);

}

//Print out the performance for each property type
void ShowPerformance(RealEstateCompany company) {
    
    printf("The following are financial stats for %s, %s.\n\n", company.name, company.address);
    
    for(int i = 0; i < NUM_PROPERTY_TYPES; i++) {
        
        char type[32] = "";
        
        if(i == apt) strcpy(type, "apartments");
        else if (i == th ) strcpy(type,"townhouses");
        else if (i == semi) strcpy(type ,"semidetached houses");
        
        printf("For the %s, the monthly earnings are $%.2lf, the roi is %.2lf%%, the total value is $%.2lf and the capital gains are $%.2lf\n\n", type, company.sumOfMonthlyEarnings[i], company.sumOfROI[i], company.sumOfCurrentValue[i], company.sumOfCapitalGains[i]);
    }
    
}
