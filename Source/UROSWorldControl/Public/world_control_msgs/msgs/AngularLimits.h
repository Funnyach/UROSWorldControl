#pragma once

#include "ROSBridgeMsg.h"

#include "geometry_msgs/Vector3.h"

namespace world_control_msgs
{
	class AngularLimits : public FROSBridgeMsg
	{
		uint8 Swing1Motion;
		uint8 Swing2Motion;
		uint8 TwistMotion;
		float Swing1LimitAngle;
		float Swing2LimitAngle;
		float TwistLimitAngle;
		geometry_msgs::Vector3 AngularRoationOffset;
		bool UseAdvanced;
		bool SwingSoftConstraint;
		float SwingStiffness;
		float SwingDamping;
		bool TwistSoftConstraint;
		float TwistStiffness;
		float TwistDamping;
	public:
		AngularLimits()
		{
			MsgType = "world_control_msgs/AngularLimits";
		}

		AngularLimits
		(
			uint8 InSwing1Motion,
			uint8 InSwing2Motion,
			uint8 InTwistMotion,
			float InSwing1LimitAngle,
			float InSwing2LimitAngle,
			float InTwistLimitAngle,
			geometry_msgs::Vector3 InAngularRoationOffset,
			bool InUseAdvanced,
			bool InSwingSoftConstraint,
			float InSwingStiffness,
			float InSwingDamping,
			bool InTwistSoftConstraint,
			float InTwistStiffness,
			float InTwistDamping
		):
			Swing1Motion(InSwing1Motion),
			Swing2Motion(InSwing2Motion),
			TwistMotion(InTwistMotion),
			Swing1LimitAngle(InSwing1LimitAngle),
			Swing2LimitAngle(InSwing2LimitAngle),
			TwistLimitAngle(InTwistLimitAngle),
			AngularRoationOffset(InAngularRoationOffset),
			UseAdvanced(InUseAdvanced),
			SwingSoftConstraint(InSwingSoftConstraint),
			SwingStiffness(InSwingStiffness),
			SwingDamping(InSwingDamping),
			TwistSoftConstraint(InTwistSoftConstraint),
			TwistStiffness(InTwistStiffness),
			TwistDamping(InTwistDamping)
		{
			MsgType = "world_control_msgs/AngularLimits";
		}

		~AngularLimits() override {}

		uint8 GetSwing1Motion() const
		{
			return Swing1Motion;
		}

		uint8 GetSwing2Motion() const
		{
			return Swing2Motion;
		}

		uint8 GetTwistMotion() const
		{
			return TwistMotion;
		}

		float GetSwing1LimitAngle() const
		{
			return Swing1LimitAngle;
		}

		float GetSwing2LimitAngle() const
		{
			return Swing2LimitAngle;
		}

		float GetTwistLimitAngle() const
		{
			return TwistLimitAngle;
		}

		geometry_msgs::Vector3 GetAngularRoationOffset() const
		{
			return AngularRoationOffset;
		}

		bool GetUseAdvanced() const
		{
			return UseAdvanced;
		}

		bool GetSwingSoftConstraint() const
		{
			return SwingSoftConstraint;
		}

		float GetSwingStiffness() const
		{
			return SwingStiffness;
		}

		float GetSwingDamping() const
		{
			return SwingDamping;
		}

		bool GetTwistSoftConstraint() const
		{
			return TwistSoftConstraint;
		}

		float GetTwistStiffness() const
		{
			return TwistStiffness;
		}

		float GetTwistDamping() const
		{
			return TwistDamping;
		}

		void SetSwing1Motion(uint8 InSwing1Motion)
		{
			Swing1Motion = InSwing1Motion;
		}

		void SetSwing2Motion(uint8 InSwing2Motion)
		{
			Swing2Motion = InSwing2Motion;
		}

		void SetTwistMotion(uint8 InTwistMotion)
		{
			TwistMotion = InTwistMotion;
		}

		void SetSwing1LimitAngle(float InSwing1LimitAngle)
		{
			Swing1LimitAngle = InSwing1LimitAngle;
		}

		void SetSwing2LimitAngle(float InSwing2LimitAngle)
		{
			Swing2LimitAngle = InSwing2LimitAngle;
		}

		void SetTwistLimitAngle(float InTwistLimitAngle)
		{
			TwistLimitAngle = InTwistLimitAngle;
		}

		void SetAngularRoationOffset(geometry_msgs::Vector3 InAngularRoationOffset)
		{
			AngularRoationOffset = InAngularRoationOffset;
		}

		void SetUseAdvanced(bool InUseAdvanced)
		{
			UseAdvanced = InUseAdvanced;
		}

		void SetSwingSoftConstraint(bool InSwingSoftConstraint)
		{
			SwingSoftConstraint = InSwingSoftConstraint;
		}

		void SetSwingStiffness(float InSwingStiffness)
		{
			SwingStiffness = InSwingStiffness;
		}

		void SetSwingDamping(float InSwingDamping)
		{
			SwingDamping = InSwingDamping;
		}

		void SetTwistSoftConstraint(bool InTwistSoftConstraint)
		{
			TwistSoftConstraint = InTwistSoftConstraint;
		}

		void SetTwistStiffness(float InTwistStiffness)
		{
			TwistStiffness = InTwistStiffness;
		}

		void SetTwistDamping(float InTwistDamping)
		{
			TwistDamping = InTwistDamping;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Swing1Motion = JsonObject->GetNumberField(TEXT("swing_1_motion"));

			Swing2Motion = JsonObject->GetNumberField(TEXT("swing_2_motion"));

			TwistMotion = JsonObject->GetNumberField(TEXT("twist_motion"));

			Swing1LimitAngle = JsonObject->GetNumberField(TEXT("swing_1_limit_angle"));

			Swing2LimitAngle = JsonObject->GetNumberField(TEXT("swing_2_limit_angle"));

			TwistLimitAngle = JsonObject->GetNumberField(TEXT("twist_limit_angle"));

			AngularRoationOffset = geometry_msgs::Vector3::GetFromJson(JsonObject->GetObjectField(TEXT("angular_roation_offset")));

			UseAdvanced = JsonObject->GetBoolField(TEXT("use_advanced"));

			SwingSoftConstraint = JsonObject->GetBoolField(TEXT("swing_soft_constraint"));

			SwingStiffness = JsonObject->GetNumberField(TEXT("swing_stiffness"));

			SwingDamping = JsonObject->GetNumberField(TEXT("swing_damping"));

			TwistSoftConstraint = JsonObject->GetBoolField(TEXT("twist_soft_constraint"));

			TwistStiffness = JsonObject->GetNumberField(TEXT("twist_stiffness"));

			TwistDamping = JsonObject->GetNumberField(TEXT("twist_damping"));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			Swing1Motion = BsonObject->GetNumberField(TEXT("swing_1_motion"));

			Swing2Motion = BsonObject->GetNumberField(TEXT("swing_2_motion"));

			TwistMotion = BsonObject->GetNumberField(TEXT("twist_motion"));

			Swing1LimitAngle = BsonObject->GetNumberField(TEXT("swing_1_limit_angle"));

			Swing2LimitAngle = BsonObject->GetNumberField(TEXT("swing_2_limit_angle"));

			TwistLimitAngle = BsonObject->GetNumberField(TEXT("twist_limit_angle"));

			AngularRoationOffset = geometry_msgs::Vector3::GetFromBson(BsonObject->GetObjectField(TEXT("angular_roation_offset")));

			UseAdvanced = BsonObject->GetBoolField(TEXT("use_advanced"));

			SwingSoftConstraint = BsonObject->GetBoolField(TEXT("swing_soft_constraint"));

			SwingStiffness = BsonObject->GetNumberField(TEXT("swing_stiffness"));

			SwingDamping = BsonObject->GetNumberField(TEXT("swing_damping"));

			TwistSoftConstraint = BsonObject->GetBoolField(TEXT("twist_soft_constraint"));

			TwistStiffness = BsonObject->GetNumberField(TEXT("twist_stiffness"));

			TwistDamping = BsonObject->GetNumberField(TEXT("twist_damping"));

		}

		static AngularLimits GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			AngularLimits Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static AngularLimits GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			AngularLimits Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetNumberField(TEXT("swing_1_motion"), Swing1Motion);
			Object->SetNumberField(TEXT("swing_2_motion"), Swing2Motion);
			Object->SetNumberField(TEXT("twist_motion"), TwistMotion);
			Object->SetNumberField(TEXT("swing_1_limit_angle"), Swing1LimitAngle);
			Object->SetNumberField(TEXT("swing_2_limit_angle"), Swing2LimitAngle);
			Object->SetNumberField(TEXT("twist_limit_angle"), TwistLimitAngle);
			Object->SetObjectField(TEXT("angular_roation_offset"), AngularRoationOffset.ToJsonObject());
			Object->SetBoolField(TEXT("use_advanced"), UseAdvanced);
			Object->SetBoolField(TEXT("swing_soft_constraint"), SwingSoftConstraint);
			Object->SetNumberField(TEXT("swing_stiffness"), SwingStiffness);
			Object->SetNumberField(TEXT("swing_damping"), SwingDamping);
			Object->SetBoolField(TEXT("twist_soft_constraint"), TwistSoftConstraint);
			Object->SetNumberField(TEXT("twist_stiffness"), TwistStiffness);
			Object->SetNumberField(TEXT("twist_damping"), TwistDamping);
			return Object;
		}
		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetNumberField(TEXT("swing_1_motion"), Swing1Motion);
			Object->SetNumberField(TEXT("swing_2_motion"), Swing2Motion);
			Object->SetNumberField(TEXT("twist_motion"), TwistMotion);
			Object->SetNumberField(TEXT("swing_1_limit_angle"), Swing1LimitAngle);
			Object->SetNumberField(TEXT("swing_2_limit_angle"), Swing2LimitAngle);
			Object->SetNumberField(TEXT("twist_limit_angle"), TwistLimitAngle);
			Object->SetObjectField(TEXT("angular_roation_offset"), AngularRoationOffset.ToBsonObject());
			Object->SetBoolField(TEXT("use_advanced"), UseAdvanced);
			Object->SetBoolField(TEXT("swing_soft_constraint"), SwingSoftConstraint);
			Object->SetNumberField(TEXT("swing_stiffness"), SwingStiffness);
			Object->SetNumberField(TEXT("swing_damping"), SwingDamping);
			Object->SetBoolField(TEXT("twist_soft_constraint"), TwistSoftConstraint);
			Object->SetNumberField(TEXT("twist_stiffness"), TwistStiffness);
			Object->SetNumberField(TEXT("twist_damping"), TwistDamping);
			return Object;
		}
		virtual FString ToYamlString() const override
		{
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
			return OutputString;
		}
	};
}