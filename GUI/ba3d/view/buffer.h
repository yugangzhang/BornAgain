//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/view/buffer.h
//! @brief     Defines Buffer class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI_BA3D_VIEW_BUFFER_H
#define BORNAGAIN_GUI_BA3D_VIEW_BUFFER_H

#include "GUI/ba3d/def.h"
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>

namespace RealSpace {

class Geometry;

// GL buffer
class Buffer final : protected QOpenGLFunctions {
public:
    Buffer(Geometry const&);
    void draw();

private:
    int m_vertexCount;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_glBuffer;
};

// Buffer for drawing 3D Coordinate Axes on canvas
class Buffer3DAxes final : protected QOpenGLFunctions {
public:
    Buffer3DAxes();
    void draw3DAxes();

private:
    int m_vertexCount3DAxes;
    QOpenGLVertexArrayObject m_vao3DAxes;
    QOpenGLBuffer m_glBuffer3DAxes;
};

} // namespace RealSpace
#endif // BORNAGAIN_GUI_BA3D_VIEW_BUFFER_H
