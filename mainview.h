#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <vector>
#include <QString>

class QLabel;

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:
    void onClick();

private:
    void loadPhrases();

private:
    Ui::MainView *ui;

    QLabel* displayPhrase;
    std::vector<QString> phrases;
};

#endif // MAINVIEW_H
