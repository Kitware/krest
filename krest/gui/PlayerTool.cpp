/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <krest/gui/PlayerTool.hpp>

#include <krest/gui/Player.hpp>

#include <QByteArray>
#include <QMouseEvent>
#include <QPair>
#include <QStack>
#include <QVariant>

namespace krest
{

namespace gui
{

// ============================================================================
class PlayerToolPrivate
{
public:
  PlayerToolPrivate(Player* player) : player{player} {}

  Player* const player;
  QStack<QPair<QByteArray, QVariant>> pushedProperties;
};

// ----------------------------------------------------------------------------
QTE_IMPLEMENT_D_FUNC(PlayerTool)

// ----------------------------------------------------------------------------
PlayerTool::PlayerTool(Player* parent)
  : QObject{parent}, d_ptr{new PlayerToolPrivate{parent}}
{
}

// ----------------------------------------------------------------------------
PlayerTool::~PlayerTool()
{
}

// ----------------------------------------------------------------------------
Player* PlayerTool::player() const
{
  QTE_D();
  return d->player;
}

// ----------------------------------------------------------------------------
void PlayerTool::activate()
{
}

// ----------------------------------------------------------------------------
void PlayerTool::deactivate()
{
  QTE_D();

  while (!d->pushedProperties.empty())
  {
    auto const pair = d->pushedProperties.pop();
    auto const name = pair.first;
    d->player->setProperty(name.data(), pair.second);
  }
}

// ----------------------------------------------------------------------------
void PlayerTool::mousePressEvent(QMouseEvent* event)
{
  event->ignore();
}

// ----------------------------------------------------------------------------
void PlayerTool::mouseReleaseEvent(QMouseEvent* event)
{
  event->ignore();
}

// ----------------------------------------------------------------------------
void PlayerTool::mouseMoveEvent(QMouseEvent* event)
{
  event->ignore();
}

// ----------------------------------------------------------------------------
void PlayerTool::paintGL()
{
}

// ----------------------------------------------------------------------------
void PlayerTool::updateImage()
{
}

// ----------------------------------------------------------------------------
void PlayerTool::pushProperty(char const* name, QVariant const& value)
{
  QTE_D();
  d->pushedProperties.push({name, d->player->property(name)});
  d->player->setProperty(name, value);
}

} // namespace gui

} // namespace krest
