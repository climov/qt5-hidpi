/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtQuick module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSGTEXTUREMATERIAL_H
#define QSGTEXTUREMATERIAL_H

#include <QtQuick/qsgmaterial.h>
#include <QtQuick/qsgtexture.h>
#include <QPointer>

QT_BEGIN_NAMESPACE

class Q_QUICK_EXPORT QSGOpaqueTextureMaterial : public QSGMaterial
{
public:
    QSGOpaqueTextureMaterial();

    virtual QSGMaterialType *type() const;
    virtual QSGMaterialShader *createShader() const;
    virtual int compare(const QSGMaterial *other) const;

    void setTexture(QSGTexture *texture);
    QSGTexture *texture() const { return m_texture.data(); }

    void setMipmapFiltering(QSGTexture::Filtering filteringType) { m_mipmap_filtering = filteringType; }
    QSGTexture::Filtering mipmapFiltering() const { return QSGTexture::Filtering(m_mipmap_filtering); }

    void setFiltering(QSGTexture::Filtering filteringType) { m_filtering = filteringType; }
    QSGTexture::Filtering filtering() const { return QSGTexture::Filtering(m_filtering); }

    void setHorizontalWrapMode(QSGTexture::WrapMode mode) { m_horizontal_wrap = mode; }
    QSGTexture::WrapMode horizontalWrapMode() const { return QSGTexture::WrapMode(m_horizontal_wrap); }

    void setVerticalWrapMode(QSGTexture::WrapMode mode) { m_vertical_wrap = mode; }
    QSGTexture::WrapMode verticalWrapMode() const { return QSGTexture::WrapMode(m_vertical_wrap); }

protected:
    QPointer<QSGTexture> m_texture;

    uint m_filtering: 2;
    uint m_mipmap_filtering: 2;
    uint m_horizontal_wrap : 1;
    uint m_vertical_wrap: 1;

    uint m_reserved : 26;
};


class Q_QUICK_EXPORT QSGTextureMaterial : public QSGOpaqueTextureMaterial
{
public:
    virtual QSGMaterialType *type() const;
    virtual QSGMaterialShader *createShader() const;
};

QT_END_NAMESPACE

#endif
