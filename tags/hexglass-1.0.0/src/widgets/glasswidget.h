/****
    * HexGlass is a Tetris-like puzzle game.
    *
    * Copyright (C) 2010 Alexey Michurin
    *
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 3 of the License, or
    * (at your option) any later version.
    *
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    * GNU General Public License for more details.
    *
    * You should have received a copy of the GNU General Public License
    * along with this program. If not, see <http://www.gnu.org/licenses/>.
*****/

#ifndef SRC_WIDGETS_GLASSWIDGET_H
#define SRC_WIDGETS_GLASSWIDGET_H

#include "skin.h"

#include <QWidget>
#include <QPixmap>

class QPaintEvent;
class Configuration;
class QMouseEvent;
class QTimerEvent;

class GlassWidget : public QWidget {

Q_OBJECT

private:
    Skin skin;
    int glass_width;
    int glass_height;
    int * glass_body;
    int cursor_hide_timer;
    bool show_paused_label;

private:
    void regeometry();
    void touch_mouse();

protected:
    void paintEvent(QPaintEvent * event);

    void mouseDoubleClickEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void timerEvent(QTimerEvent * event);

public:
    GlassWidget(QWidget * parent = 0);
    ~GlassWidget();

public slots:
    void hex_size(int, int);
    void hex_update(int, int, int); // l, r, id
    void set_skin(const Skin &);
    void set_paused_mode(bool);

signals:
    void start_game(); // field ready, start game
};

#endif // SRC_WIDGETS_GLASSWIDGET_H
