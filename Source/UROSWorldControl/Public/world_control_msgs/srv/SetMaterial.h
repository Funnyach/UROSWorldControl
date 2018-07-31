#pragma once

#include "ROSBridgeSrv.h"


class UROSBRIDGE_API FROSSetMaterialSrv : public FROSBridgeSrv
{
public:
	FROSSetMaterialSrv()
	{
		SrvType = TEXT("world_control_msgs/SetMaterial");
	}

	class Request : public SrvRequest
	{
	private:
		FString Id;
		TArray<FString> MaterialNames;
		TArray<FString> MaterialPaths;
					
	public:
		Request(){ }
		Request(FString InId,
			TArray<FString> InMaterialNames,
			TArray<FString> InMaterialPaths)
			:
			Id(InId),
			MaterialNames(InMaterialNames),
			MaterialPaths(InMaterialPaths) { }
			
			
		// Getters 
		FString GetId() const { return Id; }
		TArray<FString> GetMaterialNames() const { return MaterialNames; }
		TArray<FString> GetMaterialPaths() const { return MaterialPaths; }
			
			
		// Setters 
		void SetId(FString InId) { Id = InId; }
		void SetMaterialNames(TArray<FString> InMaterialNames) { MaterialNames = InMaterialNames; }
		void SetMaterialPaths(TArray<FString> InMaterialPaths) { MaterialPaths = InMaterialPaths; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			TArray<TSharedPtr<FJsonValue>> ValuesPtrArr;

			Id = JsonObject->GetStringField(TEXT("id"));

			MaterialNames.Empty();
			ValuesPtrArr = JsonObject->GetArrayField(TEXT("material_names"));
			for (auto &ptr : ValuesPtrArr)
				MaterialNames.Add(ptr->AsString());

			MaterialPaths.Empty();
			ValuesPtrArr = JsonObject->GetArrayField(TEXT("material_paths"));
			for (auto &ptr : ValuesPtrArr)
				MaterialPaths.Add(ptr->AsString());

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			TArray<TSharedPtr<FBsonValue>> ValuesPtrArr;

			Id = BsonObject->GetStringField(TEXT("id"));

			MaterialNames.Empty();
			ValuesPtrArr = BsonObject->GetArrayField(TEXT("material_names"));
			for (auto &ptr : ValuesPtrArr)
				MaterialNames.Add(ptr->AsString());

			MaterialPaths.Empty();
			ValuesPtrArr = BsonObject->GetArrayField(TEXT("material_paths"));
			for (auto &ptr : ValuesPtrArr)
				MaterialPaths.Add(ptr->AsString());

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

			Object->SetStringField(TEXT("id"), Id);

			TArray<TSharedPtr<FJsonValue>> MaterialNamesArray;
			for (auto &val : MaterialNames)
				MaterialNamesArray.Add(MakeShareable(new FJsonValueString(val)));
			Object->SetArrayField(TEXT("material_names"), MaterialNamesArray);

			TArray<TSharedPtr<FJsonValue>> MaterialPathsArray;
			for (auto &val : MaterialPaths)
				MaterialPathsArray.Add(MakeShareable(new FJsonValueString(val)));
			Object->SetArrayField(TEXT("material_paths"), MaterialPathsArray);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("id"), Id);

			TArray<TSharedPtr<FBsonValue>> MaterialNamesArray;
			for (auto &val : MaterialNames)
				MaterialNamesArray.Add(MakeShareable(new FBsonValueString(val)));
			Object->SetArrayField(TEXT("material_names"), MaterialNamesArray);

			TArray<TSharedPtr<FBsonValue>> MaterialPathsArray;
			for (auto &val : MaterialPaths)
				MaterialPathsArray.Add(MakeShareable(new FBsonValueString(val)));
			Object->SetArrayField(TEXT("material_paths"), MaterialPathsArray);

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