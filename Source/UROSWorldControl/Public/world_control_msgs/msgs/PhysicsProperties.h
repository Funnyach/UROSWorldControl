#pragma once

#include "ROSBridgeMsg.h"


namespace world_control_msgs
{
	class PhysicsProperties : public FROSBridgeMsg
	{
		bool SimulatePhysics;
		bool Gravity;
		bool GenerateOverlapEvents;
		float Mass;
	public:
		PhysicsProperties()
		{
			MsgType = "world_control_msgs/PhysicsProperties";
		}

		PhysicsProperties
		(
			bool InSimulatePhysics,
			bool InGravity,
			bool InGenerateOverlapEvents,
			float InMass
		):
			SimulatePhysics(InSimulatePhysics),
			Gravity(InGravity),
			GenerateOverlapEvents(InGenerateOverlapEvents),
			Mass(InMass)
		{
			MsgType = "world_control_msgs/PhysicsProperties";
		}

		~PhysicsProperties() override {}

		bool GetSimulatePhysics() const
		{
			return SimulatePhysics;
		}

		bool GetGravity() const
		{
			return Gravity;
		}

		bool GetGenerateOverlapEvents() const
		{
			return GenerateOverlapEvents;
		}

		float GetMass() const
		{
			return Mass;
		}

		void SetSimulatePhysics(bool InSimulatePhysics)
		{
			SimulatePhysics = InSimulatePhysics;
		}

		void SetGravity(bool InGravity)
		{
			Gravity = InGravity;
		}

		void SetGenerateOverlapEvents(bool InGenerateOverlapEvents)
		{
			GenerateOverlapEvents = InGenerateOverlapEvents;
		}

		void SetMass(float InMass)
		{
			Mass = InMass;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			SimulatePhysics = JsonObject->GetBoolField(TEXT("simulate_physics"));

			Gravity = JsonObject->GetBoolField(TEXT("gravity"));

			GenerateOverlapEvents = JsonObject->GetBoolField(TEXT("generate_overlap_events"));

			Mass = JsonObject->GetNumberField(TEXT("mass"));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			SimulatePhysics = BsonObject->GetBoolField(TEXT("simulate_physics"));

			Gravity = BsonObject->GetBoolField(TEXT("gravity"));

			GenerateOverlapEvents = BsonObject->GetBoolField(TEXT("generate_overlap_events"));

			Mass = BsonObject->GetNumberField(TEXT("mass"));

		}

		static PhysicsProperties GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			PhysicsProperties Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static PhysicsProperties GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			PhysicsProperties Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetBoolField(TEXT("simulate_physics"), SimulatePhysics);
			Object->SetBoolField(TEXT("gravity"), Gravity);
			Object->SetBoolField(TEXT("generate_overlap_events"), GenerateOverlapEvents);
			Object->SetNumberField(TEXT("mass"), Mass);
			return Object;
		}
		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetBoolField(TEXT("simulate_physics"), SimulatePhysics);
			Object->SetBoolField(TEXT("gravity"), Gravity);
			Object->SetBoolField(TEXT("generate_overlap_events"), GenerateOverlapEvents);
			Object->SetNumberField(TEXT("mass"), Mass);
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