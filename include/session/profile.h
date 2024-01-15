#ifndef PROFILE_H
#define PROFILE_H

#include <QAbstractItemModel>
#include <QDate>
#include <QObject>

#include "edithistory.h"
#include "../serialization/serializable.h"

class ActivityLog;
class Directive;



class Profile : public QAbstractItemModel, Serializable
{
    /* Model Structure:
     *
     *   [Root]                                Where...
     *      |                                    Dn: Directive at index n of
     *      |---[D0]                                 m_directives
     *      |     |--[ ] // Directive Info
     *      |     |   |                           n: Name of Directive
     *      |     |   `--[n][d][v][t][a]          d: Description of Directive
     *      |     |                               v: Valence of Directive
     *      |     |--[ ] // Edit History          t: Threshold of Directive
     *      |     |   |                           a: Is Directive Active?
     *      |     |   `--[d0][d1][d2]...[dn]
     *      |     |      [E0][E1][E2]...[En]     dn: Edit date number n
     *      |     |                              En: Edit summary number n
     *      |     `--[ ] // Activity Log
     *      |         |                          ln: Log date for log n days
     *      |         `--[l0][l1][l2]...[ln]         after creation date
     *      |            [a0][a1][a2]...[an]     an: Log value isActive for log
     *      |            [c0][c1][c2]...[cn]         number n
     *      |            [e0][e1][e2]...[en]     cn: Log value isConsulted for
     *      |            [f0][f1][f2]...[fn]         log number n
     *      |---[D1]                             en: Log value isEnforced for
     *      |     |--- . . .                         log number n
     *      .     .                              fn: Log value isFollowed for
     *      .     .                                  log number n
     *      .     .
     *
     */
    Q_OBJECT
public:
    // -------------------------------------------------------------------------
    // [Profile]   L I F E - C Y C L E
    // -------------------------------------------------------------------------
    explicit Profile(const QString& profileName,
                     QObject *parent = nullptr);
    ~Profile();


    // -------------------------------------------------------------------------
    // [Profile]   M E M B E R S
    // -------------------------------------------------------------------------
    // Accessors
    QDate creationDate() const {return m_creationDate;}
    QString dataPath() const {return m_dataPath;}
    QString profileName() const {return m_profileName;}

    // Mutators
    void setDataPath(const QString& path);
    void setProfileName(const QString& name);


    // -------------------------------------------------------------------------
    // [QAbstractItemModel]   N A V I G A T I O N
    // -------------------------------------------------------------------------
    // Structural Information
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    bool hasChildren(const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    // Index Creation
    QModelIndex index(int row,
                      int column,
                      const QModelIndex& parent = QModelIndex()) const override;


    // -------------------------------------------------------------------------
    // [QAbstractItemModel]   I T E M   D A T A   H A N D L I N G
    // -------------------------------------------------------------------------
    // Access
    QVariant data(const QModelIndex& index,
                  int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    // QMap<int, QVariant> itemData(const QModelIndex& index) const override;

    // Mutation
    bool setData(const QModelIndex& index,
                 const QVariant& value,
                 int role = Qt::EditRole) override;
    bool setHeaderData(int section,
                       Qt::Orientation orientation,
                       const QVariant& value,
                       int role = Qt::EditRole) override;
    // bool setItemData(const QModelIndex& index,
    //                  const QMap<int, QVariant>& roles) override;


    // -------------------------------------------------------------------------
    // [QAbstractItemModel]   M I M E   O P E R A T I O N S
    // -------------------------------------------------------------------------
    // Drag and Drop
    // bool canDropMimeData(const QMimeData* data,
    //                      Qt::DropAction action,
    //                      int row,
    //                      int column,
    //                      const QModelIndex& parent) const override;
    // bool dropMimeData(const QMimeData* data,
    //                   Qt::DropAction action,
    //                   int row,
    //                   int column,
    //                   const QModelIndex& parent) override;
    // Qt::DropActions supportedDragActions() const override;
    // Qt::DropActions supportedDropActions() const override;

    // MIME Data
    // QMimeData* mimeData(const QModelIndexList& indexes) const override;
    // QStringList mimeTypes() const override;


    // -------------------------------------------------------------------------
    // [Serializable]   S E R I A L I Z A T I O N
    // -------------------------------------------------------------------------
    QVariant toVariant() const override;
    void fromVariant(const QVariant& variant) override;

signals:

private:
    // -------------------------------------------------------------------------
    // [Profile]   H E L P E R   F U N C T I O N S
    // -------------------------------------------------------------------------

    // -------------------------------------------------------------------------
    // [Profile]   D A T A   M E M B E R S
    // -------------------------------------------------------------------------
    QString m_profileName;
    QDate m_creationDate;
    QString m_dataPath;

    QList<Directive*> m_directives;
    QMap<Directive*, bool> m_currentlyActive;
    QMap<Directive*, QList<QPair<QDate, QVariant> >* > m_editHistories;
    QMap<Directive*, QMap<QDate, ActivityLog*> > m_logs;
};

#endif // PROFILE_H
