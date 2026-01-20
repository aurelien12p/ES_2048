#ifndef HOMEPAGEPRESENTER_HPP
#define HOMEPAGEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class HomePageView;

class HomePagePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    HomePagePresenter(HomePageView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~HomePagePresenter() {}

private:
    HomePagePresenter();

    HomePageView& view;
};

#endif // HOMEPAGEPRESENTER_HPP
