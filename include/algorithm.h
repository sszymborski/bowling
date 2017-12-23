#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include "data.h"
#include "interface.h"

class algorithm
{
public:
    algorithm(data &, interface &);
    virtual ~algorithm();
protected:
private:
    std::vector< std::vector<int> > tabela;
};

#endif // ALGORITHM_H
