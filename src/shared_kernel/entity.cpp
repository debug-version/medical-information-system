#include "entity.h"

Entity::Entity(IdType id)
    : id_(id)
{
}

Entity::IdType Entity::getId() const
{
    return id_;
}

bool Entity::operator==(const Entity &other) const
{
    if (isSameInstance(other))
        return true;
    if (!isSameType(other))
        return false;
    if (isUnassignedId() || other.isUnassignedId())
        return false;
    return hasSameId(other);
}

bool Entity::operator!=(const Entity &other) const
{
    return !(*this == other);
}

bool Entity::isUnassignedId() const
{
    return id_ <= 0;
}

bool Entity::isSameInstance(const Entity &other) const
{
    return this == &other;
}

bool Entity::isSameType(const Entity &other) const
{
    return typeid(*this) == typeid(other);
}

bool Entity::hasSameId(const Entity &other) const
{
    return id_ == other.id_;
}
