#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "domain/sqlquerymodel.h"

class TreeItem;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(QStringList userRoleNames READ userRoleNames CONSTANT)

public:
    explicit TreeModel(SqlQueryModel &data, QObject *parent = 0);
    explicit TreeModel(QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QStringList userRoleNames();

private:
    void setupModelData(const SqlQueryModel &rows, TreeItem *parent);

    TreeItem *rootItem;

    SqlQueryModel *m_sqlFlatModel;
};

#endif // TREEMODEL_H
