/* This file is part of SEAL-TK, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/seal-tk/blob/master/LICENSE for details. */

#ifndef sealtk_core_KwiverVideoSource_hpp
#define sealtk_core_KwiverVideoSource_hpp

#include <sealtk/core/VideoSource.hpp>

#include <QImage>
#include <QObject>
#include <QSet>
#include <qtGlobal.h>

#include <vital/types/timestamp.h>
#include <vital/algo/video_input.h>

namespace sealtk
{

namespace core
{

class KwiverVideoSourcePrivate;

class KwiverVideoSource : public VideoSource
{
  Q_OBJECT

public:
  explicit KwiverVideoSource(QObject* parent = nullptr);
  ~KwiverVideoSource() override;

  kwiver::vital::algo::video_input_sptr videoInput() const;
  void setVideoInput(kwiver::vital::algo::video_input_sptr const& videoInput);

  QSet<kwiver::vital::timestamp::time_t> times() const override;

public slots:
  void seek(kwiver::vital::timestamp::time_t time) override;

protected:
  QTE_DECLARE_PRIVATE(KwiverVideoSource)

private:
  QTE_DECLARE_PRIVATE_RPTR(KwiverVideoSource)
};

}

}

#endif
