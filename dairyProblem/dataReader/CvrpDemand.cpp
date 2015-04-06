#include "CvrpDemand.h"

namespace Vrp
{

QDebug operator<<(QDebug cout, const CvrpDemand& p_node)
{
    return cout << "Index: " << p_node.index << ", demand: " << p_node.demand;
}

} // namespace Vrp
