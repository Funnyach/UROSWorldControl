#pragma once

#include "ROSBridgeSrv.h"

#include "world_control_msgs/msgs/PhysicsConstraintDetails.h"
#include "geometry_msgs/Pose.h"


class UROSBRIDGE_API FROSSpawnPhysicsConstraintSrv : public FROSBridgeSrv
{
public:
	FROSSpawnPhysicsConstraintSrv()
	{
		SrvType = TEXT("world_control_msgs/SpawnPhysicsConstraint");
	}

	class Request : public SrvRequest
	{
	private:
		world_control_msgs::PhysicsConstraintDetails ConstraintDetails;
		geometry_msgs::Pose Pose;
					
	public:
		Request(){ }
		Request(world_control_msgs::PhysicsConstraintDetails InConstraintDetails,
			geometry_msgs::Pose InPose)
			:
			ConstraintDetails(InConstraintDetails),
			Pose(InPose) { }
			
			
		// Getters 
		world_control_msgs::PhysicsConstraintDetails GetConstraintDetails() const { return ConstraintDetails; }
		geometry_msgs::Pose GetPose() const { return Pose; }
			
			
		// Setters 
		void SetConstraintDetails(world_control_msgs::PhysicsConstraintDetails InConstraintDetails) { ConstraintDetails = InConstraintDetails; }
		void SetPose(geometry_msgs::Pose InPose) { Pose = InPose; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			ConstraintDetails = world_control_msgs::PhysicsConstraintDetails::GetFromJson(JsonObject->GetObjectField(TEXT("constraint_details")));

			Pose = geometry_msgs::Pose::GetFromJson(JsonObject->GetObjectField(TEXT("pose")));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			ConstraintDetails = world_control_msgs::PhysicsConstraintDetails::GetFromBson(BsonObject->GetObjectField(TEXT("constraint_details")));

			Pose = geometry_msgs::Pose::GetFromBson(BsonObject->GetObjectField(TEXT("pose")));

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
			
//			### TOSTRING ###
			
		virtual TSharedPtr<FJsonObject> ToJsonObject() const
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetObjectField(TEXT("constraint_details"), ConstraintDetails.ToJsonObject());

			Object->SetObjectField(TEXT("pose"), Pose.ToJsonObject());

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetObjectField(TEXT("constraint_details"), ConstraintDetails.ToBsonObject());

			Object->SetObjectField(TEXT("pose"), Pose.ToBsonObject());

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
			
//			### TOSTRING ###
			
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