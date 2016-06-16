#ifndef FILTER_H
#define FILTER_H

#include <QDialog>
#include <QLineEdit>

#include <QFile>        // для работы с файлами
#include <QTextStream>
#include <QStringList>
#include <QLabel>

#include <QTimer>
#include <QTextDocument>
#include <QTreeWidgetItem> // для вывода списка фильтров
#include <QStatusBar>

#include "dfrssfilter.h"
#include "settings.h"

struct filters_struct
{
    QString title;
    QString feed;
    bool is_on;
};

extern QList<filters_struct> filters;


namespace Ui {
class filter;
}

class Filter : public QDialog
{
    Q_OBJECT

public:
    explicit Filter(QWidget *parent = 0);
    ~Filter();
    QString encodeEntities(const QString& src, const QString& force = QString());
    void read_filters();
    void write_filters();
    void show_filters(QTreeWidget *treewidget, QList<filters_struct> values);
    void save_checked(QTreeWidget *treewidget);

public slots:
    void add_filter();
    void del_filter();
    void set_filters_header_label();
    void check_all();
    void uncheck_all();

private:
    Ui::filter *ui;
    QLineEdit *lineEdit;
    QLabel *filter_hint, *choice_hint;
    QTreeWidget *filers_list;
    settings * sett;

private slots:
    void closeEvent(QCloseEvent *);
};

#endif // FILTER_H
