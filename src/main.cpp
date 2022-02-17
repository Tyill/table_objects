#include "gui/central_widget.h"
#include "logic/logic.h"
#include "model/model.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
#ifdef _WIN32
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("plugins");
    QCoreApplication::setLibraryPaths(paths);
#endif

    QApplication app(argc, argv);
    app.setApplicationName(PROJECT_NAME);

    CentralWidget mainWin;
    mainWin.show();
    
    Logic logic(&mainWin);

    int result = 0;
    try {
        result = app.exec();
    }
    catch (const char *error) {
        qCritical() << "Caught an exception:" << error;
        result = 1;
    }
    catch (const QString &error) {
        qCritical() << "Caught an exception:" << error;
        result = 2;
    }
    catch (const std::exception &ex) {
        qCritical() << "Caught an exception:" << ex.what();
        result = 3;
    }
    catch (...) {
        qCritical() << "Caught an unknown exception";
        result = 4;
    }

    return result;
}
