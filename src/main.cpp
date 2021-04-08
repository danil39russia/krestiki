#include "nana/gui/widgets/picture.hpp"
#include "nana/paint/image.hpp"
#include <fmt/core.h>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>

int main() {
    using namespace nana;

    // Define a form.
    form fm;
    int a = 0;
    auto text = [&a] {
        return fmt::format(
            "Hello, <bold blue size=16>Nana C++ Library</>, num = {}\n",
            // "Image: <image=\"image.bmp\">",
            a);
    };
    paint::image img("resources/label_image_maxlimited.png");
    picture pic{fm};

    // Define a label and display a text.
    label lab{fm, text()};
    lab.format(true);

    // Define a button and answer the click event.
    button btn{fm, "Quit"};
    btn.events().click([&fm] { fm.close(); });

    button inc{fm, "++"};
    inc.events().click([&] {
        ++a;
        lab.caption(text());
    });

    // Layout management
    fm.div("vert <>"
           "<<><weight=80% text><>>"
           "<>"
           "<<><weight=50%<img2>><>>"
           "<>"
           "<weight=24<><button><>>"
           "<>");
    fm["text"] << lab;
    fm["button"] << btn;
    fm["button"] << inc;
    fm["img2"] << pic;
    fm.collocate();

    pic.load(img);
    // Show the form
    fm.show();

    // Start to event loop process, it blocks until the form is closed.
    exec();
}
