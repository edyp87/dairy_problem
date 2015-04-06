#pragma once

#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <memory>

namespace Vrp
{

class CvrpFile
{
public:

    explicit CvrpFile(const QString &p_filename);
    QString readLine() const;
    bool atEnd() const;

    static QString s_descriptionSplitter;

private:
    void loadCvrpFile();

    QFile m_cvrpRawFile;
    std::unique_ptr<QTextStream> m_cvrpRawFileStream;
};

} // namespace Vrp
