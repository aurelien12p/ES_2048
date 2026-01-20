#ifndef POPUPGAMEOVER_HPP
#define POPUPGAMEOVER_HPP

#include <gui_generated/containers/PopUpGameOverBase.hpp>
#include <touchgfx/Callback.hpp>

class PopUpGameOver : public PopUpGameOverBase
{
public:
    PopUpGameOver();
    virtual ~PopUpGameOver() {}
    virtual void initialize();

    virtual void retryClicked();

    void setRetryCallback(touchgfx::GenericCallback<>& callback)
    {
        retryCallback = &callback;
    }

protected:
    touchgfx::GenericCallback<>* retryCallback;
};

#endif // POPUPGAMEOVER_HPP
