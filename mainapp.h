#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>
#include "matrix.h"
#include <memory>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainApp; }
QT_END_NAMESPACE

class MainApp : public QMainWindow
{
private:
    Q_OBJECT
    Ui::MainApp* ui;
    mx::MatrixNd m_A;
    mx::MatrixNd m_B;

public:
    MainApp(QWidget* parent = nullptr);
    ~MainApp();
    void log(std::string msg);
    void setError(std::string msg);
    void setOutput(std::string msg, const mx::MatrixNd& out);

private slots:
    void setA();
    void setB();
    void add();
    void subs();
};
#endif // MAINAPP_H
