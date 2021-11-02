//RealEstateMain.c - main program for real estate companies

// 02-Mar-21  M. Watler         Created
// 22-Oct-21  Yiyuan Dong       Modified
// Student ID 065-182-131

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "RealEstateCompany.h"

int initCompanyData(RealEstateCompany *company);

int main(void) {
    
    int ret = 0;
    
    RealEstateCompany company = {"Brookfield Asset Management", "11 Yonge Street"};
    
    //init company data from files, returns an error code
    ret = initCompanyData(&company);
    
    // error code is -1, files not found. Program will abort.
    if (ret == -1) printf("Files not found. Program aborting...\n");
    
    else {
        //Calaulate earnings, current values and capital gains for each property
        AnalyzeProperties(&company);
        //Sum up the earnings, current values and capital gains for each type of property
        CalculatePerformance(&company);
        //Print out a  breif report
        ShowPerformance(&company);
    }

    return ret;
}

int initCompanyData(RealEstateCompany *company) {
    //Read the data for all companies from a file
    char address[MAX_STR];
    int rooms;
    int bathrooms;
    double purchasePrice;
    double monthlyRent;
    double monthlyUtilities;
    double monthlyCondoFees;
    double monthlyPropertyTax;
    
    //Retrieve data for apartments
    FILE* fp = fopen("Apartments.txt", "r");
    
    if (fp == NULL) return -1;
    
    for (int i = 0; i < NUM_PROPERTY; ++i) {
        fscanf(fp, "%[^\n]s", address);
        fscanf(fp, "%d", &rooms);
        fscanf(fp, "%d", &bathrooms);
        fscanf(fp, "%lf", &purchasePrice);
        fscanf(fp, "%lf", &monthlyRent);
        fscanf(fp, "%lf", &monthlyCondoFees);
        while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
        
        Apartment apt = {"", rooms, bathrooms, purchasePrice, monthlyRent, 0, 0, 0, 0, monthlyCondoFees};
        strcpy(apt.common.address, address);

        company->apartments[i] = apt;
        
    }
    
    fclose(fp);
    
    //Retrieve data for townhouses
    fp = fopen("Townhouses.txt", "r");
    
    if (fp == NULL) return -1;
    
    for (int i = 0; i < NUM_PROPERTY; ++i) {
        fscanf(fp, "%[^\n]s", address);
        fscanf(fp, "%d", &rooms);
        fscanf(fp, "%d", &bathrooms);
        fscanf(fp, "%lf", &purchasePrice);
        fscanf(fp, "%lf", &monthlyRent);
        fscanf(fp, "%lf", &monthlyUtilities);
        fscanf(fp, "%lf", &monthlyCondoFees);
        fscanf(fp, "%lf", &monthlyPropertyTax);
        while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
        
        Townhouse th = {"", rooms, bathrooms, purchasePrice, monthlyRent, 0, 0, 0, 0, monthlyUtilities, monthlyCondoFees, monthlyPropertyTax};
        strcpy(th.common.address, address);
        
        company->townhouses[i] = th;
    }
    fclose(fp);
    
    //Retrieve data for semi-detached houses
    fp = fopen("SemiDetachedHouses.txt", "r");
    
    if (fp == NULL) return -1;
    
    for (int i = 0; i < NUM_PROPERTY; ++i) {
        fscanf(fp, "%[^\n]s", address);
        fscanf(fp, "%d", &rooms);
        fscanf(fp, "%d", &bathrooms);
        fscanf(fp, "%lf", &purchasePrice);
        fscanf(fp, "%lf", &monthlyRent);
        fscanf(fp, "%lf", &monthlyUtilities);
        fscanf(fp, "%lf", &monthlyPropertyTax);
        while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
        
        SemiDetachedHouse semi = {"", rooms, bathrooms, purchasePrice, monthlyRent, 0, 0, 0, 0, monthlyUtilities, monthlyPropertyTax};
        strcpy(semi.common.address, address);
        
        company->semiDetached[i] = semi;
    }
    fclose(fp);
    
    return 0;
    
}
