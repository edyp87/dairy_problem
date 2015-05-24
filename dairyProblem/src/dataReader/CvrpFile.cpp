#include "CvrpFile.h"
#include <stdexcept>

namespace Vrp
{

QString CvrpFile::s_descriptionSplitter = ":";

CvrpFile::CvrpFile(const QString &p_filename)
    : m_cvrpRawFile(p_filename)
{
    loadCvrpFile();
}

QString CvrpFile::readLine() const
{
    return m_cvrpRawFileStream->readLine();
}

bool CvrpFile::atEnd() const
{
    return m_cvrpRawFileStream->atEnd();
}


void CvrpFile::loadCvrpFile()
{
    if (not m_cvrpRawFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error(std::string("Cannot open file!"));
    }
    m_cvrpRawFileStream.reset(new QTextStream(&m_cvrpRawFile));
}

CvrpFile::~CvrpFile()
{
    m_cvrpRawFile.close();
}

} // namespace Vrp
