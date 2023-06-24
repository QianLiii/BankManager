#include "textreplacerdelegate.h"

TextReplacerDelegate::TextReplacerDelegate(int type, QObject* parent):
    QItemDelegate(parent),
    wd_type(type)
{

}
void TextReplacerDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
//        蓝：enabled,selected,active灰：enabled,selected
        int col = index.column();
        int row = index.row();
        if(row == 0){qDebug()<<col<<": "<<option.state;}

        QColor whi(255,255,255), blk(0,0,0);
//                选中设置
//        选中且活跃态
        if ((option.state & (QStyle::State_Selected | QStyle::State_Active)) == (QStyle::State_Selected | QStyle::State_Active))
        {
        //    选中时设置背景色，更改文字颜色为白色
            painter->fillRect(option.rect, option.palette.highlight());
            painter->setPen(whi);
        }
        //        选中但非活跃态
        else if((option.state & QStyle::State_Selected) == QStyle::State_Selected)
        {
            painter->fillRect(option.rect, option.palette.midlight());
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
                painter->drawText(option.rect, Qt::AlignVCenter, index.data().toString());
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
                painter->drawText(option.rect, Qt::AlignVCenter, index.data().toString());
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
                painter->drawText(option.rect, Qt::AlignVCenter, index.data().toString());
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
