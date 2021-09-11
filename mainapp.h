#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>
#include "matrix.h"
#include <memory>
#include <string>

#pragma warning (disable : 4267)

QT_BEGIN_NAMESPACE
namespace Ui { class MainApp; }
QT_END_NAMESPACE

class MainApp : public QMainWindow
{
private:
    Q_OBJECT
    Ui::MainApp* ui;
    mx::MatrixNd matx;
public:
    MainApp(QWidget* parent = nullptr);
    ~MainApp();
    void log(std::string msg);
    void setError(std::string msg);
    void setOutput(std::string msg, arma::mat out);
    void setOutput(std::string msg, double out);

private slots:
    void setA();
    void setB();
    void add();
    void subs();
    void mulAB();
    void accuA();
    void invA();
    void invB();
    void tposeA();
    void tposeB();
    void sqA();
    void sqB();
    void detA();
    void detB();
};
#endif // MAINAPP_H
