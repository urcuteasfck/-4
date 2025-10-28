#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Saturn with Moons");

    sf::RectangleShape bg(sf::Vector2f(800, 600));
    bg.setFillColor(sf::Color(24, 22, 61));

    float planetRadius = 95;
    sf::CircleShape planet(planetRadius);
    planet.setFillColor(sf::Color(225, 130, 0));
    planet.setOutlineThickness(5);
    planet.setOutlineColor(sf::Color(200, 100, 0));
    planet.setOrigin(planetRadius, planetRadius);
    planet.setPosition(400, 300);

    float ringX = 400, ringY = 300;
    float ringRadius = 120;
    float ringScaleX = 2.6f, ringScaleY = 0.8f;
    float ringAngle = -18.f;

    sf::CircleShape ring1(ringRadius);
    ring1.setScale(ringScaleX, ringScaleY);
    ring1.setFillColor(sf::Color(182, 153, 86));
    ring1.setPosition(ringX, ringY);
    ring1.setOrigin(ringRadius, ringRadius);
    ring1.setRotation(ringAngle);

    sf::CircleShape ring2(100);
    ring2.setScale(ringScaleX, ringScaleY);
    ring2.setFillColor(sf::Color(150, 75, 0));
    ring2.setPosition(ringX, ringY);
    ring2.setOrigin(100, 100);
    ring2.setRotation(ringAngle);

    float ovalCenterX = ringX;
    float ovalCenterY = ringY;

    float leftMoonRadius = 12;
    sf::CircleShape moonLeft(leftMoonRadius);
    moonLeft.setFillColor(sf::Color(179, 179, 204));
    moonLeft.setOrigin(leftMoonRadius, leftMoonRadius);
    moonLeft.setPosition(ovalCenterX - 220, ovalCenterY - 30);

    float rightMoonRadius = 18;

    float moonRingRadiusX = ringRadius * ringScaleX;
    float moonRingRadiusY = ringRadius * ringScaleY;
    float moonRightX = ovalCenterX + moonRingRadiusX * 0.6f;   
    float moonRightY = ovalCenterY;

    sf::CircleShape moonRight(rightMoonRadius);
    moonRight.setFillColor(sf::Color(200, 200, 230));
    moonRight.setOrigin(rightMoonRadius, rightMoonRadius);
    moonRight.setPosition(moonRightX, moonRightY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bg);
        window.draw(ring1);
        window.draw(ring2);
        window.draw(planet);
        window.draw(moonLeft);
        window.draw(moonRight);
        window.display();
    }

    return 0;
}
//#include<SFML/Graphics.hpp>
//#include <functional> 
//#include <cmath> 
//
//void drawGraph(sf::RenderWindow & window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
//    sf::VertexArray graph(sf::LinesStrip);
//
//    for (float x = xMin; x <= xMax; x += 0.1f) {
//        float y = func(x);
//
//        float screenX = 400 + x * scaleX;
//        float screenY = 300 - y * scaleY;
//
//        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
//    }
//
//    window.draw(graph);
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Ïðèëîæåíèå äëÿ âûâîäà ãðàôèêîâ");
//
//    sf::CircleShape userPoint(5);
//    userPoint.setFillColor(sf::Color::Red);
//    bool userPointExists = false;
//
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf")) {
//        return -1;
//    }
//    sf::Text coordinatesText;
//    coordinatesText.setFont(font);
//    coordinatesText.setCharacterSize(20);
//    coordinatesText.setFillColor(sf::Color::White);
//    coordinatesText.setPosition(10, 10);
//
//    // Îñè X è Y
//    sf::VertexArray xAxis(sf::Lines, 2);
//    xAxis[0].position = sf::Vector2f(0, 300);
//    xAxis[0].color = sf::Color::White;
//    xAxis[1].position = sf::Vector2f(800, 300);
//    xAxis[1].color = sf::Color::White;
//
//    sf::VertexArray yAxis(sf::Lines, 2);
//    yAxis[0].position = sf::Vector2f(400, 0);
//    yAxis[0].color = sf::Color::White;
//    yAxis[1].position = sf::Vector2f(400, 600);
//    yAxis[1].color = sf::Color::White;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed) {
//                if (event.mouseButton.button == sf::Mouse::Left) {
//                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//
//                    float mathX = (mousePos.x - 400) / 30.0f;
//                    float mathY = -(mousePos.y - 300) / 10.0f;
//
//                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
//                    userPointExists = true;
//
//                    float y1 = mathX + 10;
//                    float y2 = pow(mathX, 2) - mathX + 4;
//                    std::string status;
//                    if (mathY < y1 and mathY > y2) {
//                        status = "Area 1";
//                    }
//                    else if (mathY > y1 and mathY > y2) {
//                        status = "Area 2";
//                    }
//                    else if (mathY > y1 and mathY < y2 and mathX < 0) {
//                        status = "Area 3";
//                    }
//                    else if (mathY > y1 and mathY < y2 and mathX > 0) {
//                        status = "Area 4";
//                    }
//                    else if (mathY < y1 and mathY < y2) {
//                        status = "Area 5";
//                    }
//                    else {
//                        status = "Border";
//                    }
//                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY * 10.0) + ")" + " " + status);
//                }
//            }
//        }
//
//
//        window.clear();
//
//
//        window.draw(xAxis);
//        window.draw(yAxis);
//
//
//
//        drawGraph(window, [](float x) { return x + 10; }, -20, 20, 30, 10, sf::Color::Blue);
//
//        drawGraph(window, [](float x) { return pow(x, 2) - x + 4; }, -20, 20, 30, 10, sf::Color::Red);
//
//        if (userPointExists) {
//            window.draw(userPoint);
//            window.draw(coordinatesText);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}
//












//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <random>
//#include <string>
//
//// Константы для настройки мира
//const unsigned int WORLD_WIDTH = 20;  // Ширина сетки
//const unsigned int WORLD_HEIGHT = 20; // Высота сетки
//const unsigned int CELL_SIZE = 30;    // Размер клетки в пикселях
//const sf::Color LIVE_COLOR = sf::Color::White;  // Цвет "живых" клеток
//const sf::Color DEAD_COLOR = sf::Color::Black;  // Цвет "мертвых" клеток
//const sf::Color GRID_COLOR = sf::Color::Red;    // Цвет линии сетки
//
//// Структура Point представляет клетку сетки, хранящую её статус
//struct Point {
//    bool is_live = false;  // Флаг, живет ли клетка
//};
//void initWorld(std::vector<std::vector<Point>>& world) {
//    std::random_device rd;
//    std::mt19937 gen(rd());  // Генератор случайных чисел
//    std::uniform_int_distribution<> dis(0, 1);  // Диапазон: 0 или 1
//
//    for (unsigned int y = 0; y < WORLD_HEIGHT; ++y) {
//        for (unsigned int x = 0; x < WORLD_WIDTH; ++x) {
//            world[y][x].is_live = dis(gen) == 1;  // Случайное присвоение статуса
//        }
//    }
//}
//// Функция обновляет мир согласно правилам "Жизни"
//// Функция обновляет мир согласно правилам "Жизни"
//void updateWorld(std::vector<std::vector<Point>>& world, const std::vector<std::vector<Point>>& prevWorld) {
//    // Лямбда-функция для подсчета живых соседей вокруг клетки
//    auto countLiveNeighbors = [&](unsigned int x, unsigned int y) -> unsigned int {
//        unsigned int count = 0;
//        for (int dy = -1; dy <= 1; ++dy) {
//            for (int dx = -1; dx <= 1; ++dx) {
//                if (dx == 0 && dy == 0) continue;  // Пропуск самой клетки
//                int nx = x + dx;
//                int ny = y + dy;
//                if (nx >= 0 && ny >= 0 && nx < WORLD_WIDTH && ny < WORLD_HEIGHT && prevWorld[ny][nx].is_live) {
//                    ++count;
//                }
//            }
//        }
//        return count;
//        };
//
//    // Применение правил "Жизни" к каждой клетке
//    for (unsigned int y = 0; y < WORLD_HEIGHT; ++y) {
//        for (unsigned int x = 0; x < WORLD_WIDTH; ++x) {
//            unsigned int liveNeighbors = countLiveNeighbors(x, y);
//            if (prevWorld[y][x].is_live) {
//                world[y][x].is_live = liveNeighbors == 2 || liveNeighbors == 3;  // Клетка выживает
//            }
//            else {
//                world[y][x].is_live = liveNeighbors == 3;  // Новая клетка рождается
//            }
//        }
//    }
//}
//    // Проверка, идентичны ли два мира (нет изменений)
//bool worldsAreEqual(const std::vector<std::vector<Point>>&w1, const std::vector<std::vector<Point>>&w2); {
//    for (unsigned int y = 0; y < WORLD_HEIGHT; ++y) {
//        for (unsigned int x = 0; x < WORLD_WIDTH; ++x) {
//            if (w1[y][x].is_live != w2[y][x].is_live) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//
//    // Применение правил "Жизни" к каждой клетке
//for (unsigned int y = 0; y < WORLD_HEIGHT; ++y) {
//    for (unsigned int x = 0; x < WORLD_WIDTH; ++x) {
//        unsigned int liveNeighbors = countLiveNeighbors(x, y);
//        if (prevWorld[y][x].is_live) {
//            world[y][x].is_live = liveNeighbors == 2 || liveNeighbors == 3;  // Клетка выживает
//        }
//        else {
//            world[y][x].is_live = liveNeighbors == 3;  // Новая клетка рождается
//        }
//    }
//}
//
//
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(WORLD_WIDTH * CELL_SIZE, WORLD_HEIGHT * CELL_SIZE), "Game of Life");
//
//    // Создаем двумерные массивы для текущего и предыдущего состояний мира с именем world и prevWorld (массивы хранят клетки! (Point!)
//    std::vector<std::vector<Point>>world(WORLD_WIDTH, std::vector<Point>(WORLD_HEIGHT));
//    std::vector<std::vector<Point>>prevWorld(WORLD_WIDTH, std::vector<Point>(WORLD_HEIGHT));
//
//
//
//
//    initWorld(world);  // Инициализируем мир 
//    // Загрузка шрифта для вывода текста
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf")) {  // Путь к файлу шрифта
//        return EXIT_FAILURE;
//    }
//
//    // Настройка текста для вывода статуса
//    sf::Text statusText;
//    statusText.setFont(font);
//    statusText.setCharacterSize(24);
//    statusText.setFillColor(sf::Color::Red);
//    sf::Clock clock;
//    const sf::Time updateInterval = sf::seconds(0.5f);  // Интервал обновления в секундах
//
//    bool optimalDetected = false;
//    bool showGrid = false;  // Отображение сетки
//    bool isPaused = false;  // Пауза
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            // Обработка нажатий клавиш
//            else if (event.type == sf::Event::KeyPressed) {
//                if (event.key.code == sf::Keyboard::G) {
//                    showGrid = !showGrid;  // Переключение сетки
//                }
//                else if (event.key.code == sf::Keyboard::P) {
//                    isPaused = !isPaused;  // Переключение паузы
//                    if (isPaused) {
//                        statusText.setString("Paused");
//                    }
//                }
//                else if (event.key.code == sf::Keyboard::R) {
//                    initWorld(world);  // Перезапуск игры
//                    isPaused = false;
//                    optimalDetected = false;
//                    statusText.setString("");
//                }
//            }
//        }
//        // Если пауза не активна и интервал прошел, обновляем мир
//        if (!isPaused && clock.getElapsedTime() >= updateInterval) {
//            clock.restart();
//
//            prevWorld = world;
//            updateWorld(world, prevWorld);
//
//            if (worldsAreEqual(world, prevWorld)) {
//                statusText.setString("Optimal configuration detected");
//                optimalDetected = true;
//            }
//
//            // Проверка на отсутствие живых клеток
//            bool allDead = true;
//            for (const auto& row : world) {
//                for (const auto& cell : row) {
//                    if (cell.is_live) {
//                        allDead = false;
//                        break;
//                    }
//                }
//                if (!allDead) break;
//            }
//
//            if (allDead) {
//                statusText.setString("All points died");
//                optimalDetected = true;
//            }
//        }
//    }
//    return 0;
//}










        //#include <SFML/Graphics.hpp>
        //int main()
        //{
        //    sf::RenderWindow
        //        window(sf::VideoMode(400, 400), "block");
        //
        //    const int cellSize = 80;
        //    const int gridSize = 5;
        //
        //    sf::RectangleShape cells[gridSize][gridSize];
        //
        //    for (int i = 0; i < gridSize; ++i)
        //    {
        //        for (int j = 0; j < gridSize; ++j)
        //        {
        //            cells[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2));
        //            cells[i][j].setPosition(i * cellSize, j * cellSize);
        //            cells[i][j].setFillColor(sf::Color::Black);
        //            cells[i][j].setOutlineColor(sf::Color::White);
        //            cells[i][j].setOutlineThickness(1);
        //
        //        }
        //
        //
        //        while (window.isOpen())
        //        {
        //            sf::Event event;
        //            while (window.pollEvent(event))
        //            {
        //                if (event.type == sf::Event::Closed)
        //                    window.close();
        //            }
        //            window.clear(sf::Color::White);
        //            for (int i = 0; i < gridSize; ++i) {
        //                for (int j = 0; j < gridSize; ++j) {
        //                    window.draw(cells[i][j]);
        //                }
        //            }
        //            window.display();
        //
        //            return 0;
        //
        //
        //
        //
        //
        //        }
        //
        //
        //    }
        //
    