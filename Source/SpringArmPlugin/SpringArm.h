
#pragma once

#include "Engine/Level/Actor.h"
#include "Engine/Scripting/ScriptingObject.h"
#include "Engine/Core/Types/LayersMask.h"

/// <summary>
/// A tool that checks for collision objects along its backward direction, moving all children out of the collision object if an obstruction is detected.
/// </summary>
API_CLASS(Attributes = "ActorContextMenu(\"New/Physics/Spring Arm\"), ActorToolbox(\"Physics\", \"Spring Arm\")")
class SPRINGARMPLUGIN_API SpringArm : public Actor
{
API_AUTO_SERIALIZATION()
DECLARE_SCENE_OBJECT(SpringArm);

private:
	float _castRadius;
	float _hitDistance;

public:
	/// <summary>
	/// The distance used during collision checks for the spring to place its children along.
	/// </summary>
	API_FIELD(Attributes = "EditorOrder(0), DefaultValue(400.0f), EditorDisplay(\"Spring Arm\")")
	float ArmLength = 400;

	/// <summary>
	/// Gets the radius of the sphere used during collision checks. A value of 0 will result in a standard line-based RayCast instead.
	/// </summary>
	API_PROPERTY(Attributes = "EditorOrder(10), DefaultValue(20.0f), EditorDisplay(\"Spring Arm\"), Limit(0.0f)")
	FORCE_INLINE float GetCastRadius() const
	{
		return _castRadius;
	}

	/// <summary>
	/// Gets the radius of the sphere used during collision checks. A value of 0 will result in a standard line-based RayCast instead.
	/// </summary>
	API_PROPERTY() void SetCastRadius(const float& value);

	/// <summary>
	/// The mask used for collision checks. For usage with cameras, you'll often want to exclude the collision layer that the player resides on to prevent the camera from clipping into the player.
	/// </summary>
	API_FIELD(Attributes = "EditorOrder(20), DefaultValue(1 >> 0), EditorDisplay(\"Spring Arm\")")
	LayersMask CollisionMask = 1 >> 0;

	/// <summary>
	/// Any additional offset to apply to children after the spring has moved the children.
	/// </summary>
	/// <remarks>
	/// The offset is done in the Actor's local space.
	/// </remarks>
	API_FIELD(Attributes = "EditorOrder(30), DefaultValue(typeof(Vector3), \"0,0,0\"), EditorDisplay(\"Spring Arm\")")
	Vector3 PositionOffset = Vector3::Zero;

	/// <summary>
	/// The current length of the SpringArm, taking into account any obstructing collisions.
	/// </summary>
	API_PROPERTY() FORCE_INLINE float GetHitDistance() const
	{
		return _hitDistance;
	}

private:
	void ProcessSpring();
	void PlaceChildrenAlongSpring(const float& distance);

public:
#if USE_EDITOR
	void OnDebugDrawSelected() override;
#endif

    // [Actor]
    void BeginPlay(SceneBeginData* data) override;
    void OnEnable() override;
    void OnDisable() override;
};
