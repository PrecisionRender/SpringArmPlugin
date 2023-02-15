// Copyright (c) 2023 PrecisionRender. All rights reserved.

#include "SpringArm.h"
#include "Engine/Debug/DebugDraw.h"
#include "Engine/Level/Scene/Scene.h"
#include "Engine/Physics/Physics.h"
#include "Engine/Debug/DebugLog.h"

SpringArm::SpringArm(const SpawnParams& params)
    : Actor(params)
    , _castRadius(20.0f)
{
}

void SpringArm::SetCastRadius(const float& value)
{
    _castRadius = Math::Max(value, 0.0f);
}

void SpringArm::ProcessSpring()
{
    bool isColliding;
    RayCastHit hit;

    // If our cast radius is zero, do a RayCast instead of a SphereCast.
    if (Math::IsZero(_castRadius))
    {
        isColliding = Physics::RayCast(GetPosition(), GetTransform().GetBackward(), hit, ArmLength, CollisionMask);
    }
    else
    {
        isColliding = Physics::SphereCast(GetPosition(), _castRadius, GetTransform().GetBackward(), hit, ArmLength, CollisionMask);
    }

    _hitDistance = isColliding ? hit.Distance : ArmLength;
    PlaceChildrenAlongSpring(_hitDistance);
}

void SpringArm::PlaceChildrenAlongSpring(const float& distance)
{
    if (Math::IsZero(GetChildrenCount()))
    {
        return;
    }

    for (int i = 0; i < GetChildrenCount(); i++)
    {
        GetChild(i)->SetPosition(GetPosition() + GetTransform().GetBackward() * distance);
        GetChild(i)->SetLocalPosition(GetChild(i)->GetLocalPosition() + PositionOffset);

    }
}

#if USE_EDITOR
void SpringArm::OnDebugDrawSelected()
{
    DEBUG_DRAW_LINE(GetPosition(), GetPosition() + GetTransform().GetBackward() * _hitDistance, Color::YellowGreen, 0, true);
    
    if (!Math::IsZero(_castRadius))
    {
        BoundingSphere sphere = BoundingSphere(GetPosition() + GetTransform().GetBackward() * _hitDistance, _castRadius);
        DEBUG_DRAW_WIRE_SPHERE(sphere, Color::YellowGreen, 0, true);
    }

    // Base
    Actor::OnDebugDrawSelected();
}
#endif

void SpringArm::BeginPlay(SceneBeginData* data)
{
    // Base
    Actor::BeginPlay(data);

    ProcessSpring();
}

void SpringArm::OnEnable()
{
    GetScene()->Ticking.LateUpdate.AddTick<SpringArm, &SpringArm::ProcessSpring>(this);
#ifdef USE_EDITOR
    GetScene()->Ticking.LateUpdate.AddTickExecuteInEditor<SpringArm, &SpringArm::ProcessSpring>(this);
#endif

    // Base
    Actor::OnEnable();
}

void SpringArm::OnDisable()
{
    GetScene()->Ticking.LateUpdate.RemoveTick(this);
#ifdef USE_EDITOR
    GetScene()->Ticking.LateUpdate.RemoveTickExecuteInEditor(this);
#endif

    // Base
    Actor::OnDisable();
}
