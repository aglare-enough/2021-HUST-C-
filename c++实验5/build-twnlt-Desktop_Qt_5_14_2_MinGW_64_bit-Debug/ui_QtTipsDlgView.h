/********************************************************************************
** Form generated from reading UI file 'QtTipsDlgView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTIPSDLGVIEW_H
#define UI_QTTIPSDLGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_QtTipsDlgView
{
public:
    QLabel *labelMsg;

    void setupUi(QDialog *QtTipsDlgView)
    {
        if (QtTipsDlgView->objectName().isEmpty())
            QtTipsDlgView->setObjectName(QString::fromUtf8("QtTipsDlgView"));
        QtTipsDlgView->resize(325, 27);
        QtTipsDlgView->setMaximumSize(QSize(325, 27));
        labelMsg = new QLabel(QtTipsDlgView);
        labelMsg->setObjectName(QString::fromUtf8("labelMsg"));
        labelMsg->setGeometry(QRect(10, 0, 311, 20));
        labelMsg->setMaximumSize(QSize(311, 20));

        retranslateUi(QtTipsDlgView);

        QMetaObject::connectSlotsByName(QtTipsDlgView);
    } // setupUi

    void retranslateUi(QDialog *QtTipsDlgView)
    {
        QtTipsDlgView->setWindowTitle(QCoreApplication::translate("QtTipsDlgView", "QtTipsDlgView", nullptr));
        labelMsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtTipsDlgView: public Ui_QtTipsDlgView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTIPSDLGVIEW_H
