#pragma once

#include "ROSBridgeMsg.h"


namespace world_control_msgs
{
	class LinearLimits : public FROSBridgeMsg
	{
		uint8 XMotion;
		uint8 YMotion;
		uint8 ZMotion;
		float Limit;
		bool UseAdvanced;
		bool SoftConstraint;
		float Stiffness;
		float Damping;
	public:
		LinearLimits()
		{
			MsgType = "world_control_msgs/LinearLimits";
		}

		LinearLimits
		(
			uint8 InXMotion,
			uint8 InYMotion,
			uint8 InZMotion,
			float InLimit,
			bool InUseAdvanced,
			bool InSoftConstraint,
			float InStiffness,
			float InDamping
		):
			XMotion(InXMotion),
			YMotion(InYMotion),
			ZMotion(InZMotion),
			Limit(InLimit),
			UseAdvanced(InUseAdvanced),
			SoftConstraint(InSoftConstraint),
			Stiffness(InStiffness),
			Damping(InDamping)
		{
			MsgType = "world_control_msgs/LinearLimits";
		}

		~LinearLimits() override {}

		uint8 GetXMotion() const
		{
			return XMotion;
		}

		uint8 GetYMotion() const
		{
			return YMotion;
		}

		uint8 GetZMotion() const
		{
			return ZMotion;
		}

		float GetLimit() const
		{
			return Limit;
		}

		bool GetUseAdvanced() const
		{
			return UseAdvanced;
		}

		bool GetSoftConstraint() const
		{
			return SoftConstraint;
		}

		float GetStiffness() const
		{
			return Stiffness;
		}

		float GetDamping() const
		{
			return Damping;
		}

		void SetXMotion(uint8 InXMotion)
		{
			XMotion = InXMotion;
		}

		void SetYMotion(uint8 InYMotion)
		{
			YMotion = InYMotion;
		}

		void SetZMotion(uint8 InZMotion)
		{
			ZMotion = InZMotion;
		}

		void SetLimit(float InLimit)
		{
			Limit = InLimit;
		}

		void SetUseAdvanced(bool InUseAdvanced)
		{
			UseAdvanced = InUseAdvanced;
		}

		void SetSoftConstraint(bool InSoftConstraint)
		{
			SoftConstraint = InSoftConstraint;
		}

		void SetStiffness(float InStiffness)
		{
			Stiffness = InStiffness;
		}

		void SetDamping(float InDamping)
		{
			Damping = InDamping;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			XMotion = JsonObject->GetNumberField(TEXT("x_motion"));

			YMotion = JsonObject->GetNumberField(TEXT("y_motion"));

			ZMotion = JsonObject->GetNumberField(TEXT("z_motion"));

			Limit = JsonObject->GetNumberField(TEXT("limit"));

			UseAdvanced = JsonObject->GetBoolField(TEXT("use_advanced"));

			SoftConstraint = JsonObject->GetBoolField(TEXT("soft_constraint"));

			Stiffness = JsonObject->GetNumberField(TEXT("stiffness"));

			Damping = JsonObject->GetNumberField(TEXT("damping"));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			XMotion = BsonObject->GetNumberField(TEXT("x_motion"));

			YMotion = BsonObject->GetNumberField(TEXT("y_motion"));

			ZMotion = BsonObject->GetNumberField(TEXT("z_motion"));

			Limit = BsonObject->GetNumberField(TEXT("limit"));

			UseAdvanced = BsonObject->GetBoolField(TEXT("use_advanced"));

			SoftConstraint = BsonObject->GetBoolField(TEXT("soft_constraint"));

			Stiffness = BsonObject->GetNumberField(TEXT("stiffness"));

			Damping = BsonObject->GetNumberField(TEXT("damping"));

		}

		static LinearLimits GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			LinearLimits Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static LinearLimits GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			LinearLimits Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual FString ToString() const override
		{
			return "LinearLimits {x_motion = " + FString::FromInt(XMotion) +
				", y_motion = " + FString::FromInt(YMotion) +
				", z_motion = " + FString::FromInt(ZMotion) +
				", limit = " + FString::SanitizeFloat(Limit) +
				", use_advanced = " + (UseAdvanced ? FString("True") : FString("False")) +
				", soft_constraint = " + (SoftConstraint ? FString("True") : FString("False")) +
				", stiffness = " + FString::SanitizeFloat(Stiffness) +
				", damping = " + FString::SanitizeFloat(Damping) + "}";
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetNumberField(TEXT("x_motion"), XMotion);
			Object->SetNumberField(TEXT("y_motion"), YMotion);
			Object->SetNumberField(TEXT("z_motion"), ZMotion);
			Object->SetNumberField(TEXT("limit"), Limit);
			Object->SetBoolField(TEXT("use_advanced"), UseAdvanced);
			Object->SetBoolField(TEXT("soft_constraint"), SoftConstraint);
			Object->SetNumberField(TEXT("stiffness"), Stiffness);
			Object->SetNumberField(TEXT("damping"), Damping);
			return Object;
		}
		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetNumberField(TEXT("x_motion"), XMotion);
			Object->SetNumberField(TEXT("y_motion"), YMotion);
			Object->SetNumberField(TEXT("z_motion"), ZMotion);
			Object->SetNumberField(TEXT("limit"), Limit);
			Object->SetBoolField(TEXT("use_advanced"), UseAdvanced);
			Object->SetBoolField(TEXT("soft_constraint"), SoftConstraint);
			Object->SetNumberField(TEXT("stiffness"), Stiffness);
			Object->SetNumberField(TEXT("damping"), Damping);
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