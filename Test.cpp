#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("CHECK_THROWS and CHECK NOT_THROWS")
{
    OrgChart organization;
    organization.add_root("TOP")
      .add_sub("TOP", "A1")         
      .add_sub("TOP", "A2")         
      .add_sub("TOP", "A3")         
      .add_sub("TOP", "A4")         
      .add_sub("A4", "a4")  
      .add_sub("A1", "a1") 
      .add_sub("A3", "a3");      

  cout << organization << endl; /* Should Print:
       TOP
       |--------|--------|--------|
       A1      A2      A3        A4    
       |                 |        |
       a1               a3       a4
 */
    vector<string> check0 = {"TOP", "A1", "A2", "A3", "A4", "a1", "a3", "a4"};
    unsigned int i0=0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        CHECK_EQ(check0.at(i0), *it);
        i0++;
    } 

    CHECK_THROWS(organization.add_sub("A5", "a5"));
    CHECK_THROWS(organization.add_sub("A6", "a6"));
    CHECK_THROWS(organization.add_sub("A7", "a7"));
    CHECK_NOTHROW(organization.add_sub("TOP", "A5"));
    CHECK_NOTHROW(organization.add_sub("A5", "a5"));
    CHECK_NOTHROW(organization.add_sub("A6", "a6"));
    CHECK_NOTHROW(organization.add_sub("A7", "a7"));

    vector<string> check = {"TOP", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "a1", "a3", "a4", "a5", "a6", "a7"};
    unsigned int i1=0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        CHECK_EQ(check.at(i1), *it);
        i1++;
    } 
    
    string root = "root";
    string sub = "sub";
    for(int j=0; j<20; j++){
        CHECK_THROWS(organization.add_sub(root, sub));
    }
    for(int j=0; j<20; j++){
        CHECK_NOTHROW(organization.add_sub("A6", sub));
    }

}

