/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_KwiverTracksSink_hpp
#define krest_core_KwiverTracksSink_hpp

#include <krest/core/AbstractDataSink.hpp>

#include <qtGlobal.h>

class QAbstractItemModel;
class QUrl;

namespace krest
{

namespace core
{

class VideoSource;

class KwiverTracksSinkPrivate;

// ============================================================================
class SEALTK_CORE_EXPORT KwiverTracksSink : public AbstractDataSink
{
  Q_OBJECT

public:
  KwiverTracksSink(QObject* parent = nullptr);
  ~KwiverTracksSink() override;

  bool setData(
    VideoSource* video, QAbstractItemModel* model,
    bool includeHidden = false) override;

  bool setTransform(
    kwiver::vital::transform_2d_sptr const& transform) override;

  bool addData(
    QAbstractItemModel* model,
    kwiver::vital::transform_2d_sptr const& transform,
    bool includeHidden = false) override;

  void writeData(QUrl const& uri) const override;

protected:
  QTE_DECLARE_PRIVATE_RPTR(KwiverTracksSink)

private:
  QTE_DECLARE_PRIVATE(KwiverTracksSink)
};

} // namespace core

} // namespace krest

#endif
