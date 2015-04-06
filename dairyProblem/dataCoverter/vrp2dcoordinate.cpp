#include <dataCoverter/vrp2dcoordinate.h>

namespace Vrp
{

QDebug operator<<(QDebug cout, const Vrp2dCoordinate& p_node)
{
    return cout << "Index: " << p_node.index << ", x: " << p_node.x << ", y: " << p_node.y << ".";
}

} // namespace Vrp
