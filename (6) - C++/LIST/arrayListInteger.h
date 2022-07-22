#include<vector>

using namespace std;

struct itemListInteger{
 int value; int next;
};

class arrayListInteger
{
private:
 vector<itemListInteger> list;
public:
arrayListInteger();
~arrayListInteger();

}