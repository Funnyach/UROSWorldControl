#pragma once

#include "ROSBridgeMsg.h"


namespace world_control_msgs
{
	class Tag : public FROSBridgeMsg
	{
		FString TagType;
		FString Key;
		FString Value;
	public:
		Tag()
		{
			MsgType = "world_control_msgs/Tag";
		}

		Tag
		(
			FString InTagType,
			FString InKey,
			FString InValue
		):
			TagType(InTagType),
			Key(InKey),
			Value(InValue)
		{
			MsgType = "world_control_msgs/Tag";
		}

		~Tag() override {}

		FString GetTagType() const
		{
			return TagType;
		}

		FString GetKey() const
		{
			return Key;
		}

		FString GetValue() const
		{
			return Value;
		}

		void SetTagType(FString InTagType)
		{
			TagType = InTagType;
		}

		void SetKey(FString InKey)
		{
			Key = InKey;
		}

		void SetValue(FString InValue)
		{
			Value = InValue;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			TagType = JsonObject->GetStringField(TEXT("tag_type"));

			Key = JsonObject->GetStringField(TEXT("key"));

			Value = JsonObject->GetStringField(TEXT("value"));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			TagType = BsonObject->GetStringField(TEXT("tag_type"));

			Key = BsonObject->GetStringField(TEXT("key"));

			Value = BsonObject->GetStringField(TEXT("value"));

		}

		static Tag GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			Tag Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static Tag GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			Tag Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetStringField(TEXT("tag_type"), TagType);
			Object->SetStringField(TEXT("key"), Key);
			Object->SetStringField(TEXT("value"), Value);
			return Object;
		}
		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("tag_type"), TagType);
			Object->SetStringField(TEXT("key"), Key);
			Object->SetStringField(TEXT("value"), Value);
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