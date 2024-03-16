#ifndef PROJETO1DA_PUMPINGSTATIONS_H
#define PROJETO1DA_PUMPINGSTATIONS_H

#include <string>


class PumpingStations{
    public:
        PumpingStations()=default;
        PumpingStations(int id, std::string pumping_station_code);
        int getId() const;
        const std::string getPumpingStationCode() const;
        bool operator==(const PumpingStations& other) const;
        bool operator!=(const PumpingStations& other) const;
    private:
        int id_;
        std::string pumping_station_code_;
};

namespace std {
    template<>
    struct hash<PumpingStations> {
        size_t operator()(const PumpingStations& obj) const {
            size_t hash1 = std::hash<int>()(obj.getId());
            size_t hash2 = std::hash<std::string>()(obj.getPumpingStationCode());
            return hash1 ^ (hash2 << 1); // Combining hashes
        }
    };
}



#endif