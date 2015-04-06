#include <dataCoverter/vrptokens.h>

namespace Utils
{

e_keywords findEnumForKeyword(QString p_keyword)
{
    for (int i = 0; i < keywordStringList.size(); ++i)
    {
        if (keywordStringList[i] == p_keyword)
        {
            return (e_keywords) i;
        }
    }
    return Utils::e_keywords::UNDEFINED;
}

} // namespace Utils
