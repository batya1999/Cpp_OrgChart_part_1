#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;
namespace ariel
{
    class OrgChart
    {
    public:
        string *begin();
        string *end();
        string *begin_reverse_order();
        string *reverse_order();
        string *begin_level_order();
        string *end_level_order();
        string *begin_preorder();
        string *end_preorder();
        OrgChart add_root(string root);
        OrgChart add_sub(string pre, string pos);
        friend ostream &operator<<(ostream &output, OrgChart &orga);
        
    };

}