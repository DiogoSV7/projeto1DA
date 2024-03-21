#include <string>
#include <utility>
#include "../includes/WaterReservoir.h"
using namespace std;


/**
 * @brief Constructs a WaterReservoir object with the given parameters.
 *
 * @param water_reservoir_name The name of the water reservoir.
 * @param municipality The municipality where the water reservoir is located.
 * @param id The ID of the water reservoir.
 * @param code The code of the water reservoir.
 * @param max_delivery The maximum delivery capacity of the water reservoir.
 *
 * @complexity Time Complexity: O(1)
 */
WaterReservoir::WaterReservoir(string water_reservoir_name, string municipality, int id, string code, int max_delivery){
    this->water_reservoir_name_=std::move(water_reservoir_name);
    this->municipality_=std::move(municipality);
    this->code_=std::move(code);
    this->id_=id;
    this->max_delivery_=max_delivery;
}

/**
 * @brief Retrieves the name of the water reservoir.
 *
 * @return The name of the water reservoir.
 *
 * @complexity Time Complexity: O(1)
 */
const string WaterReservoir::getWaterReservoirName() const {
    return water_reservoir_name_;
}

/**
 * @brief Retrieves the municipality where the water reservoir is located.
 *
 * @return The municipality of the water reservoir.
 *
 * @complexity Time Complexity: O(1)
 */
const string WaterReservoir::getMunicipality() const {
    return municipality_;
}


/**
 * @brief Retrieves the code of the water reservoir.
 *
 * @return The code of the water reservoir.
 *
 * @complexity Time Complexity: O(1)
 */
const string WaterReservoir::getCode() const {
    return code_;
}

/**
 * @brief Retrieves the ID of the water reservoir.
 *
 * @return The ID of the water reservoir.
 *
 * @complexity Time Complexity: O(1)
 */
const int WaterReservoir::getId() const {
    return id_;
}

/**
 * @brief Retrieves the maximum delivery capacity of the water reservoir.
 *
 * @return The maximum delivery capacity of the water reservoir.
 *
 * @complexity Time Complexity: O(1)
 */
const int WaterReservoir::getMaxDelivery() const {
    return max_delivery_;
}

/**
 * @brief Checks if two WaterReservoir objects are equal based on their codes.
 *
 * @param other The other WaterReservoir object to compare.
 * @return True if the two objects are equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool WaterReservoir::operator==(const WaterReservoir& other) const {
    return code_ == other.code_;
}

/**
 * @brief Checks if two WaterReservoir objects are not equal based on their codes.
 *
 * @param other The other WaterReservoir object to compare.
 * @return True if the two objects are not equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool WaterReservoir::operator!=(const WaterReservoir& other) const {
    return !(*this == other);
}
