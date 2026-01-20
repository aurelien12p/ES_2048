#include <gui/containers/PopUpWin.hpp>

PopUpWin::PopUpWin() : resetCallback(0), continueCallback(0)
{
}

void PopUpWin::initialize()
{
    PopUpWinBase::initialize();
}

void PopUpWin::retryClicked()
{
    if (resetCallback && resetCallback->isValid())
    {
        resetCallback->execute();
    }
}

void PopUpWin::continueClicked()
{
    if (continueCallback && continueCallback->isValid())
    {
        continueCallback->execute();
    }

    setVisible(false);
    invalidate();
}
