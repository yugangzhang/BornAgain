#ifndef LAYERVIEW_H
#define LAYERVIEW_H

#include "ConnectableView.h"
#include "MaterialBrowser.h"
#include "Layer.h"

//! graphics representation of Layer
class LayerView : public ConnectableView
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName )
    Q_PROPERTY(double thickness READ getThickness WRITE setThickness )
    Q_PROPERTY(MaterialProperty material READ getMaterialProperty WRITE setMaterialProperty )

public:
    enum { Type = DesignerHelper::LayerType };

    LayerView(QGraphicsItem *parent = 0);
    ~LayerView() { delete m_layer; }

    //! сalls the ISampleViewVisitor's visit method
    virtual void accept(IViewVisitor *visitor) { visitor->visit(this); }

    int type() const { return Type; }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setFixedX() { m_fixed_xpos = x(); m_fixed=true; }
    qreal getFixedX() { return m_fixed_xpos; }
    double getThickness() const { return m_layer->getThickness(); }
    MaterialProperty getMaterialProperty() const { return m_materialProperty; }

    void setLayer(Layer *layer) { delete m_layer; m_layer = layer; }
    const Layer *getLayer() { return m_layer; }

public slots:
    void setThickness(double thickness);
    void setMaterialProperty(const MaterialProperty &materialProperty);

signals:
    void LayerMoved();

protected:
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    qreal m_fixed_xpos;
    bool m_fixed;

    MaterialProperty m_materialProperty;
    Layer *m_layer;
};


inline void LayerView::setThickness(double thickness)
{
    if(thickness != m_layer->getThickness()) {
        m_layer->setThickness(thickness);
        m_rect.setHeight(DesignerHelper::nanometerToScreen(getThickness()));
        setPortCoordinates();
        emit heightChanged();
    }
}


inline void LayerView::setMaterialProperty(const MaterialProperty &materialProperty)
{
    m_materialProperty = materialProperty;
    setColor(materialProperty.getColor());
    update();
}


#endif // LAYERVIEW_H