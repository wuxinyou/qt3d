/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
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

#ifndef QT3DRENDER_QUICK3DSCENE2D_QSCENE2D_P_H
#define QT3DRENDER_QUICK3DSCENE2D_QSCENE2D_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <Qt3DQuickScene2D/qscene2d.h>

#include <private/qnode_p.h>
#include <private/scene2dsharedobject_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

namespace Quick {

class QScene2D;
class Scene2DManager;

// render thread -> render thread
static const QEvent::Type INITIALIZE = QEvent::Type(QEvent::User + 1);

// main thread -> main thread, render thread
static const QEvent::Type RENDER = QEvent::Type(QEvent::User + 2);

// main thread -> main thread
static const QEvent::Type RENDERSYNC = QEvent::Type(QEvent::User + 3);

// render thread -> main thread
static const QEvent::Type PREPARE = QEvent::Type(QEvent::User + 4);
static const QEvent::Type INITIALIZED = QEvent::Type(QEvent::User + 5);
static const QEvent::Type RENDERED = QEvent::Type(QEvent::User + 6);

// main thread -> render thread
static const QEvent::Type QUIT = QEvent::Type(QEvent::User + 7);


class Q_AUTOTEST_EXPORT QScene2DPrivate : public Qt3DCore::QNodePrivate
{
public:
    Q_DECLARE_PUBLIC(QScene2D)

    QScene2DPrivate();
    ~QScene2DPrivate();

    Scene2DManager *m_renderManager;
    QMetaObject::Connection m_textureDestroyedConnection;
    Qt3DRender::QRenderTargetOutput *m_output;
};

struct QScene2DData
{
    QScene2D::RenderPolicy renderPolicy;
    Scene2DSharedObjectPtr sharedObject;
    Qt3DCore::QNodeId output;
};

} // namespace Quick
} // namespace Qt3DRender

QT_END_NAMESPACE

#endif // QT3DRENDER_QUICK3DSCENE2D_QSCENE2D_P_H