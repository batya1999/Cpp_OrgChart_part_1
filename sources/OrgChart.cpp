#include "OrgChart.hpp"
using namespace std;
namespace ariel{

    OrgChart OrgChart::add_sub(string pre, string post)
    {
        return *this;
    }

    string *OrgChart::begin_level_order()
    {
        return NULL;
    }


    string *OrgChart::end_level_order()
    {
        return NULL;
    }

    string *OrgChart::begin_reverse_order()
    {
        return NULL;
    }
    
    string *OrgChart::reverse_order()
    {
        return NULL;
    }

    string *OrgChart::begin_preorder()
    {
        return NULL;
    }
    

    OrgChart OrgChart::add_root(string root)
    {
        return *this;
    }

    string *OrgChart::end_preorder()
    {
        return NULL;
    }
    string *OrgChart::begin()
    {
        return begin_level_order(); 
    }
    string *OrgChart::end()
    { 
        return end_level_order(); 
    }
    ostream &operator<<(ostream &output, OrgChart &organization)
    {
        return output;
    }

}