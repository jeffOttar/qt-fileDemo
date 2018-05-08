#include "mainview.h"
#include "ui_mainview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QFile>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    loadPhrases();//read the vector and file

    auto vlmain = new QVBoxLayout(ui->centralWidget);//QVBoxLayout* vlmain
    QHBoxLayout* hlmain = new QHBoxLayout();
    vlmain->addLayout(hlmain);//putting horizontal layout into vertical layout

    QPushButton* newPhraseBtn = new QPushButton();
    newPhraseBtn->setText("New Phrase");
    connect(newPhraseBtn,
            &QPushButton::clicked,
            this,
            &MainView::onClick
            );

    hlmain->addWidget(newPhraseBtn);


    displayPhrase = new QLabel();
    vlmain->addWidget(displayPhrase);
    displayPhrase->setText(phrases[qrand() % phrases.size()]);

}

MainView::~MainView()
{
    delete ui;
}

void MainView::onClick()
{
    displayPhrase->setText(phrases[qrand() % phrases.size()]);
}

void MainView::loadPhrases()
{
    QFile iFile(":/text/phrases.txt");
    if(!iFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Error opening file\n";
        exit(EXIT_FAILURE);
    }

    QTextStream in(&iFile);//make a textstream with ifiles address in it

    QString line = in.readLine();//read 1 line
    while(!in.atEnd())//test for end of file
    {
        phrases.push_back(line);
        line = in.readLine();
    }
}
