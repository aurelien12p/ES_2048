#include <gui/containers/PopUpGameOver.hpp>

PopUpGameOver::PopUpGameOver() : retryCallback(0)
{
}

void PopUpGameOver::initialize()
{
    PopUpGameOverBase::initialize();
}

void PopUpGameOver::retryClicked()
{
    if (retryCallback && retryCallback->isValid())
    {
        retryCallback->execute();
    }
}
