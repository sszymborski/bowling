#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include <chrono>
#include "data.h"
#include "interface.h"

class algorithm
{
public:
    algorithm();
    virtual ~algorithm();
    void pierwszy(data &, interface &);
    void drugi(data &, interface &);
    void trzeci(data &, interface &);
protected:
private:
    std::vector< std::vector<int> > tabela;
    std::vector<int> pozostaleStarty;
    std::vector<int> pozostaleStopy;

};

#endif // ALGORITHM_H
