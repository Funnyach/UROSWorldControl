#pragma once

#include "ROSBridgeMsg.h"

#include "world_control_msgs/msgs/LinearLimits.h"
#include "world_control_msgs/msgs/AngularLimits.h"

namespace world_control_msgs
{
	class PhysicsConstraintDetails : public FROSBridgeMsg
	{
		FString IdFirstModel;
		FString IdSecondModel;
		bool DisableCollision;
		bool EnableProjection;
		float ProjectionLinearTolerance;
		float ProjectionAngularTolerance;
		bool ParentDominates;
		world_control_msgs::LinearLimits LinearLimits;
		world_control_msgs::AngularLimits AngularLimits;
	public:
		PhysicsConstraintDetails()
		{
			MsgType = "world_control_msgs/PhysicsConstraintDetails";
		}

		PhysicsConstraintDetails
		(
			FString InIdFirstModel,
			FString InIdSecondModel,
			bool InDisableCollision,
			bool InEnableProjection,
			float InProjectionLinearTolerance,
			float InProjectionAngularTolerance,
			bool InParentDominates,
			world_control_msgs::LinearLimits InLinearLimits,
			world_control_msgs::AngularLimits InAngularLimits
		):
			IdFirstModel(InIdFirstModel),
			IdSecondModel(InIdSecondModel),
			DisableCollision(InDisableCollision),
			EnableProjection(InEnableProjection),
			ProjectionLinearTolerance(InProjectionLinearTolerance),
			ProjectionAngularTolerance(InProjectionAngularTolerance),
			ParentDominates(InParentDominates),
			LinearLimits(InLinearLimits),
			AngularLimits(InAngularLimits)
		{
			MsgType = "world_control_msgs/PhysicsConstraintDetails";
		}

		~PhysicsConstraintDetails() override {}

		FString GetIdFirstModel() const
		{
			return IdFirstModel;
		}

		FString GetIdSecondModel() const
		{
			return IdSecondModel;
		}

		bool GetDisableCollision() const
		{
			return DisableCollision;
		}

		bool GetEnableProjection() const
		{
			return EnableProjection;
		}

		float GetProjectionLinearTolerance() const
		{
			return ProjectionLinearTolerance;
		}

		float GetProjectionAngularTolerance() const
		{
			return ProjectionAngularTolerance;
		}

		bool GetParentDominates() const
		{
			return ParentDominates;
		}

		world_control_msgs::LinearLimits GetLinearLimits() const
		{
			return LinearLimits;
		}

		world_control_msgs::AngularLimits GetAngularLimits() const
		{
			return AngularLimits;
		}

		void SetIdFirstModel(FString InIdFirstModel)
		{
			IdFirstModel = InIdFirstModel;
		}

		void SetIdSecondModel(FString InIdSecondModel)
		{
			IdSecondModel = InIdSecondModel;
		}

		void SetDisableCollision(bool InDisableCollision)
		{
			DisableCollision = InDisableCollision;
		}

		void SetEnableProjection(bool InEnableProjection)
		{
			EnableProjection = InEnableProjection;
		}

		void SetProjectionLinearTolerance(float InProjectionLinearTolerance)
		{
			ProjectionLinearTolerance = InProjectionLinearTolerance;
		}

		void SetProjectionAngularTolerance(float InProjectionAngularTolerance)
		{
			ProjectionAngularTolerance = InProjectionAngularTolerance;
		}

		void SetParentDominates(bool InParentDominates)
		{
			ParentDominates = InParentDominates;
		}

		void SetLinearLimits(world_control_msgs::LinearLimits InLinearLimits)
		{
			LinearLimits = InLinearLimits;
		}

		void SetAngularLimits(world_control_msgs::AngularLimits InAngularLimits)
		{
			AngularLimits = InAngularLimits;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			IdFirstModel = JsonObject->GetStringField(TEXT("id_first_model"));

			IdSecondModel = JsonObject->GetStringField(TEXT("id_second_model"));

			DisableCollision = JsonObject->GetBoolField(TEXT("disable_collision"));

			EnableProjection = JsonObject->GetBoolField(TEXT("enable_projection"));

			ProjectionLinearTolerance = JsonObject->GetNumberField(TEXT("projection_linear_tolerance"));

			ProjectionAngularTolerance = JsonObject->GetNumberField(TEXT("projection_angular_tolerance"));

			ParentDominates = JsonObject->GetBoolField(TEXT("parent_dominates"));

			LinearLimits = world_control_msgs::LinearLimits::GetFromJson(JsonObject->GetObjectField(TEXT("linear_limits")));

			AngularLimits = world_control_msgs::AngularLimits::GetFromJson(JsonObject->GetObjectField(TEXT("angular_limits")));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			IdFirstModel = BsonObject->GetStringField(TEXT("id_first_model"));

			IdSecondModel = BsonObject->GetStringField(TEXT("id_second_model"));

			DisableCollision = BsonObject->GetBoolField(TEXT("disable_collision"));

			EnableProjection = BsonObject->GetBoolField(TEXT("enable_projection"));

			ProjectionLinearTolerance = BsonObject->GetNumberField(TEXT("projection_linear_tolerance"));

			ProjectionAngularTolerance = BsonObject->GetNumberField(TEXT("projection_angular_tolerance"));

			ParentDominates = BsonObject->GetBoolField(TEXT("parent_dominates"));

			LinearLimits = world_control_msgs::LinearLimits::GetFromBson(BsonObject->GetObjectField(TEXT("linear_limits")));

			AngularLimits = world_control_msgs::AngularLimits::GetFromBson(BsonObject->GetObjectField(TEXT("angular_limits")));

		}

		static PhysicsConstraintDetails GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			PhysicsConstraintDetails Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static PhysicsConstraintDetails GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			PhysicsConstraintDetails Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetStringField(TEXT("id_first_model"), IdFirstModel);
			Object->SetStringField(TEXT("id_second_model"), IdSecondModel);
			Object->SetBoolField(TEXT("disable_collision"), DisableCollision);
			Object->SetBoolField(TEXT("enable_projection"), EnableProjection);
			Object->SetNumberField(TEXT("projection_linear_tolerance"), ProjectionLinearTolerance);
			Object->SetNumberField(TEXT("projection_angular_tolerance"), ProjectionAngularTolerance);
			Object->SetBoolField(TEXT("parent_dominates"), ParentDominates);
			Object->SetObjectField(TEXT("linear_limits"), LinearLimits.ToJsonObject());
			Object->SetObjectField(TEXT("angular_limits"), AngularLimits.ToJsonObject());
			return Object;
		}
		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("id_first_model"), IdFirstModel);
			Object->SetStringField(TEXT("id_second_model"), IdSecondModel);
			Object->SetBoolField(TEXT("disable_collision"), DisableCollision);
			Object->SetBoolField(TEXT("enable_projection"), EnableProjection);
			Object->SetNumberField(TEXT("projection_linear_tolerance"), ProjectionLinearTolerance);
			Object->SetNumberField(TEXT("projection_angular_tolerance"), ProjectionAngularTolerance);
			Object->SetBoolField(TEXT("parent_dominates"), ParentDominates);
			Object->SetObjectField(TEXT("linear_limits"), LinearLimits.ToBsonObject());
			Object->SetObjectField(TEXT("angular_limits"), AngularLimits.ToBsonObject());
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