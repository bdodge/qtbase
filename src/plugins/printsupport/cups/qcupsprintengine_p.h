/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QCUPSPRINTENGINE_P_H
#define QCUPSPRINTENGINE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "QtPrintSupport/qprintengine.h"

#ifndef QT_NO_PRINTER

#include <QtCore/qstring.h>
#include <QtGui/qpaintengine.h>

#include <private/qpaintengine_p.h>
#include <private/qprintengine_pdf_p.h>
#include <QtPrintSupport/qprintengine.h>
#include <private/qcups_p.h>

QT_BEGIN_NAMESPACE

class QCupsPrintEnginePrivate;

class QCupsPrintEngine : public QPdfPrintEngine
{
    Q_DECLARE_PRIVATE(QCupsPrintEngine)
public:
    QCupsPrintEngine(QPrinter::PrinterMode m);
    virtual ~QCupsPrintEngine();

    // reimplementations QPdfPrintEngine
    void setProperty(PrintEnginePropertyKey key, const QVariant &value);
    QVariant property(PrintEnginePropertyKey key) const;
    // end reimplementations QPdfPrintEngine

private:
    Q_DISABLE_COPY(QCupsPrintEngine)
};

class QCupsPrintEnginePrivate : public QPdfPrintEnginePrivate
{
    Q_DECLARE_PUBLIC(QCupsPrintEngine)
public:
    QCupsPrintEnginePrivate(QPrinter::PrinterMode m);
    ~QCupsPrintEnginePrivate();

    bool openPrintDevice();
    void closePrintDevice();

    void updatePaperSize();

private:
    Q_DISABLE_COPY(QCupsPrintEnginePrivate)

    QStringList cupsOptions;
    QString cupsStringPageSize;
    QRect cupsPaperRect;
    QRect cupsPageRect;
    QString cupsTempFile;
};

QT_END_NAMESPACE

#endif // QT_NO_PRINTER

#endif // QCUPSPRINTENGINE_P_H
