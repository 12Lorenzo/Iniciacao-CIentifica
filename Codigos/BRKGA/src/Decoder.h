#ifndef DECODER_H
#define DECODER_H

#include "SampleDecoder.h"
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include "Instancia.h"

class Decoder{

public:
    Decoder();
    ~Decoder();
    double decode(const std::vector< double >& chromosome) const;
    void ordena(vector<tuple<int, double, double, float>> cromossomo);

private:

};

#endif