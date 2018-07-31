#pragma once

#include "ROSBridgeSrv.h"

class UROSBRIDGE_API FROSDeleteModelSrv : public FROSBridgeSrv
{
public:
	FROSDeleteModelSrv()
	{
		SrvType = TEXT("world_control_msgs/DeleteModel");
	}

	class Request : public SrvRequest
	{
	private:
		FString Id;
					
	public:
		Request(){ }
		Request(FString InId)
			:
			Id(InId) { }
			
			
		// Getters 
		FString GetId() const { return Id; }
			
			
		// Setters 
		void SetId(FString InId) { Id = InId; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Id = JsonObject->GetStringField(TEXT("id"));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			Id = BsonObject->GetStringField(TEXT("id"));

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
			return "FROSDeleteModelSrv:Request {id = " + Id + "}";
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetStringField(TEXT("id"), Id);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("id"), Id);

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
			return "FROSDeleteModelSrv:Response {success = " + (Success ? FString("True") : FString("False")) + "}";
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