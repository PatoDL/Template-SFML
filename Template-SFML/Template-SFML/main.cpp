#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
#include "STP\Core\ObjectGroup.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\RectangleShape.hpp"

using namespace sf;

Texture texture;
Sprite sprite;
RectangleShape collider;

void cargarTextura()
{
	texture.loadFromFile("res/xd.png");
	sprite.setTexture(texture);
}

void setSpriteConf()
{
	sprite.setPosition(90.f, 90.f);
}

void initSprite()
{
	cargarTextura();
	setSpriteConf();
}

Sprite drawSprite()
{
	return sprite;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "STP Example");
	tmx::TileMap map("res/atr.tmx");

	map.ShowObjects(); // Display all the layer objects.

	initSprite();

	float recY = 0.f;

	sf::View view1;

	sf::View view2(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f));

	while (window.isOpen()) {    // Start the game loop
								 // Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		view1.reset(sf::FloatRect(0.f, recY, 800.f, 600.f));

		window.setView(view1);
		sf::View currentview = window.getView();

		sprite.setPosition(view1.getCenter().x-sprite.getLocalBounds().width/2, view1.getCenter().y-sprite.getLocalBounds().height/2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			recY++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			recY--;
		}

		// Clear screen
		window.clear();
		// Draw the map
		window.draw(map);
		window.draw(drawSprite());
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}