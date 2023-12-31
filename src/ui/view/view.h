#pragma once


#include <imgui.h>
#include <string>
#include <icons/IconsMaterialDesignIcons.h>


namespace ui {


class View {
protected:
    std::string _menu_title;
    std::string _window_title;
public:
    View(const std::string& menu_title, const std::string& window_title, bool open)
            : _menu_title(menu_title)
            , _window_title(window_title)
            , is_open(open)
    {}

    virtual void draw() = 0;

    bool is_open;
    const std::string& menu_title() const { return _menu_title; }
    const std::string& window_title() const { return _window_title; }
};


} // namespace ui
