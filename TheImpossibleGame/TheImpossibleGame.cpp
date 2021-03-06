#include "pch.h"
#include <SFML/Window.hpp>

#include "Modules/Hub.hpp"

#include "Modules/Levels/sounds/Sounds.hpp"

int main() {

	ModuleShape::window = new RenderWindow;
	ModuleShape::event = new Event;

	ModuleShape::window->create(
		VideoMode(1280, 720), 
		"The Impossible Game", 
		Style::Titlebar | Style::Close | Style::Fullscreen
	);

	ModuleShape::windowWidth = ModuleShape::window->getSize().x;
	ModuleShape::windowHeight = ModuleShape::window->getSize().y;

	Sounds::Sounds();
	Hub::Hub();

	ModuleShape::mainTheme->setLoop(true);
	ModuleShape::mainTheme->play();

	while (ModuleShape::window->isOpen()) {
		
		ModuleShape::windowWidth = ModuleShape::window->getSize().x;
		ModuleShape::windowHeight = ModuleShape::window->getSize().y;

		ModuleShape::window->clear(Color::Black);
		Hub::motion();

		while (ModuleShape::window->pollEvent(*(ModuleShape::event))) {
			switch (ModuleShape::event->type) {
				case Event::KeyPressed: {
					if (Keyboard::isKeyPressed(Keyboard::M)) {
						if (Hub::mainThemePlays) Hub::mainTheme->pause();
						else Hub::mainTheme->play();
						Hub::mainThemePlays = !Hub::mainThemePlays;
					}
					break;
				}
				case Event::Closed: {
					ModuleShape::window->close();
					break;
				}
			}
			Hub::events();
		}
		Hub::render();

		ModuleShape::window->display();
	}
}