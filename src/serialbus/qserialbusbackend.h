/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialBus module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSERIALBUSBACKEND_H
#define QSERIALBUSBACKEND_H

#include <QtSerialBus/qserialbusglobal.h>
#include <QtCore/qobject.h>
#include <QtCore/qbytearray.h>

QT_BEGIN_NAMESPACE

class Q_SERIALBUS_EXPORT QSerialBusBackend : public QObject
{
    Q_OBJECT
public:
    //TODO: remove
    virtual QByteArray readAll() = 0;
    virtual QByteArray read(qint64) = 0;
    //TODO: SetConfigurationParameter?
    //TODO: (const QString &key, const QVariant &value)?
    //TODO: getConfiguration?
    virtual void setConfiguration(const QPair<QString, QVariant> &) = 0;
    //TODO: inconsistent naming.
    //TODO: Should it be (const char*, int len) instead of QByteArray;
    virtual void writeToBus(const QByteArray &) = 0;
    //TODO: better way than QDataStream to pass the information
    virtual void setDataStreamVersion(int) = 0;
    virtual int dataStreamVersion() const = 0;
    //TODO: size? bytesAvailable
    virtual qint64 size() const = 0;

Q_SIGNALS:
    void readyRead();

};

QT_END_NAMESPACE

#endif // QSERIALBUSBACKEND_H
