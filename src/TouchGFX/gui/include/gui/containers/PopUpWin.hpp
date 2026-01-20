#ifndef POPUPWIN_HPP
#define POPUPWIN_HPP

#include <gui_generated/containers/PopUpWinBase.hpp>
#include <touchgfx/Callback.hpp>

class PopUpWin : public PopUpWinBase
{
public:
    PopUpWin();
    virtual ~PopUpWin() {}
    virtual void initialize();

    virtual void retryClicked();
    virtual void continueClicked();

    void setResetCallback(touchgfx::GenericCallback<>& callback)
    {
        resetCallback = &callback;
    }

    void setContinueCallback(touchgfx::GenericCallback<>& callback)
    {
        continueCallback = &callback;
    }

protected:
    touchgfx::GenericCallback<>* resetCallback;
    touchgfx::GenericCallback<>* continueCallback;
};

#endif // POPUPWIN_HPP
