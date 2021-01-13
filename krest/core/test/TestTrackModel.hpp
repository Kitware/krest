/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef sealtk_core_test_TestTrackModel_hpp
#define sealtk_core_test_TestTrackModel_hpp

#include <sealtk/core/test/TestTracks.hpp>

#include <sealtk/core/AbstractItemModel.hpp>
#include <sealtk/core/TimeMap.hpp>

namespace sealtk
{

namespace core
{

namespace test
{

// ============================================================================
class SimpleTrackModel : public core::AbstractItemModel
{
public:
  SimpleTrackModel(QVector<TimeMap<TrackState>> data);

  int rowCount(QModelIndex const& parent = {}) const override;

  QVariant data(QModelIndex const& index, int role) const override;
  QModelIndex parent(QModelIndex const& index) const override;
  QModelIndex index(int row, int column,
                    QModelIndex const& parent) const override;

  void setFirstId(qint64 id);

private:
  QVector<TimeMap<TrackState>> const rowData;
  qint64 firstId = 0;
};

} // namespace test

} // namespace core

} // namespace sealtk

#endif
