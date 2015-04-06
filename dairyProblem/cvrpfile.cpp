#include "cvrpfile.h"
#include <stdexcept>

QString CvrpFile::s_descriptionSplitter = ":";

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

CvrpFile::CvrpFile(const QString &p_filename)
    : m_cvrpRawFile(p_filename)
{
    loadCvrpFile();
}

void CvrpFile::loadCvrpFile()
{
    if (not m_cvrpRawFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error(std::string("Cannot open file!"));
    }
    m_cvrpRawFileStream.reset(new QTextStream(&m_cvrpRawFile));
}
