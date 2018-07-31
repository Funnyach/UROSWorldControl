#pragma once

#include "ROSBridgeSrv.h"

class UROSBRIDGE_API  FROSAttachModelToParentSrv : public FROSBridgeSrv
{
public:
	FROSAttachModelToParentSrv()
	{
		SrvType = TEXT("world_control_msgs/AttachModelToParent");
	}

	class Request : public SrvRequest
	{
	private:
		FString ParentId;
		FString ChildId;
					
	public:
		Request(){ }
		Request(FString InParentId,
			FString InChildId)
			:
			ParentId(InParentId),
			ChildId(InChildId) { }
			
			
		// Getters 
		FString GetParentId() const { return ParentId; }
		FString GetChildId() const { return ChildId; }
			
			
		// Setters 
		void SetParentId(FString InParentId) { ParentId = InParentId; }
		void SetChildId(FString InChildId) { ChildId = InChildId; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			ParentId = JsonObject->GetStringField(TEXT("parent_id"));

			ChildId = JsonObject->GetStringField(TEXT("child_id"));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			ParentId = BsonObject->GetStringField(TEXT("parent_id"));

			ChildId = BsonObject->GetStringField(TEXT("child_id"));

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

			Object->SetStringField(TEXT("parent_id"), ParentId);

			Object->SetStringField(TEXT("child_id"), ChildId);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("parent_id"), ParentId);

			Object->SetStringField(TEXT("child_id"), ChildId);

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