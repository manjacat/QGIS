/***************************************************************************
    qgsmaskingwidget.h
    ---------------------
    begin                : September 2019
    copyright            : (C) 2019 by Hugo Mercier
    email                : hugo dot mercier at oslandia dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef QGSMASKINGWIDGET_H
#define QGSMASKINGWIDGET_H

// We don't want to expose this in the public API
#define SIP_NO_FILE

#include "qgspanelwidget.h"
#include "ui_qgsmaskingwidgetbase.h"
#include "qgis_sip.h"
#include "qgis_gui.h"

/**
 * \ingroup gui
 * Main widget for the configuration of mask sources and targets.
 *
 * \note This class is not a part of public API
 * \since QGIS 3.14
 */
class GUI_EXPORT QgsMaskingWidget: public QgsPanelWidget, private Ui::QgsMaskingWidgetBase
{
    Q_OBJECT
  public:
    //! constructor
    QgsMaskingWidget( QWidget *parent = nullptr );

    //! Sets the layer to configure
    void setLayer( QgsVectorLayer *layer );

    //! Applies the changes
    void apply();

  signals:
    //! Emitted when a change is performed
    void widgetChanged();

  private:
    QgsVectorLayer *mLayer = nullptr;
    //! Populate the mask source and target widgets
    void populate();
};

#endif
