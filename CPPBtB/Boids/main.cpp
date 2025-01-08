#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "boid.h"

// Forward declare functions to be used in main
sf::Vector2f Cohesion(boid bj);
sf::Vector2f Seperation(boid bj);
sf::Vector2f Alignment(boid bj);
sf::Vector2f BoundPosition(boid bj);

//list with boids
std::vector<boid> boids;
sf::RenderWindow window(sf::VideoMode(500, 500), "Boiding");
 
int main()
{

    //modern random number generator C++11 <
    std::random_device rd; //non-deterministic number generator
    std::mt19937 gen(rd()); //Mersenne Twister pseudo-random number generator that takes rd() as a seed
    std::uniform_real_distribution<float> positionDist(0.f, 500.f);
    std::uniform_real_distribution<float> velocityDist(-0.01f, 0.01f);

    for (int i = 0; i < 50; ++i) {
        sf::Vector2f startPosition(positionDist(gen), positionDist(gen));
        sf::Vector2f startVelocity(velocityDist(gen), velocityDist(gen));
        boids.emplace_back(startPosition, startVelocity);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //update boids
        for (auto& boi : boids)
        {
            sf::Vector2f v1 = Cohesion(boi);
            sf::Vector2f v2 = Seperation(boi);
            sf::Vector2f v3 = Alignment(boi);
            sf::Vector2f v4 = BoundPosition(boi);

            float maxSpeed = 1.0f;  // The maximum speed for the boids
            boi.velocity += v1 + v2 + v3 + v4;

            // Limit the speed of the boid
            float length = std::sqrt(boi.velocity.x * boi.velocity.x + boi.velocity.y * boi.velocity.y);
            if (length > maxSpeed) 
            {
                boi.velocity = boi.velocity / length * maxSpeed;  // Normalize and apply max speed
            }

            boi.position += boi.velocity;

            boi.update();
            boi.draw(window);
        }

        window.display();
    }

    return 0;
}

sf::Vector2f Cohesion(boid bj)
{
    //PROCEDURE rule1(boid bj)
    sf::Vector2f pcJ (0.f, 0.f);

    for (auto& boi : boids)
    {
        if (&boi != &bj)
        {
            pcJ += boi.position;
        }
    }

    pcJ = pcJ / static_cast<float> (boids.size() - 1);

    return(pcJ - bj.position) * 0.1f;
    //END PROCEDURE
}

sf::Vector2f Seperation(boid bj)
{
    //PROCEDURE rule2(boid bj)

    sf::Vector2f c (0.f, 0.f);

    for (auto& boi : boids)
    {
        if (&boi != &bj)
        {
            sf::Vector2f dif = boi.position - bj.position;

            float dis = std::sqrt(dif.x * dif.x + dif.y * dif.y);


            if (dis < 30.f) 
            {
                c -= dif;
            }
        }
    }

    return c;
    //END PROCEDURE
}

sf::Vector2f Alignment(boid bj)
{
    //PROCEDURE rule3(boid bj)
    sf::Vector2f pvJ(0.f, 0.f);

    for (auto& boi : boids) 
    {
        if (&boi != &bj)
        {
            pvJ += boi.velocity;
        }
    }

    pvJ = pvJ / static_cast<float> (boids.size() - 1);

    return(pvJ - bj.velocity) * 0.125f; // /8
    //END PROCEDURE
}

sf::Vector2f BoundPosition(boid bj) 
{
    // Boundary correction procedure
    sf::Vector2f v(0.f, 0.f);
    float boundaryForce = 1.f; // Strength of the boundary force

    if (bj.position.x < 0) {
        v.x = boundaryForce;
    }
    else if (bj.position.x > window.getSize().x) {
        v.x = -boundaryForce;
    }

    if (bj.position.y < 0) {
        v.y = boundaryForce;
    }
    else if (bj.position.y > window.getSize().y) {
        v.y = -boundaryForce;
    }

    return v;
    //END PROCEDURE
}