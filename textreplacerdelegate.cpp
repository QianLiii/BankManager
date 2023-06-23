#include "textreplacerdelegate.h"

TextReplacerDelegate::TextReplacerDelegate(int type, QObject* parent):
    QItemDelegate(parent),
    wd_type(type)
{

}
void TextReplacerDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        int col = index.column();

        QColor whi(255,255,255), blk(0,0,0);
//                选中设置
        if (option.state & QStyle::State_Selected)
        {
        //    选中时设置背景色，更改文字颜色为白色
            painter->fillRect(option.rect, option.palette.highlight());
            painter->setPen(whi);
        }
        else
        {
            painter->setPen(blk);
        }

//        fund
        if(wd_type == 0)
        {
//            type
            if(col == 2)
            {
                QString text;
                if(index.data().toBool())
                {
                    text = "股份基金";
                }
                else
                {
                    text = "货币基金";
                }

                painter->drawText(option.rect, Qt::AlignVCenter, text);
            }
//            risk
            else if(col == 3)
            {
                QString text;
                if(index.data().toUInt() == 1)
                {
                    text = "非常低";
                }
                else if(index.data().toUInt() == 2)
                {
                    text = "低";
                }
                else if(index.data().toUInt() == 3)
                {
                    text = "中";
                }
                else if(index.data().toUInt() == 4)
                {
                    text = "高";
                }
                else
                {
                    text = "非常高";
                }
                painter->drawText(option.rect, Qt::AlignVCenter, text);
            }
//            other
            else
            {
                QItemDelegate::paint(painter, option, index);
            }
        }
//        insurance
        else if(wd_type == 1)
        {
//            crowd
            if(col == 2)
            {
                QString text;
                if(index.data().toUInt() == 1)
                {
                    text = "全部人群";
                }
                else if(index.data().toUInt() == 2)
                {
                    text = "青少年";
                }
                else if(index.data().toUInt() == 3)
                {
                    text = "成年人";
                }
                else
                {
                    text = "老年客户";
                }
                painter->drawText(option.rect, Qt::AlignVCenter, text);
            }
//            type
            else if(col == 3)
            {
                QString text;
                if(index.data().toString() == "WEALTH")
                {
                    text = "财产保险";
                }
                else
                {
                    text = "健康保险";
                }
                painter->drawText(option.rect, Qt::AlignVCenter, text);
            }
//            other
            else
            {
                QItemDelegate::paint(painter, option, index);
            }
        }
//        assets inspect
        else if(wd_type == 10)
        {
//            status
            if(col == 2)
            {
                QString text;
                if(index.data().toBool())
                {
                    text = "正常";
                }
                else
                {
                    text = "冻结";
                }
                painter->drawText(option.rect, Qt::AlignVCenter, text);
            }
//            other
            else
            {
                QItemDelegate::paint(painter, option, index);
            }
        }
//        other tables
        else
        {
            QItemDelegate::paint(painter, option, index);
        }
    }

void TextReplacerDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    QItemDelegate::setModelData(editor, model, index);
}
