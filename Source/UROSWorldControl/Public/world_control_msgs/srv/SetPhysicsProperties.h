#pragma once

#include "ROSBridgeSrv.h"

#include "world_control_msgs/msgs/PhysicsProperties.h"


class UROSBRIDGE_API FROSSetPhysicsPropertiesSrv : public FROSBridgeSrv
{
public:
	FROSSetPhysicsPropertiesSrv()
	{
		SrvType = TEXT("world_control_msgs/SetPhysicsProperties");
	}

	class Request : public SrvRequest
	{
	private:
		FString Id;
		world_control_msgs::PhysicsProperties PhysicsProperties;
					
	public:
		Request(){ }
		Request(FString InId,
			world_control_msgs::PhysicsProperties InPhysicsProperties)
			:
			Id(InId),
			PhysicsProperties(InPhysicsProperties) { }
			
			
		// Getters 
		FString GetId() const { return Id; }
		world_control_msgs::PhysicsProperties GetPhysicsProperties() const { return PhysicsProperties; }
			
			
		// Setters 
		void SetId(FString InId) { Id = InId; }
		void SetPhysicsProperties(world_control_msgs::PhysicsProperties InPhysicsProperties) { PhysicsProperties = InPhysicsProperties; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Id = JsonObject->GetStringField(TEXT("id"));

			PhysicsProperties = world_control_msgs::PhysicsProperties::GetFromJson(JsonObject->GetObjectField(TEXT("physics_properties")));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			Id = BsonObject->GetStringField(TEXT("id"));

			PhysicsProperties = world_control_msgs::PhysicsProperties::GetFromBson(BsonObject->GetObjectField(TEXT("physics_properties")));

		}
			
		static Request GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			Request Req;
			Req.FromJson(JsonObject);
			return Req;
		}
			
		static Request GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			Request Req;
			Req.FromBson(BsonObject);
			return Req;
		}
			
		FString ToString() const override
		{
			return "FROSSetPhysicsPropertiesSrv:Request {id = " + Id +
				", physics_properties = " + PhysicsProperties.ToString() + "}";
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetStringField(TEXT("id"), Id);

			Object->SetObjectField(TEXT("physics_properties"), PhysicsProperties.ToJsonObject());

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("id"), Id);

			Object->SetObjectField(TEXT("physics_properties"), PhysicsProperties.ToBsonObject());

			return Object;

		}
	};
		
	class Response : public SrvResponse
	{
	private:
		bool Success;
			
			
	public:
		Response(){ }
		Response(bool InSuccess)
			:
			Success(InSuccess) { }
			
			
		// Getters 
		bool GetSuccess() const { return Success; }
			
			
		// Setters 
		void SetSuccess(bool InSuccess) { Success = InSuccess; }
			
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Success = JsonObject->GetBoolField(TEXT("success"));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			Success = BsonObject->GetBoolField(TEXT("success"));

		}
			
		static Response GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			Response Resp;
			Resp.FromJson(JsonObject);
			return Resp;
		}
			
		static Response GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			Response Resp; 
			Resp.FromBson(BsonObject);
			return Resp;
		}			
			
		FString ToString() const override
		{
			return "FROSSetModelPoseSrv:Response {success = " + (Success ? FString("True") : FString("False")) + "}";
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetBoolField(TEXT("success"), Success);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetBoolField(TEXT("success"), Success);

			return Object;

		}
	};
		
};