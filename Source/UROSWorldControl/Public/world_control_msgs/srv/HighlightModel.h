#pragma once

#include "ROSBridgeSrv.h"

class UROSBRIDGE_API FROSHighlightModelSrv : public FROSBridgeSrv
{
public:
	FROSHighlightModelSrv()
	{
		SrvType = TEXT("world_control_msgs/HighlightModel");
	}

	class Request : public SrvRequest
	{
	private:
		uint8 None = 0;
		uint8 Black = 1;
		uint8 Red = 2;
		uint8 Blue = 3;
		uint8 Green = 4;
		uint8 Yellow = 5;
		FString Id;
		uint8 Color;
					
	public:
		Request(){ }
		Request(uint8 InNone,
			uint8 InBlack,
			uint8 InRed,
			uint8 InBlue,
			uint8 InGreen,
			uint8 InYellow,
			FString InId,
			uint8 InColor)
			:
			None(InNone),
			Black(InBlack),
			Red(InRed),
			Blue(InBlue),
			Green(InGreen),
			Yellow(InYellow),
			Id(InId),
			Color(InColor) { }
			
			
		// Getters 
		uint8 GetNone() const { return None; }
		uint8 GetBlack() const { return Black; }
		uint8 GetRed() const { return Red; }
		uint8 GetBlue() const { return Blue; }
		uint8 GetGreen() const { return Green; }
		uint8 GetYellow() const { return Yellow; }
		FString GetId() const { return Id; }
		uint8 GetColor() const { return Color; }
			
			
		// Setters 
		void SetNone(uint8 InNone) { None = InNone; }
		void SetBlack(uint8 InBlack) { Black = InBlack; }
		void SetRed(uint8 InRed) { Red = InRed; }
		void SetBlue(uint8 InBlue) { Blue = InBlue; }
		void SetGreen(uint8 InGreen) { Green = InGreen; }
		void SetYellow(uint8 InYellow) { Yellow = InYellow; }
		void SetId(FString InId) { Id = InId; }
		void SetColor(uint8 InColor) { Color = InColor; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			None = JsonObject->GetNumberField(TEXT("none"));

			Black = JsonObject->GetNumberField(TEXT("black"));

			Red = JsonObject->GetNumberField(TEXT("red"));

			Blue = JsonObject->GetNumberField(TEXT("blue"));

			Green = JsonObject->GetNumberField(TEXT("green"));

			Yellow = JsonObject->GetNumberField(TEXT("yellow"));

			Id = JsonObject->GetStringField(TEXT("id"));

			Color = JsonObject->GetNumberField(TEXT("color"));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			None = BsonObject->GetNumberField(TEXT("none"));

			Black = BsonObject->GetNumberField(TEXT("black"));

			Red = BsonObject->GetNumberField(TEXT("red"));

			Blue = BsonObject->GetNumberField(TEXT("blue"));

			Green = BsonObject->GetNumberField(TEXT("green"));

			Yellow = BsonObject->GetNumberField(TEXT("yellow"));

			Id = BsonObject->GetStringField(TEXT("id"));

			Color = BsonObject->GetNumberField(TEXT("color"));

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

			Object->SetNumberField(TEXT("none"), None);

			Object->SetNumberField(TEXT("black"), Black);

			Object->SetNumberField(TEXT("red"), Red);

			Object->SetNumberField(TEXT("blue"), Blue);

			Object->SetNumberField(TEXT("green"), Green);

			Object->SetNumberField(TEXT("yellow"), Yellow);

			Object->SetStringField(TEXT("id"), Id);

			Object->SetNumberField(TEXT("color"), Color);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetNumberField(TEXT("none"), None);

			Object->SetNumberField(TEXT("black"), Black);

			Object->SetNumberField(TEXT("red"), Red);

			Object->SetNumberField(TEXT("blue"), Blue);

			Object->SetNumberField(TEXT("green"), Green);

			Object->SetNumberField(TEXT("yellow"), Yellow);

			Object->SetStringField(TEXT("id"), Id);

			Object->SetNumberField(TEXT("color"), Color);

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