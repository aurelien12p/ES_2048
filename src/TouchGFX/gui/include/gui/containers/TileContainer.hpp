#ifndef TILECONTAINER_HPP
#define TILECONTAINER_HPP

#include <gui_generated/containers/TileContainerBase.hpp>

class TileContainer : public TileContainerBase
{
public:
    TileContainer();
    virtual ~TileContainer() {}

    virtual void initialize();

    void setVal(int value);

protected:
};

#endif // TILECONTAINER_HPP
