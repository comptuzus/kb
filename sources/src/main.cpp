
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);

    while (window.isOpen())
    {
        std::string montext("Coucou SFML " + std::to_string(window.getSize().x)
                            + " " + std::to_string(sf::Mouse::getPosition(window).x));
        sf::Text text(montext, font, 50);
        text.setFillColor(sf::Color::White);
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
        }
        sf::Vector2i position = sf::Mouse::getPosition(window);
        // Clear screen
        window.clear(sf::Color::Blue);
        // Draw the string
        text.setPosition(sf::Vector2f(position));
        window.draw(text);
        position.x -= (rectangle.getSize().x / 2);
        position.y = window.getSize().y - (rectangle.getSize().y * 2);
        rectangle.setPosition(sf::Vector2f(position));
        window.draw(rectangle);
        // Update the window
        window.display();

    }

    return EXIT_SUCCESS;
}
