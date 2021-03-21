#include <iostream>
using namespace std;

#include "BankingSystem.h"

//-------CONSTRUCTOR---------
BankingSystem::BankingSystem()
{
    customerNames = NULL;
    customerIds = NULL;
    numCustomers = 0;

    branchNames = NULL;
    branchIds = NULL;
    numBranches = 0;

    accounts = NULL;
    numAccounts = 0;
}

BankingSystem::~BankingSystem()
{
    delete [] branchNames;
    delete [] branchIds;
    delete [] customerIds;
    delete [] customerNames; // reclaim spaces
}


//---------------------------BRANCH FUNCTIONS--------------------------------
 void BankingSystem::addBranch( const int branchId, const string branchName )
 {
     string *tempBranchName;
     int *tempBranchId;
     bool branchExist = false;

     tempBranchName = new string[numBranches+1];
     tempBranchId = new int[numBranches+1];

     for(int i=0; i<numBranches; i++)
     {
         tempBranchName[i] = branchNames[i];
         tempBranchId[i] = branchIds[i];
         if( branchIds[i] == branchId )
            branchExist = true;
     }

     tempBranchName[numBranches] = branchName;
     tempBranchId[numBranches] = branchId;

     if( branchExist )
        cout << "Branch "<< branchId << " already exists" << endl;

     else
     {
         delete []branchNames;
         delete []branchIds;

         branchNames = tempBranchName;
         branchIds = tempBranchId;
        numBranches++;

         cout << "Branch "<< branchId << " has been added" << endl;
     }
 }
