#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    srand(time(NULL)); // initialisation de rand
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "NetMouse v0.01");
    sf::UdpSocket socket;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::IpAddress recipient = argv[1];
        sf::Packet packet;
        packet << sf::Mouse::getPosition(window).x << sf::Mouse::getPosition(window).y;
        packet << sf::Mouse::isButtonPressed(sf::Mouse::Left);
        packet << sf::Mouse::isButtonPressed(sf::Mouse::Right);
        if (socket.send(packet, recipient, 4500) != sf::Socket::Done) {
            cout << "ERROR ERRROR ERROR" << endl;
        }
    sf::sleep(sf::milliseconds(50));    }

    return 0;
}
