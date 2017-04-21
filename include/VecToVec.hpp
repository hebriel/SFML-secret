#ifndef VECTOVEC_HPP_INCLUDED
#define VECTOVEC_HPP_INCLUDED

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "vector2.h"

/**CHUNK OF CODE MEANT TO CONVERT Bl4ckb0ne's Vector2<T> TO SFML's Vector2<T> AND VICE-VERSA**/

template <typename T>
sf::Vector2<T> toSfVector(const Vector2<T> &vec)
{
    return sf::Vector2<T>(vec.x, vec.y);
}

template <typename T>
Vector2<T> toVector(const sf::Vector2<T> &vec)
{
    Vector2<T> _temp(vec.x, vec.y);
    return _temp;
}

/**CHUNK OF CODE MEANT TO CONVERT Bl4ckb0ne's Edges TO SFML's VertexArray**/

sf::VertexArray toVertexArray(const Edge &edge, const sf::Color &color = sf::Color::White)
{
    sf::VertexArray varray(sf::Lines, 2);
    varray[0] = sf::Vertex(toSfVector(edge.p1), color);
    varray[1] = sf::Vertex(toSfVector(edge.p2), color);

    return varray;
}



#endif // VECTOVEC_HPP_INCLUDED
