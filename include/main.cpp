#include "gui/mainwindow.h"

#include <QApplication>

#include "appinit.h"

// For Testing
#include "decision/constantdirective.h"
#include "decision/variabledirective.h"
#include "serialization/binaryserializer.h"
#include "serialization/jsonserializer.h"
#include "session/activitylog.h"
#include "session/edithistory.h"
#include <QMetaProperty>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    App::init();

    MainWindow w;
    w.show();

    /*
     * =========================================================================
     *     T    E    S    T    I    N    G
     * =========================================================================
     *
     * GOALS:
     *     - Validate functionality of the following classes/interfaces before
     *       integrating them into or using them with the Profile model class:
     *         - Directive
     *             - ConstantDirective
     *             - VariableDirective
     *         - Serializable interface implementations
     *         - Serializer
     *             - BinarySerializer
     *             - JsonSerializer
     *         - ActivityLog
     *         - EditHistory
     *     - Evaluate design choices made for classes listed above.
     */

    /*
     * -------------------------------------------------------------------------
     *    TEST 00 - DIRECTIVES
     * -------------------------------------------------------------------------
     * GOALS:
     *     - Validate functionality of the following features of the Directive
     *       class in both ConstantDirective and VariableDirective subclasses:
     *         - Basic data storage and retrieval of members
     *             - Tested members are:
     *                 - Name
     *                 - Description
     *                 - Valence
     *                 - Threshold
     *         - Printing through qDebug
     *     - Validate stored QVariant helper members
     *     - Validate dynamic creation of Directives through
     */
    {
        qDebug() << "Creating ConstantDirective objects cDir1 and cDir2, and" <<
            "VariableDirective objects vDir1 and vDir2.";
        auto cDir1 = ConstantDirective("cDir1 Name",
                                       "cDir1 Description",
                                       Directive::Valence::POSITIVE,
                                       0.5);
        auto cDir2 = ConstantDirective("cDir2 Name",
                                       "cDir2 Description",
                                       Directive::Valence::NEGATIVE,
                                       0.1);
        auto vDir1 = VariableDirective("vDir1 Name",
                                       "vDir1 Description",
                                       Directive::Valence::NEGATIVE,
                                       QDate(2024, 1, 9),
                                       QDate(2024, 1, 13),
                                       0.1,
                                       0.8);
        auto vDir2 = VariableDirective();
        qDebug() << "Testing stream operator for each Directive...";
        qDebug() << cDir1;
        qDebug() << cDir2;
        qDebug() << vDir1;
        qDebug() << vDir2;
        qDebug() << "Checking members of cDir1 through getters...";
        qDebug() << "\tName:" << cDir1.name();
        qDebug() << "\tDescription:" << cDir1.description();
        qDebug() << "\tValence:" << (bool)cDir1.valence();
        qDebug() << "\tThreshold:" << cDir1.threshold();
        qDebug() << "Modifying members of cDir1 through setters...";
        QString nameEdited("cDir1 Name but edited");
        cDir1.setName(nameEdited);
        qDebug() << "\tName <-" << nameEdited;
        QString descriptionEdited("cDir1 Description but edited");
        cDir1.setDescription(descriptionEdited);
        qDebug() << "\tDescription <-" << descriptionEdited;
        auto valenceEdited(Directive::Valence::NEGATIVE);
        cDir1.setValence(valenceEdited);
        qDebug() << "\tValence <-" << (bool)valenceEdited;
        double thresholdEdited(0.1);
        cDir1.setThreshold(thresholdEdited);
        qDebug() << "\tThreshold <-" << thresholdEdited;
        qDebug() << "Checking changes...";
        qDebug() << cDir1;
        qDebug() << "Storing in QVariant and printing result...";
        auto cDir1Variant(cDir1.toVariant());
        qDebug() << "\t" << cDir1Variant;
        qDebug() << "Checking QVariant helper functions...";
        qDebug() << "\tDirective::nameOf(cDir1Variant) ="
                 << Directive::nameOf(cDir1Variant);
        qDebug() << "\tDirective::descriptionOf(cDir1Variant) ="
                 << Directive::descriptionOf(cDir1Variant);
        qDebug() << "\t(bool)Directive::valenceOf(cDir1Variant) ="
                 << qToUnderlying(Directive::valenceOf(cDir1Variant));
        qDebug() << "\tDirective::thresholdOf(cDir1Variant) ="
                 << Directive::thresholdOf(cDir1Variant);

    }

    /*
     * -------------------------------------------------------------------------
     *    TEST 01 - SERIALIZATION (DIRECTIVES)
     * -------------------------------------------------------------------------
     */

    return a.exec();
}
