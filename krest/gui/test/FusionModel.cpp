/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <krest/gui/FusionModel.hpp>

#include <krest/core/AbstractItemModel.hpp>
#include <krest/core/DataModelTypes.hpp>

#include <vital/types/timestamp.h>

#include <vital/range/iota.h>

#include <QVector>

#include <QtTest>

namespace kvr = kwiver::vital::range;

using time_us_t = kwiver::vital::timestamp::time_t;

namespace krest
{

namespace gui
{

namespace test
{

namespace // anonymous
{

// ============================================================================
struct DataRow
{
  qint64 id;
  time_us_t start;
  time_us_t end;
  bool visible;
};

// ----------------------------------------------------------------------------
constexpr DataRow data1[] = {
  {1, 50, 50, true},
  {2, 10, 80, true},
  {3, 70, 80, false},
};

// ----------------------------------------------------------------------------
constexpr DataRow data2[] = {
  {2, 50, 60, false},
  {3, 70, 90, true},
  {4, 40, 50, false},
};

// ----------------------------------------------------------------------------
constexpr DataRow data3[] = {
  {2, 40, 50, true},
  {4, 30, 80, false},
  {5, 20, 70, false},
};

// ============================================================================
class TestModelBase : public krest::core::AbstractItemModel
{
public:
  using krest::core::AbstractItemModel::data;

protected:
  QVariant data(QModelIndex const& index, int role,
                DataRow const* rowData) const;
};

// ----------------------------------------------------------------------------
QVariant TestModelBase::data(
  QModelIndex const& index, int role, DataRow const* rowData) const
{
  if (this->checkIndex(index, IndexIsValid | ParentIsInvalid))
  {
    auto& row = rowData[index.row()];
    switch (role)
    {
      case krest::core::NameRole:
      case krest::core::LogicalIdentityRole:
        return row.id;

      case krest::core::StartTimeRole:
        return QVariant::fromValue(row.start);

      case krest::core::EndTimeRole:
        return QVariant::fromValue(row.end);

      case krest::core::UserVisibilityRole:
        return row.visible;

      default:
        break;
    }
  }

  return krest::core::AbstractItemModel::data(index, role);
}

// ============================================================================
class TestModel : public TestModelBase
{
public:
  template <size_t N>
  TestModel(DataRow const (&rows)[N])
    : rowData{rows}, size{static_cast<int>(N)} {}

  int rowCount(QModelIndex const& parent = {}) const override
  { return (parent.isValid() ? 0 : this->size); }

  QVariant data(QModelIndex const& index, int role) const override
  { return this->data(index, role, rowData); }

protected:
  using TestModelBase::data;

private:
  DataRow const* const rowData;
  int const size;
};

// ============================================================================
class TestMutatingModel : public TestModelBase
{
public:
  int rowCount(QModelIndex const& parent = {}) const override
  { return (parent.isValid() ? 0 : this->rowData.count()); }

  QVariant data(QModelIndex const& index, int role) const override
  { return this->data(index, role, rowData.data()); }

  void insertRow(int i, DataRow const& row)
  {
    this->beginInsertRows({}, i, i);
    this->rowData.insert(i, row);
    this->endInsertRows();
  }

  void removeRow(int i)
  {
    this->beginRemoveRows({}, i, i);
    this->rowData.remove(i);
    this->endRemoveRows();
  }

protected:
  using TestModelBase::data;

private:
  QVector<DataRow> rowData;
};

// ----------------------------------------------------------------------------
void testRow(
  QAbstractItemModel const& model, int row,
  time_us_t expectedStart, time_us_t expectedEnd, bool expectedVisibility)
{
  using krest::core::LogicalIdentityRole;
  using krest::core::StartTimeRole;
  using krest::core::EndTimeRole;
  using krest::core::VisibilityRole;

  auto const& index = model.index(row, 0);

  QVERIFY(model.data(index, StartTimeRole).canConvert<time_us_t>());
  QCOMPARE(model.data(model.index(row, 0), StartTimeRole).value<time_us_t>(),
           expectedStart);

  QVERIFY(model.data(index, EndTimeRole).canConvert<time_us_t>());
  QCOMPARE(model.data(model.index(row, 0), EndTimeRole).value<time_us_t>(),
           expectedEnd);

  QVERIFY(model.data(index, VisibilityRole).canConvert<bool>());
  QCOMPARE(model.data(model.index(row, 0), VisibilityRole).toBool(),
           expectedVisibility);
}

// ----------------------------------------------------------------------------
void testModelData(
  QAbstractItemModel const& model, qint64 id,
  time_us_t expectedStart, time_us_t expectedEnd, bool expectedVisibility)
{
  using krest::core::LogicalIdentityRole;

  for (auto const row : kvr::iota(model.rowCount()))
  {
    auto const& index = model.index(row, 0);

    QVERIFY(model.data(index, LogicalIdentityRole).canConvert<qint64>());
    if (model.data(index, LogicalIdentityRole).value<qint64>() == id)
    {
      testRow(model, row, expectedStart, expectedEnd, expectedVisibility);
      return;
    }
  }

  QFAIL(qPrintable(QStringLiteral("Did not find id %1 in model").arg(id)));
}

} // namespace <anonymous>

// ============================================================================
class TestFusionModel : public QObject
{
  Q_OBJECT

private slots:
  void operations();
  void mutatingModel();
};

// ----------------------------------------------------------------------------
void TestFusionModel::operations()
{
  TestModel dm1{data1};
  TestModel dm2{data2};
  TestModel dm3{data3};

  // Test model shape
  FusionModel fm;
  QCOMPARE(fm.rowCount(), 0);

  fm.addModel(&dm1);
  QCOMPARE(fm.rowCount(), 3);

  fm.addModel(&dm2);
  QCOMPARE(fm.rowCount(), 4);

  fm.addModel(&dm3);
  QCOMPARE(fm.rowCount(), 5);

  // Test model data
  testModelData(fm, 1, 50, 50, true);
  testModelData(fm, 2, 10, 80, true);
  testModelData(fm, 3, 70, 90, true);
  testModelData(fm, 4, 30, 80, false);
  testModelData(fm, 5, 20, 70, false);

  // Remove a model
  fm.removeModel(&dm1);

  // Test model shape and data again
  QCOMPARE(fm.rowCount(), 4);
  testModelData(fm, 2, 40, 60, true);
  testModelData(fm, 3, 70, 90, true);
  testModelData(fm, 4, 30, 80, false);
  testModelData(fm, 5, 20, 70, false);
}

// ----------------------------------------------------------------------------
void TestFusionModel::mutatingModel()
{
  TestModel dmc{data3};
  TestMutatingModel dmm;

  // Test model initial state
  FusionModel fm;
  fm.addModel(&dmc);
  fm.addModel(&dmm);

  QCOMPARE(fm.rowCount(), 3);
  testModelData(fm, 2, 40, 50, true);
  testModelData(fm, 4, 30, 80, false);
  testModelData(fm, 5, 20, 70, false);

  // Test state after adding some new rows
  dmm.insertRow(0, data1[0]);
  dmm.insertRow(0, data1[1]);
  dmm.insertRow(1, data1[2]);

  QCOMPARE(fm.rowCount(), 5);
  testModelData(fm, 1, 50, 50, true);
  testModelData(fm, 2, 10, 80, true);
  testModelData(fm, 3, 70, 80, false);
  testModelData(fm, 4, 30, 80, false);
  testModelData(fm, 5, 20, 70, false);

  // Test state after removing a "common" row
  dmm.removeRow(0);

  QCOMPARE(fm.rowCount(), 5);
  testModelData(fm, 1, 50, 50, true);
  testModelData(fm, 2, 40, 50, true);
  testModelData(fm, 3, 70, 80, false);
  testModelData(fm, 4, 30, 80, false);
  testModelData(fm, 5, 20, 70, false);

  // Test state after removing a "unique" row
  dmm.removeRow(1);

  QCOMPARE(fm.rowCount(), 4);
  testModelData(fm, 2, 40, 50, true);
  testModelData(fm, 3, 70, 80, false);
  testModelData(fm, 4, 30, 80, false);
  testModelData(fm, 5, 20, 70, false);
}

} // namespace test

} // namespace gui

} // namespace krest

// ----------------------------------------------------------------------------
QTEST_MAIN(krest::gui::test::TestFusionModel)
#include "FusionModel.moc"
