#pragma once

#include "id.h"
#include <cstdint>
#include <typeinfo>

class Entity
{
  public:
    using IdType = Id;

    explicit Entity(IdType id);

    virtual ~Entity() = default;

    IdType getId() const;

    bool operator==(const Entity &other) const;
    bool operator!=(const Entity &other) const;

  protected:
    IdType id_;

  private:
    bool isUnassignedId() const;
    bool isSameInstance(const Entity &other) const;
    bool isSameType(const Entity &other) const;
    bool hasSameId(const Entity &other) const;
};
