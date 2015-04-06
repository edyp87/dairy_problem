#include "vrpdemand.h"

namespace Vrp
{

QDebug operator<<(QDebug cout, const VrpDemand& p_node)
{
    return cout << "Index: " << p_node.index << ", demand: " << p_node.demand;
}

} // namespace Vrp
