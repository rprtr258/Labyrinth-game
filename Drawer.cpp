#include "Drawer.h"
sf::RectangleShape r;
Drawer::Drawer() {
    window.create(sf::VideoMode(640, 640+GUI_HEIGHT), "Labyrinth");
    view.reset(sf::FloatRect(0, 0, 640, 640));
    view.setCenter(64, 64);
    view.setViewport(sf::FloatRect(0.0f, GUI_HEIGHT/(0.0f+640+GUI_HEIGHT), 1.0f, 1.0f-GUI_HEIGHT/(0.0f+640+GUI_HEIGHT)));
}

void Drawer::pushDrawable(DrawableInterface* thing) {
    things.push_back(thing);
}

void Drawer::setGUI(DrawableInterface* gui) {
    this->gui = gui;
}

sf::View& Drawer::getView() {
    return view;
}

sf::RenderWindow& Drawer::getWindow() {
    return window;
}

void Drawer::draw() {
    sf::View guiView;
    guiView.reset(sf::FloatRect(0, 0, 640, 640+GUI_HEIGHT));
    guiView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
    window.setView(guiView);
    gui->draw(window);
    things.at(3)->draw(window);
    window.setView(view);
    for(std::vector<DrawableInterface*>::iterator it = things.begin();it!=things.end()-1;it++) {
        (*it)->draw(window);
    }
}
