#pragma once

#include <QMainWindow>
#include <QTabWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void setupSystemTab();
    void setupStorageTab();
    void setupMemoryTab();
    void setupDisplayTab();
    void setupNetworkTab();
    void setupDiagnosticsTab();

    QTabWidget* tabs_ = nullptr;
};
