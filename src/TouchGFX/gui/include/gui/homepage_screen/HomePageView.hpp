#ifndef HOMEPAGEVIEW_HPP
#define HOMEPAGEVIEW_HPP

#include <gui_generated/homepage_screen/HomePageViewBase.hpp>
#include <gui/homepage_screen/HomePagePresenter.hpp>

class HomePageView : public HomePageViewBase
{
public:
    HomePageView();
    virtual ~HomePageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void setBestScore(int highScore);
protected:
    touchgfx::Unicode::UnicodeChar homeBestScoreBuffer[20];
};

#endif // HOMEPAGEVIEW_HPP
