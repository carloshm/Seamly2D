/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2017  Seamly, LLC                                       *
 *                                                                         *
 *   http://github.com/fashionfreedom/seamly2d                             *
 *                                                                         *
 ***************************************************************************
 **
 **  Seamly2D is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Seamly2D is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Seamly2D.  If not, see <http://www.gnu.org/licenses/>.
 **
 **************************************************************************

 ************************************************************************
 **
 **  @file   visline.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   21 7, 2014
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://github.com/valentina-project/vpo2> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef VISLINE_H
#define VISLINE_H

#include <qcompilerdetection.h>
#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QLineF>
#include <QMetaObject>
#include <QObject>
#include <QPointF>
#include <QString>
#include <Qt>
#include <QtGlobal>

#include "../vtools/visualization/visualization.h"
#include "../vmisc/def.h"
#include "../vwidgets/scalesceneitems.h"

class VisLine: public Visualization, public VScaledLine
{
    Q_OBJECT
public:
    explicit VisLine(const VContainer *data, QGraphicsItem *parent = nullptr);
    virtual ~VisLine() = default;

    virtual int  type() const Q_DECL_OVERRIDE {return Type;}
    enum { Type = UserType + static_cast<int>(Vis::Line)};
    static qreal CorrectAngle(const qreal &angle);
protected:
    QPointF      Ray(const QPointF &firstPoint, const qreal &angle) const;
    QPointF      Ray(const QPointF &firstPoint) const;
    QLineF       Axis(const QPointF &p, const qreal &angle) const;
    QLineF       Axis(const QPointF &p1, const QPointF &p2) const;
    virtual void InitPen() Q_DECL_OVERRIDE;
    virtual void AddOnScene() Q_DECL_OVERRIDE;

    void         DrawRay(VScaledLine *lineItem, const QPointF &p, const QPointF &pTangent,
                         const QColor &color, Qt::PenStyle style);
private:
    Q_DISABLE_COPY(VisLine)
};

#endif // VISLINE_H
