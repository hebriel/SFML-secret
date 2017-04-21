
/**GRAPHICS**/

#include <SFML/Graphics.hpp> //SFML

/**STANTARD LIBS**/

#include <random> //RANDOM
#include <time.h> //TIME
#include <vector> //VECTOR

/**DELAUNAY TRIANGULATION - FORK FROM Bl4ckb0ne WORK**/

#include <vector2.h>
#include <triangle.h>
#include <delaunay.h>

/**A LIBRARY TO CONVERT SOME ORIGINAL DATA TO SFML DATA**/

#include <VecToVec.hpp>

/*---*/


int main()
{
    // Create the main window


    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    Delaunay triangulation; //TRIANGULATION IS A "Delaunay" OBJECT

    srand(time(NULL)); //SETTING RANDOM SEED

    std::vector< Vector2<float> > sites(30); //DECLARING POINTS

    for(unsigned int i = 0; i < sites.size(); ++i)
    {
        sites[i].x = rand() % 700 + 50;
        sites[i].y = rand() % 500 + 50;
    }

    triangulation.triangulate(sites);
    std::vector<Edge> edges = triangulation.getEdges();
    std::vector<sf::VertexArray> lines(edges.size());

    for(unsigned int i = 0; i < edges.size(); ++i)
    {
        lines[i] = toVertexArray(edges[i]);
    }


    sf::RectangleShape shp(sf::Vector2f(4, 4));

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        for(unsigned int i = 0; i < sites.size(); ++i)
        {
            shp.setPosition(toSfVector(Vector2<float>(sites[i])));
            app.draw(shp);
        }

        for(unsigned int i = 0; i < lines.size(); ++i)
        {
            app.draw(lines[i]);
        }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
