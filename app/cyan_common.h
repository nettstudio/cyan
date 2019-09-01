/*
#
# Cyan <https://cyan.fxarena.net>
# Copyright Ole-André Rodlie, FxArena DA.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
*/

#ifndef CYAN_COMMON_H
#define CYAN_COMMON_H

#include <QObject>
#include <QMap>
#include <QDateTime>
#include <QMenu>
#include <QPair>

#include <list>
#include <lcms2.h>
#include <Magick++.h>

#ifdef WITH_FFMPEG
extern "C" {
#include <libavutil/avutil.h>
#include <libavutil/imgutils.h>
#include <libavdevice/avdevice.h>
#include <libswscale/swscale.h>
}
#endif

//#include "cyan_tileitem.h"


/*
// project
#define CYAN_PROJECT "cyan-project"
#define CYAN_PROJECT_VERSION 1

// common layer
#define CYAN_LAYER "cyan-layer"
#define CYAN_LAYER_VERSION 1
#define CYAN_LAYER_VISIBILITY "cyan-visibility"
#define CYAN_LAYER_OPACITY "cyan-opacity"
#define CYAN_LAYER_COMPOSE "cyan-compose"
#define CYAN_LAYER_X "cyan-layer-x"
#define CYAN_LAYER_Y "cyan-layer-y"
#define CYAN_LAYER_ORDER "cyan-layer-order"
#define CYAN_LAYER_LOCK "cyan-layer-lock"
#define CYAN_LAYER_LABEL "cyan-layer-label"

// text layer
#define CYAN_LAYER_TEXT_HTML "cyan-layer-text-html"
#define CYAN_LAYER_TEXT_PANGO "cyan-layer-text-pango"
#define CYAN_LAYER_TEXT_ALIGN "cyan-layer-text-align"
#define CYAN_LAYER_TEXT_ROTATE "cyan-layer-text-rotate"*/

class CyanCommon: public QObject
{
    Q_OBJECT

public:

    /*struct QPairSortFirst
    {
        template<typename T1, typename T2>
        bool operator()(const QPair<T1,T2> & a, const QPair<T1,T2> & b) const
        {
            return a.first < b.first;
        }
    };

    enum MoveLayer {
        MoveLayerUp,
        MoveLayerDown,
        MoveLayerLeft,
        MoveLayerRight
    };*/

    enum ICCTag {
        ICCDescription,
        ICCManufacturer,
        ICCModel,
        ICCCopyright
    };

    enum Colorspace
    {
        NoColorspace,
        RGBColorspace,
        CMYKColorspace,
        GRAYColorspace
    };

    enum newDialogType
    {
        newImageDialogType,
        newLayerDialogType
    };

    enum RenderingIntent
    {
        UndefinedRenderingIntent,
        SaturationRenderingIntent,
        PerceptualRenderingIntent,
        AbsoluteRenderingIntent,
        RelativeRenderingIntent
    };

    /*struct Tile
    {
        TileItem *rect;
    };

    struct Layer
    {
        Magick::Image image;
        QMap<int, CyanCommon::Layer> layers;
        Magick::CompositeOperator composite = Magick::OverCompositeOp;
        QSize pos = QSize(0, 0);
        bool visible = true;
        bool locked = false;
        double opacity = 1.0;
        QString label = QObject::tr("New Layer");
        int order = -1;
        QString text;
        bool isText = false;
        QString textAlign;
        int textRotate = 0;
    };

    struct Canvas
    {
        Magick::Image image;
        QMap<int, CyanCommon::Layer> layers;
        QString error;
        QString warning;
        QString label = QObject::tr("New Image");
        QMap<int, CyanCommon::Tile> tiles;
        QSize tileSize;
        QColor brushColor;
        bool brushAA = true;
        Magick::LineCap brushLineCap = Magick::RoundCap;
        Magick::LineJoin brushLineJoin = Magick::MiterJoin;
        QString timestamp;
        Magick::Blob profile;
    };*/

    CyanCommon(QObject *parent = nullptr);

    //static QString timestamp();


    static const QString canvasWindowTitle(Magick::Image image);

    static int getDiskResource();
    static void setDiskResource(int gib);

    static int getMemoryResource();
    static void setMemoryResource(int gib);

    static void setThreadResources(int thread);


    static QStringList getColorProfilesPath();
    static QMap<QString, QString> getColorProfiles(Magick::ColorspaceType colorspace);

    static Magick::ColorspaceType getProfileColorspace(const QString &filename);
    static Magick::ColorspaceType getProfileColorspace(cmsHPROFILE profile);

    static const QString getProfileTag(Magick::Blob buffer,
                                       CyanCommon::ICCTag tag = CyanCommon::ICCDescription);
    static const QString getProfileTag(const QString filename,
                                       CyanCommon::ICCTag tag = CyanCommon::ICCDescription);
    static const QString getProfileTag(cmsHPROFILE profile,
                                       CyanCommon::ICCTag tag = CyanCommon::ICCDescription);


    static const QString humanFileSize(float num,
                                       bool mp = false,
                                       bool are = false);



#ifdef WITH_FFMPEG
    static QByteArray getEmbeddedCoverArt(const QString &filename);
    static int getVideoMaxFrames(const QString &filename);
    static Magick::Image getVideoFrame(const QString &filename,
                                       int frame = 0);
#endif
};

#endif // CYANCOMMON_H