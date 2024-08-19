#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "test1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    string str4 = "up";
    if (str2.compare(str4))
    {
        transform(str3.begin(), str3.end(), str3.begin(), ::toupper);
        cout << str3 << endl;
    }
    else
    {
        transform(str3.begin(), str3.end(), str3.begin(), ::tolower);
        cout << str3 << endl;
    }

    return 0;

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    return a.exec();
}