#include "../includes/Pipes.h"
using namespace std;

/**
 * @brief Constructs a new Pipes object with the given parameters.
 *
 * @param serv_site_a The name of the source service site.
 * @param serv_site_b The name of the destination service site.
 * @param capacity The capacity of the pipe.
 * @param direction If the pipe is unidirectional or bidirectional
 *
 * @complexity Time Complexity: O(1)
 *
 */
Pipes::Pipes(std::string serv_site_a, std::string serv_site_b, int capacity, int direction) {
    this->serv_point_a_ = serv_site_a;
    this->serv_point_b_ = serv_site_b;
    this->capacity_ = capacity;
    this->direction_ = direction;
}

/**
 * @brief Get the name of the source city of the pipe.
 *
 * @return The name of the source city.
 *
 * @complexity Time Complexity: O(1)
 */
const string Pipes::getCitySourceName() const {
    return serv_point_a_;
}

/**
 * @brief Get the name of the sink city of the pipe.
 *
 * @return The name of the sink city.
 *
 * @complexity Time Complexity: O(1)
 */
const string Pipes::getCitySinkName() const {
    return serv_point_b_;
}

/**
 * @brief Get the capacity of the pipe.
 *
 * @return The capacity of the pipe.
 *
 * @complexity Time Complexity: O(1)
 */
const int Pipes::getCapacity() const {
    return capacity_;
}

/**
 * @brief Get the direction of the pipe.
 *
 * @return 0 if the pipe is bidirectional, 1 if is unidirectional.
 *
 * @complexity Time Complexity: Time Complexity: O(1)
 */
const int Pipes::getDirection() const {
    return direction_;
}

/**
 * @brief Equality comparison operator for pipes.
 *
 * @param other The other pipe to compare.
 * @return True if the pipes are equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool Pipes::operator==(const Pipes& other) const {
    return (serv_point_a_ == other.serv_point_a_) &&
           (serv_point_b_ == other.serv_point_b_) &&
           (capacity_ == other.capacity_) &&
           (direction_ == other.direction_);
}

/**
 * @brief Inequality comparison operator for pipes.
 *
 * @param other The other pipe to compare.
 * @return True if the pipes are not equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool Pipes::operator!=(const Pipes& other) const {
    return !(*this == other);
}