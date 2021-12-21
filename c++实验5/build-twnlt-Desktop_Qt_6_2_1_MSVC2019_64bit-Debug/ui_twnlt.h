/********************************************************************************
** Form generated from reading UI file 'twnlt.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWNLT_H
#define UI_TWNLT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_twnlt
{
public:
    QAction *action_zszc;
    QAction *action_zdjl;
    QAction *action_open;
    QAction *action_exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_Q;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *twnlt)
    {
        if (twnlt->objectName().isEmpty())
            twnlt->setObjectName(QString::fromUtf8("twnlt"));
        twnlt->resize(1045, 790);
        twnlt->setMaximumSize(QSize(1045, 790));
        twnlt->setMouseTracking(true);
        action_zszc = new QAction(twnlt);
        action_zszc->setObjectName(QString::fromUtf8("action_zszc"));
        action_zszc->setCheckable(true);
        action_zdjl = new QAction(twnlt);
        action_zdjl->setObjectName(QString::fromUtf8("action_zdjl"));
        action_zdjl->setCheckable(true);
        action_open = new QAction(twnlt);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_open->setCheckable(true);
        action_exit = new QAction(twnlt);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_exit->setCheckable(true);
        centralwidget = new QWidget(twnlt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMouseTracking(true);
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/map.png);"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        twnlt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(twnlt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1045, 21));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_Q = new QMenu(menubar);
        menu_Q->setObjectName(QString::fromUtf8("menu_Q"));
        twnlt->setMenuBar(menubar);
        statusbar = new QStatusBar(twnlt);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        twnlt->setStatusBar(statusbar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_Q->menuAction());
        menu_F->addAction(action_open);
        menu_F->addAction(action_exit);
        menu_Q->addAction(action_zszc);
        menu_Q->addAction(action_zdjl);

        retranslateUi(twnlt);

        QMetaObject::connectSlotsByName(twnlt);
    } // setupUi

    void retranslateUi(QMainWindow *twnlt)
    {
        twnlt->setWindowTitle(QCoreApplication::translate("twnlt", "\345\205\254\344\272\244\346\215\242\344\271\230", nullptr));
        action_zszc->setText(QCoreApplication::translate("twnlt", "\346\234\200\345\260\221\350\275\254\344\271\230", nullptr));
#if QT_CONFIG(tooltip)
        action_zszc->setToolTip(QCoreApplication::translate("twnlt", "\346\234\200\345\260\221\350\275\254\344\271\230", nullptr));
#endif // QT_CONFIG(tooltip)
        action_zdjl->setText(QCoreApplication::translate("twnlt", "\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        action_open->setText(QCoreApplication::translate("twnlt", "\350\257\273\345\205\245\345\234\260\345\233\276", nullptr));
        action_exit->setText(QCoreApplication::translate("twnlt", "\351\200\200\345\207\272", nullptr));
        menu_F->setTitle(QCoreApplication::translate("twnlt", "\346\226\207\344\273\266", nullptr));
        menu_Q->setTitle(QCoreApplication::translate("twnlt", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class twnlt: public Ui_twnlt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWNLT_H
