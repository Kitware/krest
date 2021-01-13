/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_VideoRequestor_hpp
#define krest_core_VideoRequestor_hpp

#include <krest/core/Export.h>

#include <QObject>

namespace krest
{

namespace core
{

struct VideoFrame;
struct VideoRequest;
struct VideoRequestInfo;

// ============================================================================
class KREST_CORE_EXPORT VideoRequestor : public QObject
{
  Q_OBJECT

public:
  virtual ~VideoRequestor() = default;

protected:
  friend struct VideoRequest;

  explicit VideoRequestor(QObject* parent = nullptr);

  virtual void update(VideoRequestInfo const& requestInfo,
                      VideoFrame&& response) = 0;
};

} // namespace core

} // namespace krest

#endif
