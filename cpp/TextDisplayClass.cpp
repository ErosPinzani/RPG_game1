//
// Created by erosp on 01/12/2020.
//

#include "../h/TextDisplayClass.h"

TextDisplayClass::TextDisplayClass() {
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(15);
    text.setString(myString);
}

void TextDisplayClass::Update() {
    text.move(0, -movementSpeed);
    counter++;
    if (counter >= lifeTime)
        destroy = true;
}