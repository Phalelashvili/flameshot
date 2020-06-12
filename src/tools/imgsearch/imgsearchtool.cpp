// Copyright(c) 2017-2019 Alejandro Sirgo Rica & Contributors
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

#include "imgsearchtool.h"
#include "imgsearch.h"
#include <QPainter>

ImgSearchTool::ImgSearchTool(QObject *parent) : AbstractActionTool(parent) {

}

bool ImgSearchTool::closeOnButtonPressed() const {
    return true;
}

QIcon ImgSearchTool::icon(const QColor &background, bool inEditor) const {
    Q_UNUSED(inEditor);
    return QIcon(iconPath(background) + "google.svg");
}
QString ImgSearchTool::name() const {
    return tr("Reverse Image Search");
}

QString ImgSearchTool::nameID() {
    return QLatin1String("");
}

QString ImgSearchTool::description() const {
    return tr("Search by Image on Google");
}

QWidget* ImgSearchTool::widget() {
    return new ImgSearch(capture);
}

CaptureTool* ImgSearchTool::copy(QObject *parent) {
    return new ImgSearchTool(parent);
}

void ImgSearchTool::pressed(const CaptureContext &context) {
    capture = context.selectedScreenshotArea();
    emit requestAction(REQ_CAPTURE_DONE_OK);
    emit requestAction(REQ_ADD_EXTERNAL_WIDGETS);
}
