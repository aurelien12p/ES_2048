#include <gui/containers/TileContainer.hpp>
#include <touchgfx/Color.hpp>
#include <cstdio>

TileContainer::TileContainer()
{
}

void TileContainer::initialize()
{
    TileContainerBase::initialize();
}

void TileContainer::setVal(int value)
{
    touchgfx::colortype darkText = touchgfx::Color::getColorFromRGB(119, 110, 101);
    touchgfx::colortype whiteText = touchgfx::Color::getColorFromRGB(255, 255, 255);

    if (value == 0)
    {
        number.setVisible(false);
        box1.setColor(touchgfx::Color::getColorFromRGB(205, 193, 180));
    }
    else
    {
        number.setVisible(true);

        // 3. Switch géant pour toutes les couleurs
        switch (value)
        {
        case 2:
            box1.setColor(touchgfx::Color::getColorFromRGB(238, 228, 218));
            number.setColor(darkText);
            break;

        case 4:
            box1.setColor(touchgfx::Color::getColorFromRGB(237, 224, 200));
            number.setColor(darkText);
            break;

        case 8:
            box1.setColor(touchgfx::Color::getColorFromRGB(242, 177, 121));
            number.setColor(whiteText);
            break;

        case 16:
            box1.setColor(touchgfx::Color::getColorFromRGB(245, 149, 99));
            number.setColor(whiteText);
            break;

        case 32:
            box1.setColor(touchgfx::Color::getColorFromRGB(246, 124, 95));
            number.setColor(whiteText);
            break;

        case 64:
            box1.setColor(touchgfx::Color::getColorFromRGB(246, 94, 59));
            number.setColor(whiteText);
            break;

        case 128:
            box1.setColor(touchgfx::Color::getColorFromRGB(237, 207, 114));
            number.setColor(whiteText);
            break;

        case 256:
            box1.setColor(touchgfx::Color::getColorFromRGB(237, 204, 97));
            number.setColor(whiteText);
            break;

        case 512:
            box1.setColor(touchgfx::Color::getColorFromRGB(237, 200, 80));
            number.setColor(whiteText);
            break;

        case 1024:
            box1.setColor(touchgfx::Color::getColorFromRGB(237, 197, 63));
            number.setColor(whiteText);
            break;

        case 2048:
            box1.setColor(touchgfx::Color::getColorFromRGB(237, 194, 46));
            number.setColor(whiteText);
            break;

        default:
            box1.setColor(touchgfx::Color::getColorFromRGB(60, 58, 50));
            number.setColor(whiteText);
            break;
        }

        Unicode::snprintf(numberBuffer, NUMBER_SIZE, "%d", value);
        number.setWildcard(numberBuffer);
    }

    number.invalidate();
    box1.invalidate();
}
