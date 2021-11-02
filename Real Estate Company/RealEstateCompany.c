//
//  RealEstateCompany.c - funtion definitions for real estate company
//  Real Estate Company
//
//  Created by Yiyuan Dong on 2021-10-21.
//

#include "RealEstateCompany.h"

//Note: apartment: apt->0 townhouse: th->1 semi-detached house: semi->2

//Sum up the monthly earnings for each apartment, townhouse and semi-detached house.
void SumMonthlyEarnings(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
       
        company->sumOfMonthlyEarnings[apt] += company->apartments[i].common.monthlyEarning;
        company->sumOfMonthlyEarnings[th] += company->townhouses[i].common.monthlyEarning;
        company->sumOfMonthlyEarnings[semi] += company->semiDetached[i].common.monthlyEarning;
        
    }
}

//Sum up the ROI for each apartment, townhouse and semi-detached house.
void SumReturnOnInvestment(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
        
        company->sumOfROI[apt] += company->apartments[i].common.annualReturn;
        company->sumOfROI[th] += company->townhouses[i].common.annualReturn;
        company->sumOfROI[semi] += company->semiDetached[i].common.annualReturn;
        
    }
}

//Sum up the current value for each apartment, townhouse and semi-detached house.
void SumCurrentValue(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
        
        company->sumOfCurrentValue[apt] += company->apartments[i].common.currentValue;
        company->sumOfCurrentValue[th] += company->townhouses[i].common.currentValue;
        company->sumOfCurrentValue[semi] += company->semiDetached[i].common.currentValue;
    }
}

//Sum up the capital gains for each apartment/townhouse/semi-detached house.
void SumCapitalGains(RealEstateCompany *company) {
    
    for(int i = 0; i < NUM_PROPERTY; i++) {
    
        company->sumOfCapitalGains[apt] += company->apartments[i].common.captialGains;
        company->sumOfCapitalGains[th] += company->townhouses[i].common.captialGains;
        company->sumOfCapitalGains[semi] += company->semiDetached[i].common.captialGains;
    }
}

//Calaulate earnings, current values and capital gains for each apartment, townhouse and semi-detached house
void AnalyzeProperties(RealEstateCompany *company) {
    
    for(int j = 0; j < NUM_PROPERTY_TYPES; j++) {

        for (int i = 0; i < NUM_PROPERTY; i++) {
        
            switch (j) { //switch on property type
                    
                case apt: //0, apartment

                    CalculateApartmentMonthlyEarnings(&company->apartments[i]);
                    AnalyzePropertyData(&company->apartments[i].common);
                    
                    break;
                    
                case th: //1, townhouse
                    
                    CalculateTownhouseMonthlyEarnings(&company->townhouses[i]);
                    AnalyzePropertyData(&company->townhouses[i].common);
                    
                    break;
                    
                case semi://2, semi-detached house
    
                    CalculateSemiDetachedMonthlyEarnings(&company->semiDetached[i]);
                    AnalyzePropertyData(&company->semiDetached[i].common);
                    
                    break;
                    
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
void ShowPerformance(const RealEstateCompany *company) {
    
    printf("The following are financial stats for %s, %s.\n\n", company->name, company->address);
    
    for(int i = 0; i < NUM_PROPERTY_TYPES; i++) {
        
        char type[MAX_STR] = "";
        
        if(i == apt) strcpy(type, "apartments");
        else if (i == th ) strcpy(type,"townhouses");
        else if (i == semi) strcpy(type ,"semidetached houses");
        
        printf("For the %s, the monthly earnings are $%.2lf, the roi is %.2lf%%, the total value is $%.2lf and the capital gains are $%.2lf\n\n", type, company->sumOfMonthlyEarnings[i], company->sumOfROI[i], company->sumOfCurrentValue[i], company->sumOfCapitalGains[i]);
    }
    
}
