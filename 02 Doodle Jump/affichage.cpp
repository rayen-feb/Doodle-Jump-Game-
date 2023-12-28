#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace sf;


void gameOver()
{
     RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

sf::Font font;

if (!font.loadFromFile("Arial.ttf"))
{
    // Gérer l'erreur...
}
sf::Text text;

// Sélectionnez la police à utiliser
text.setFont(font);

// Définissez la chaîne à afficher
text.setString("Game over ");

// Définissez la taille des caractères
text.setCharacterSize(24); // en pixels, pas en points !

// Définissez la couleur du texte
text.setFillColor(sf::Color::Red);

// Définissez le style du texte
text.setStyle(sf::Text::Bold | sf::Text::Underlined);}
