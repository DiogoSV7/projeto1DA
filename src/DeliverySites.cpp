#include "../includes/DeliverySites.h"

/**
 * @brief Constructs a new DeliverySites object with the given parameters.
 *
 * @param city_name The name of the city associated with the delivery site.
 * @param id The ID of the delivery site.
 * @param code The code of the delivery site.
 * @param demand The demand of the delivery site.
 * @param population The population associated with the delivery site.
 *
 * @complexity Time Complexity: O(1)
 */
DeliverySites::DeliverySites(std::string city_name, int id, std::string code, double demand, std::string population)
        : city_name_(std::move(city_name)), id_(id), code_(std::move(code)), demand_(demand), population_(std::move(population)) {}

/**
 * @brief Retrieves the name of the city associated with the delivery site.
 *
 * @return The name of the city.
 *
 * @complexity Time Complexity: O(1)
 */
const std::string DeliverySites::getCityName() const {
    return city_name_;
}

/**
 * @brief Retrieves the code of the delivery site.
 *
 * @return The code of the delivery site.
 *
 * @complexity Time Complexity: O(1)
 */
const std::string DeliverySites::getCode() const {
    return code_;
}

/**
 * @brief Retrieves the ID of the delivery site.
 *
 * @return The ID of the delivery site.
 *
 * @complexity Time Complexity: O(1)
 */
const int DeliverySites::getId() const {
    return id_;
}

/**
 * @brief Retrieves the demand of the delivery site.
 *
 * @return The demand of the delivery site.
 *
 * @complexity Time Complexity: O(1)
 */
const double DeliverySites::getDemand() const {
    return demand_;
}

/**
 * @brief Retrieves the population associated with the delivery site.
 *
 * @return The population of the delivery site.
 *
 * @complexity Time Complexity: O(1)
 */
const std::string DeliverySites::getPopulation() const {
    return population_;
}

/**
 * @brief Checks if two DeliverySites objects are equal.
 *
 * @param other The other DeliverySites object to compare.
 * @return True if the two objects are equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool DeliverySites::operator==(const DeliverySites& other) const {
    return id_ == other.id_ && city_name_ == other.city_name_ && code_ == other.code_ && demand_ == other.demand_ && population_ == other.population_;
}

/**
 * @brief Checks if two DeliverySites objects are not equal.
 *
 * @param other The other DeliverySites object to compare.
 * @return True if the two objects are not equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool DeliverySites::operator!=(const DeliverySites& other) const {
    return !(*this == other);
}
