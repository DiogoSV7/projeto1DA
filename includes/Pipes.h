#ifndef PROJETO1DA_PIPES_H
#define PROJETO1DA_PIPES_H

#include <string>

class Pipes{
    public:
        Pipes()=default;
        Pipes(std::string serv_point_a, std::string serv_point_b, int capacity, int direction);
        const std::string getCitySourceName() const;
        const std::string getCitySinkName() const;
        const int getCapacity() const;
        const int getDirection() const; //1-> unidirectional 0-> bidirectional
        bool operator==(const Pipes& other) const;
        bool operator!=(const Pipes& other) const;
    private:
        std::string serv_point_a_;
        std::string serv_point_b_;
        int capacity_;
        int direction_;
};

namespace std {
    template<>
    struct hash<Pipes> {
        size_t operator()(const Pipes& obj) const {
            size_t hash1 = std::hash<std::string>()(obj.getCitySourceName());
            size_t hash2 = std::hash<std::string>()(obj.getCitySinkName());
            size_t hash3 = std::hash<int>()(obj.getCapacity());
            size_t hash4 = std::hash<int>()(obj.getDirection());
            return hash1 ^ (hash2 << 1) ^ (hash3 << 2) ^ (hash4 << 3); // Combining hashes
        }
    };
}
#endif //PROJETO1DA_PIPES_H
