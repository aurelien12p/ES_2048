#include <gui/homepage_screen/HomePageView.hpp>

HomePageView::HomePageView()
{

}

void HomePageView::setupScreen()
{
    HomePageViewBase::setupScreen();
    bestScore.setWildcard(homeBestScoreBuffer);
}

void HomePageView::tearDownScreen()
{
    HomePageViewBase::tearDownScreen();
}

void HomePageView::setBestScore(int highScore)
{
    Unicode::snprintf(homeBestScoreBuffer, 16, "%d", highScore);

    bestScore.resizeToCurrentText();
    bestScore.invalidate();
}
