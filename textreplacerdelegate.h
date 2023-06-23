#ifndef TEXTREPLACERDELEGATE_H
#define TEXTREPLACERDELEGATE_H

#include <QItemDelegate>
#include <QPainter>

class TextReplacerDelegate : public QItemDelegate
{
public:
    explicit TextReplacerDelegate(int type, QObject * parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;
private:
    int wd_type;
};

#endif // TEXTREPLACERDELEGATE_H
