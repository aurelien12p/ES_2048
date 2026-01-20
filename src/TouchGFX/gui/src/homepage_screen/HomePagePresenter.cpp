#include <gui/homepage_screen/HomePageView.hpp>
#include <gui/homepage_screen/HomePagePresenter.hpp>

HomePagePresenter::HomePagePresenter(HomePageView& v)
    : view(v)
{

}

void HomePagePresenter::activate()
{
    view.setBestScore(model->getHighScore());
}

void HomePagePresenter::deactivate()
{

}
