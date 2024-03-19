

#include "includes/Menu.h"


int main() {


    Data d;
    d.edmondsKarp("SuperSource","SuperSink");
    std::cout << d.computePipeMaxDif() << " " << d.computePipeDifVar() << " " << d.computeAvgPipeDif() << std::endl;
    return 0;
}
