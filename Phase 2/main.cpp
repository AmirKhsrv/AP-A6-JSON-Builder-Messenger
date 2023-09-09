#include "Messenger.hpp"

using namespace std;

int main()
{
    Messenger* messenger = new Messenger();
    for (int i = 0; i < 20; i++)
    {
        try
        {
            messenger->getOrder();
        }
        catch(const exception& e)
        {
            cerr << e.what();
        }
    }
    return 0;
}