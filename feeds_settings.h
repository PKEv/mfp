#ifndef FEEDS_SETTINGS_H
#define FEEDS_SETTINGS_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QStatusBar>

#include "dfrssfilter.h"
#include "settings.h"

struct feeds_struct
{
    QString title;
    QString link;
    bool is_on;
};

extern QList<feeds_struct> feeds;
void read_feeds();

namespace Ui {
class feeds_settings;
}

class feeds_settings : public QDialog
{
    Q_OBJECT

public:
    explicit feeds_settings(QWidget *parent = 0);
    ~feeds_settings();
    void show_feeds(QListWidget *listwidget, QList<feeds_struct> values);
    void read_feeds();
    void write_feeds();
    void save_checked(QListWidget *listwidget);
    void get_feed_name();

public slots:
    void add_feed();
    void del_feed();
    void set_feeds_header_label();
    void check_all();
    void uncheck_all();

private:
    Ui::feeds_settings *ui;
    QLineEdit *lineEdit;
    QLabel *feed_hint, *choice_hint;
    QListWidget *feeds_list;
    settings * sett;

private slots:
    void closeEvent(QCloseEvent *);

};

#endif // FEEDS_SETTINGS_H
