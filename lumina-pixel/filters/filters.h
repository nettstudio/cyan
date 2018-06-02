/*
#
# Copyright (c) 2018, Ole-André Rodlie <ole.andre.rodlie@gmail.com> All rights reserved.
#
# Available under the 3-clause BSD license
# See the LICENSE file for full details
#
*/

#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <QObject>
#include <QStringList>
#include <Magick++.h>
#include "interfaces.h"

class ImageFilters : public QObject, public FilterInterface
{
    Q_OBJECT
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        Q_PLUGIN_METADATA(IID "org.lumina-desktop.viewer.FilterInterface")
#endif
    Q_INTERFACES(FilterInterface)

public:
    QStringList filters() const;
    Magick::Image filterImage(const QString &filter, const Magick::Image &image);
private:
    Magick::Image filteredImage;
private slots:
    Magick::Image swirlImage(const Magick::Image &image);
    Magick::Image waveImage(const Magick::Image &image);
    void handleFilterDialogDone();
};

#endif