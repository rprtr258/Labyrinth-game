#include "Drawer.h"

sf::RenderWindow Drawer::window;
sf::View Drawer::view, Drawer::guiView;;

void Drawer::init() {
    Drawer::window.create(sf::VideoMode(640, 640+GUI_HEIGHT), "Labyrinth", sf::Style::Titlebar|sf::Style::Close);

    view.reset(sf::FloatRect(0, 0, 640, 640));
    view.setCenter(64, 64);
    view.setViewport(sf::FloatRect(0.0f, GUI_HEIGHT/(0.0f+640+GUI_HEIGHT), 1.0f, 1.0f-GUI_HEIGHT/(0.0f+640+GUI_HEIGHT)));

    guiView.reset(sf::FloatRect(0, 0, 640, 640+GUI_HEIGHT));
    guiView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

sf::View& Drawer::getView() {
    return view;
}

sf::RenderWindow& Drawer::getWindow() {
    return window;
}

void Drawer::draw() {
    window.setView(view);
        Labyrinth::draw(window);
        TrueChest::draw(window);
        Player::draw(window);
///////////////////////////////////////
    window.setView(guiView);
        GUI::draw(window);
        Inventory::draw(window);
        Messenger::draw(window);
}
