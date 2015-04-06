#ifndef VRPTOKENS_H
#define VRPTOKENS_H

#include <QStringList>

namespace Utils
{

enum class e_keywords
{
    NAME,
    TYPE,
    COMMENT,
    DIMENSION,
    CAPACITY,
    EDGE_WEIGHT_TYPE,
    EDGE_WEIGHT_FORMAT,
    EDGE_DATA_FORMAT,
    NODE_COORD_TYPE,
    DISPLAY_DATA_TYPE,
    NODE_COORD_SECTION,
    DEPOT_SECTION,
    DEMAND_SECTION,
    EDGE_DATA_SECTION,
    FIXED_EDGE_SECTION,
    DISPLAY_DATA_SECTION,
    TOUR_SECTION,
    EDGE_WEIGHT_SECTION,
    END,
    UNDEFINED
};

static QStringList keywordStringList {
    "NAME",
    "TYPE",
    "COMMENT",
    "DIMENSION",
    "CAPACITY",
    "EDGE_WEIGHT_TYPE",
    "EDGE_WEIGHT_FORMAT",
    "EDGE_DATA_FORMAT",
    "NODE_COORD_TYPE",
    "DISPLAY_DATA_TYPE",
    "NODE_COORD_SECTION",
    "DEPOT_SECTION",
    "DEMAND_SECTION",
    "EDGE_DATA_SECTION",
    "FIXED_EDGE_SECTION",
    "DISPLAY_DATA_SECTION",
    "TOUR_SECTION",
    "EDGE_WEIGHT_SECTION",
    "EOF",
    "UNDEFINED"
};

Utils::e_keywords findEnumForKeyword(QString p_keyword);

} // namespace Utils

#endif // VRPTOKENS_H
