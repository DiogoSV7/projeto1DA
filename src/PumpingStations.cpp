#include "../includes/PumpingStations.h"

/**
 * @brief Constructs a PumpingStations object with the given ID and pumping station code.
 *
 * @param id The ID of the pumping station.
 * @param pumping_station_code The code of the pumping station.
 *
 * @complexity Time Complexity: O(1)
 */
PumpingStations::PumpingStations(int id, std::string pumping_station_code)
        : id_(id), pumping_station_code_(std::move(pumping_station_code)) {}


/**
 * @brief Retrieves the ID of the pumping station.
 *
 * @return The ID of the pumping station.
 *
 * @complexity Time Complexity: O(1)
 */
int PumpingStations::getId() const {
    return id_;
}

/**
 * @brief Retrieves the code of the pumping station.
 *
 * @return The code of the pumping station.
 *
 * @complexity Time Complexity: O(1)
 */
const std::string PumpingStations::getPumpingStationCode() const {
    return pumping_station_code_;
}
/**
 * @brief Checks if two PumpingStations objects are equal.
 *
 * @param other The other PumpingStations object to compare.
 * @return True if the two objects are equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool PumpingStations::operator==(const PumpingStations& other) const {
    return id_ == other.id_ && pumping_station_code_ == other.pumping_station_code_;
}

/**
 * @brief Checks if two PumpingStations objects are not equal.
 *
 * @param other The other PumpingStations object to compare.
 * @return True if the two objects are not equal, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool PumpingStations::operator!=(const PumpingStations& other) const {
    return !(*this == other);
}
