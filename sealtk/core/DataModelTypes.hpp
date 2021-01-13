/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef sealtk_core_DataModelTypes_hpp
#define sealtk_core_DataModelTypes_hpp

#include <sealtk/core/Export.h>

#include <qtGlobal.h>

#include <QMetaType>

namespace sealtk
{

namespace core
{

QTE_BEGIN_META_NAMESPACE(SEALTK_CORE_EXPORT, data_model_types)

/// Well known item types.
enum ItemType
{
  InvalidItemType = 0,
  TrackItem       = 0x01,
  EventItem       = 0x02,
  ActivityItem    = 0x04,
  QueryResultItem = 0x08,
  RegionItem      = 0x10,
  AnnotationItem  = 0x20,
  BuiltinItems    = 0x2f
};

QTE_ENUM_NS(ItemType)

/// Set of well known item types.
Q_DECLARE_FLAGS(ItemTypes, ItemType)

QTE_FLAG_NS(ItemTypes)

/// Common data roles for item data models.
///
/// This enumeration defines a number of standard data roles used by item
/// representations. Item data models used to feed representations are expected
/// to provide a subset of these data roles as determined by the specific
/// representations being used.
enum ItemDataRole
{
  /// (QString) Name or ID of the item as it should be displayed to the user.
  NameRole = Qt::DisplayRole,

  /// (ItemType) Type of the item.
  ItemTypeRole = Qt::UserRole,

  /// (\em varies) Logical ID of the item.
  ///
  /// The data type depends on the item type. Usually this will match or
  /// contain the ID that the item was given by the source that produced the
  /// item, and may contain a reference to the item's source.
  LogicalIdentityRole,
  /// (QUuid) Universally unique identifier of the item.
  UniqueIdentityRole,

  /// (bool) Effective visibility state of the item.
  ///
  /// This is \c true if the item's user visibility is \c true, and the item
  /// has not been excluded by a filter.
  VisibilityRole,

  /// (bool) User override visibility state of the item.
  ///
  /// This is \c false iff the user has manually specified that this specific
  /// item should be hidden.
  UserVisibilityRole,

  /// (timestamp::time_t) Scene time at which the item enters scope.
  StartTimeRole,
  /// (timestamp::time_t) Scene time at which the item leaves scope.
  EndTimeRole,

  /// (QRectF) Image area location of an entity.
  ///
  /// This provides the area location (i.e. an axis-aligned bounding box) of an
  /// item. The coordinates are in the image space of the imagery corresponding
  /// to the item's time. (This datum is normally only available for items
  /// which have a specific, distinct time point, i.e. which have the same
  /// value for both StartTimeRole and EndTimeRole. Such items are often
  /// children of higher-level items.)
  AreaLocationRole,

  /// (QString) Best applicable classification type of the item.
  ///
  /// This provides the type of the best classification of the item which is
  /// currently applicable. "Best" is defined as the applicable classification
  /// with the highest score. Classification filters will affect which
  /// classifications are considered "applicable".
  ///
  /// \sa ClassificationScoreRole, ClassificationRole
  ClassificationTypeRole,

  /// (double) Best applicable classification score of the item.
  ///
  /// This provides the score of the best classification of the item which is
  /// currently applicable. "Best" is defined as the applicable classification
  /// with the highest score. Classification filters will affect which
  /// classifications are considered "applicable".
  ///
  /// \sa ClassificationTypeRole, ClassificationRole
  ClassificationScoreRole,

  /// (QVariantHash) Complete classification of the item.
  ///
  /// This provides or sets a map of \em all classifications that have been
  /// applied to the item. The keys in the map are classification types; the
  /// values are the corresponding scores, and are of \c double type.
  ClassificationRole,

  /// (QStringList) User notes associated with the item.
  NotesRole,

  /// First role that can be used for model-specific purposes.
  UserRole = Qt::UserRole + 224
};

QTE_ENUM_NS(ItemDataRole)

QTE_END_META_NAMESPACE()

} // namespace core

} // namespace sealtk

Q_DECLARE_OPERATORS_FOR_FLAGS(sealtk::core::ItemTypes)

#endif
