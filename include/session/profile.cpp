#include "profile.h"

#include "../decision/directive.h"

Profile::Profile(const QString& profileName, QObject* parent)
    : QAbstractItemModel{parent}
    , m_profileName(profileName)
    , m_creationDate(QDate::currentDate())
    , m_dataPath("")
    , m_directives()
    , m_currentlyActive()
    , m_editHistories()
    , m_logs()
{}

Profile::~Profile()
{
    //

}

void Profile::setDataPath(const QString& path)
{
    // TODO - Check for path validity.
    m_dataPath = path;
}

void Profile::setProfileName(const QString& name)
{
    // TODO - Consider checking for validity.
    m_profileName = name;
}

int Profile::columnCount(const QModelIndex& parent) const
{
    /*
     * Cases for argument parent:
     * - Root Item:
     *      - parent equals QModelIndex()
     *      - Only one column.
     * - Directive Item:
     *      - parent.parent() equals QModelIndex()
     *      - Only one column.
     * - Directive Info / Edit History / Activity Log Root Item
     *      - parent.parent().parent() equals QModelIndex
     *      - If parent.row() equals 0, in Directive Info root item
     *             - Five columns
     *      - If parent.row() equals 1, in Edit History root item
     *             - As many columns as Edits in Edit History for relevant
     *               Directive
     *      - If parent.row() equals 2, in ActivityLog root item
     *             - As many columns as days that have passed since Profile
     *               was created.
     * - Item in Directive Info / Edit History / Activity Log Data
     *      - parent.parent().parent().parent() equals QModelIndex()
     *      - Zero columns
     * - Invalid Item:
     *      - Just return zero
     */
    int result;

    if (!parent.isValid() || !parent.parent().isValid()) {
        result = 1;
    } else if (!parent.parent().parent().isValid()) {
        switch (parent.row()) {
        case 0:
            result = 5;
            break;
        case 1:
            result = m_editHistories.value(m_directives.at(parent.parent().row()))
                         ->length();
            break;
        case 2:
            result = m_creationDate.daysTo(QDate::currentDate());
            break;
        default:
            result = 0;
            break;
        }
        // } else if (parent.parent().parent().parent() == QModelIndex()) {
        //     result = 0;
    } else {
        result = 0;
    }

    return result;
}

bool Profile::hasChildren(const QModelIndex& parent) const
{
    bool result = false;

    if (!parent.isValid() ||
        !parent.parent().isValid() ||
        !parent.parent().parent().isValid())
    {
        result = true;
    }

    return result;
}

QModelIndex Profile::parent(const QModelIndex& index) const
{
    auto result = QModelIndex();

    // TODO

    return result;
}

int Profile::rowCount(const QModelIndex& parent) const
{
    // TODO
    return 0;
}

QModelIndex Profile::index(int row,
                           int column,
                           const QModelIndex& parent) const
{
    // Prepare result variable.
    QModelIndex result;

    // Initial validity check.
    if (!hasIndex(row, column, parent)) {
        result = QModelIndex();
    }

    // Testing for level of item.
    if (!parent.isValid()) {

        // Item is top level, index corresponding to Directive is requested
        result = createIndex(row, 0, m_directives.at(row));

    } else if (!parent.parent().isValid()) {

        // Item is second level, index corresponding to navigation node that
        // is the child of a Directive node.
        // First, determine which Directive the navigation node belongs to,
        // and cast the pointer to a quintptr idBase.
        auto idBase = reinterpret_cast<quintptr>(
            static_cast<Directive*>(parent.internalPointer())
            ) + 1; // Add one to ensure no overlap with Directive pointer.
        result = createIndex(row, 0, idBase + row);

    } else if (!parent.parent().parent().isValid()) {

        // Item is third level, index corresponding to a specific, viewable
        // data item within the model.
        // First, determine the relevant Directive.
        auto dir = static_cast<Directive*>(parent.parent().internalPointer());
        // Next step depends on row of parent index.
        if (parent.row() == 0) {
            // Directive Info:

            // // Using the same ID scheme as above, but with an initial
            // // base offset of 10.
            // result = createIndex(0,
            //                      column,
            //                      10 + column + reinterpret_cast<quintptr>(dir));

            // Don't need unique IDs (maybe?), can fully specify item with row
            // and column.
            result = createIndex(0, column, dir);

        } else if (parent.row() == 1) {
            // Edit History:

            // Get the edit log for the relevant Directive to use as ID.
            auto edits = m_editHistories.value(dir);
            result = createIndex(row, column, edits);

        } else if (parent.row() == 2) {
            // Activity Log:

            // TODO

        } else {

            result = QModelIndex();

        }

    } else {
        result = QModelIndex();
    }
    return result;
}

QVariant Profile::data(const QModelIndex& index,
                       int role) const
{
    // TODO
    return QVariant();
}

Qt::ItemFlags Profile::flags(const QModelIndex& index) const
{
    // TODO
    return Qt::ItemFlags();
}

QVariant Profile::headerData(int section,
                             Qt::Orientation orientation,
                             int role) const
{
    // TODO
    return QVariant();
}

bool Profile::setData(const QModelIndex& index, const QVariant& value, int role)
{
    // TODO
    return false;
}

bool Profile::setHeaderData(int section,
                            Qt::Orientation orientation,
                            const QVariant& value,
                            int role)
{
    // TODO
    return false;
}

QVariant Profile::toVariant() const
{
    // TODO
    return QVariant();
}

void Profile::fromVariant(const QVariant& variant)
{
    // TODO
}
