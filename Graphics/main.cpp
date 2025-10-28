#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 

void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x);

        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ïðèëîæåíèå äëÿ âûâîäà ãðàôèêîâ");

    sf::CircleShape userPoint(5);
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // Îñè X è Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(0, 300);
    xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(800, 300);
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 0);
    yAxis[0].color = sf::Color::White;
    yAxis[1].position = sf::Vector2f(400, 600);
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);


                    float mathX = (mousePos.x - 400) / 30.0f;
                    float mathY = -(mousePos.y - 300) / 10.0f;

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; 

                    float y1 = mathX + 10;
                    float y2 = pow(mathX,2) - mathX + 4;
                    std::string status;
                    if (mathY < y1 and mathY > y2) {
                        status = "Area 1";
                    }
                    else if (mathY > y1 and mathY > y2) {
                        status = "Area 2";
                    }
                    else if (mathY > y1 and mathY < y2 and mathX < 0) {
                        status = "Area 3";
                    }
                    else if (mathY > y1 and mathY < y2 and mathX > 0) {
                        status = "Area 4";
                    }
                    else if (mathY < y1 and mathY < y2) {
                        status = "Area 5";
                    }
                    else {
                        status = "Border";
                    }
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY * 10.0) + ")" + " " + status);
                }
            }
        }


        window.clear();


        window.draw(xAxis);
        window.draw(yAxis);



        drawGraph(window, [](float x) { return x + 10; }, -20, 20, 30, 10, sf::Color::Blue);

        drawGraph(window, [](float x) { return pow(x,2) - x + 4; }, -20, 20, 30, 10, sf::Color::Red);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;
}