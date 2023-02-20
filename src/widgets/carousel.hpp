/*
 *   The GNU General Public License v3.0
 *
 *   Copyright (C) 2023 Yaroslav Riabtsev <yaroslav.riabtsev@rwth-aachen.de>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
*/

#ifndef YACARDCOUNTER_CAROUSEL_HPP
#define YACARDCOUNTER_CAROUSEL_HPP

// Qt
#include <QWidget>

class QHBoxLayout;

class Carousel : public QWidget {
Q_OBJECT
public:
    explicit Carousel(QSizeF aspectRatio, QWidget *parent = nullptr);

    void addWidget(QWidget *widget);

protected:
    void resizeEvent(QResizeEvent *event) override;

signals:

    void itemResized(QSize newFixedSize);

private:
    QVector<QWidget *> widgets;
    QHBoxLayout *carousel;
    QSizeF ratio;
    qint32 columnCount = 0;
    qint32 idx = 0;

    void updateProps(QSize size);

    void updateLayout(double newScale = -1);
};


#endif //YACARDCOUNTER_CAROUSEL_HPP
