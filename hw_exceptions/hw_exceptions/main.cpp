#include "exception.h"

void fail()
{
    THROW(new TypedException());
}

void fail_second()
{
    std::cout << "fail 1" << '\n';
    fail();
}


int main()
{
    TRY
    {
        TRY
        {
            fail_second();
        }
        CATCH(TypedException, e)
        {
            std::cout << e->GetMessage() << " fail 2 " << '\n';
        }
        CATCH(CException, e)
        {
            std::cout << e->GetMessage() << " fail 3 " << '\n';
        }
        ENDTRYCATCH;
    }
        CATCH(CException, e)
    {
        std::cout << e->GetMessage() << " fail 4 " << '\n';
    }
    ENDTRYCATCH;

    std::cout << "fail 5" << '\n';
    return 0;
}