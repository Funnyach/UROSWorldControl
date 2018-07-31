#pragma once

#include "ROSBridgeSrv.h"

#include "geometry_msgs/Pose.h"
#include "world_control_msgs/msgs/Tag.h"
#include "world_control_msgs/msgs/PhysicsProperties.h"


class UROSBRIDGE_API FROSSpawnModelSrv : public FROSBridgeSrv
{
public:
	FROSSpawnModelSrv()
	{
		SrvType = TEXT("world_control_msgs/SpawnModel");
	}

	class Request : public SrvRequest
	{
	private:
		FString Name;
		geometry_msgs::Pose Pose;
		FString Id;
		TArray<world_control_msgs::Tag> Tags;
		FString Path;
		FString ActorLabel;
		world_control_msgs::PhysicsProperties PhysicsProperties;
		TArray<FString> MaterialNames;
		TArray<FString> MaterialPaths;
		FString ParentId;
					
	public:
		Request(){ }
		Request(FString InName,
			geometry_msgs::Pose InPose,
			FString InId,
			TArray<world_control_msgs::Tag> InTags,
			FString InPath,
			FString InActorLabel,
			world_control_msgs::PhysicsProperties InPhysicsProperties,
			TArray<FString> InMaterialNames,
			TArray<FString> InMaterialPaths,
			FString InParentId)
			:
			Name(InName),
			Pose(InPose),
			Id(InId),
			Tags(InTags),
			Path(InPath),
			ActorLabel(InActorLabel),
			PhysicsProperties(InPhysicsProperties),
			MaterialNames(InMaterialNames),
			MaterialPaths(InMaterialPaths),
			ParentId(InParentId) { }
			
			
		// Getters 
		FString GetName() const { return Name; }
		geometry_msgs::Pose GetPose() const { return Pose; }
		FString GetId() const { return Id; }
		TArray<world_control_msgs::Tag> GetTags() const { return Tags; }
		FString GetPath() const { return Path; }
		FString GetActorLabel() const { return ActorLabel; }
		world_control_msgs::PhysicsProperties GetPhysicsProperties() const { return PhysicsProperties; }
		TArray<FString> GetMaterialNames() const { return MaterialNames; }
		TArray<FString> GetMaterialPaths() const { return MaterialPaths; }
		FString GetParentId() const { return ParentId; }
			
			
		// Setters 
		void SetName(FString InName) { Name = InName; }
		void SetPose(geometry_msgs::Pose InPose) { Pose = InPose; }
		void SetId(FString InId) { Id = InId; }
		void SetTags(TArray<world_control_msgs::Tag> InTags) { Tags = InTags; }
		void SetPath(FString InPath) { Path = InPath; }
		void SetActorLabel(FString InActorLabel) { ActorLabel = InActorLabel; }
		void SetPhysicsProperties(world_control_msgs::PhysicsProperties InPhysicsProperties) { PhysicsProperties = InPhysicsProperties; }
		void SetMaterialNames(TArray<FString> InMaterialNames) { MaterialNames = InMaterialNames; }
		void SetMaterialPaths(TArray<FString> InMaterialPaths) { MaterialPaths = InMaterialPaths; }
		void SetParentId(FString InParentId) { ParentId = InParentId; }
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			TArray<TSharedPtr<FJsonValue>> ValuesPtrArr;

			Name = JsonObject->GetStringField(TEXT("name"));

			Pose = geometry_msgs::Pose::GetFromJson(JsonObject->GetObjectField(TEXT("pose")));

			Id = JsonObject->GetStringField(TEXT("id"));

			Tags.Empty();
			ValuesPtrArr = JsonObject->GetArrayField(TEXT("tags"));
			for (auto &ptr : ValuesPtrArr)
				Tags.Add(world_control_msgs::Tag::GetFromJson(ptr->AsObject()));

			Path = JsonObject->GetStringField(TEXT("path"));

			ActorLabel = JsonObject->GetStringField(TEXT("actor_label"));

			PhysicsProperties = world_control_msgs::PhysicsProperties::GetFromJson(JsonObject->GetObjectField(TEXT("physics_properties")));

			MaterialNames.Empty();
			ValuesPtrArr = JsonObject->GetArrayField(TEXT("material_names"));
			for (auto &ptr : ValuesPtrArr)
				MaterialNames.Add(ptr->AsString());

			MaterialPaths.Empty();
			ValuesPtrArr = JsonObject->GetArrayField(TEXT("material_paths"));
			for (auto &ptr : ValuesPtrArr)
				MaterialPaths.Add(ptr->AsString());

			ParentId = JsonObject->GetStringField(TEXT("parent_id"));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			TArray<TSharedPtr<FBsonValue>> ValuesPtrArr;

			Name = BsonObject->GetStringField(TEXT("name"));

			Pose = geometry_msgs::Pose::GetFromBson(BsonObject->GetObjectField(TEXT("pose")));

			Id = BsonObject->GetStringField(TEXT("id"));

			Tags.Empty();
			ValuesPtrArr = BsonObject->GetArrayField(TEXT("tags"));
			for (auto &ptr : ValuesPtrArr)
				Tags.Add(world_control_msgs::Tag::GetFromBson(ptr->AsObject()));

			Path = BsonObject->GetStringField(TEXT("path"));

			ActorLabel = BsonObject->GetStringField(TEXT("actor_label"));

			PhysicsProperties = world_control_msgs::PhysicsProperties::GetFromBson(BsonObject->GetObjectField(TEXT("physics_properties")));

			MaterialNames.Empty();
			ValuesPtrArr = BsonObject->GetArrayField(TEXT("material_names"));
			for (auto &ptr : ValuesPtrArr)
				MaterialNames.Add(ptr->AsString());

			MaterialPaths.Empty();
			ValuesPtrArr = BsonObject->GetArrayField(TEXT("material_paths"));
			for (auto &ptr : ValuesPtrArr)
				MaterialPaths.Add(ptr->AsString());

			ParentId = BsonObject->GetStringField(TEXT("parent_id"));

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

			Object->SetStringField(TEXT("name"), Name);

			Object->SetObjectField(TEXT("pose"), Pose.ToJsonObject());

			Object->SetStringField(TEXT("id"), Id);

			TArray<TSharedPtr<FJsonValue>> TagsArray;
			for (auto &val : Tags)
				TagsArray.Add(MakeShareable(new FJsonValueObject(val.ToJsonObject())));
			Object->SetArrayField(TEXT("tags"), TagsArray);

			Object->SetStringField(TEXT("path"), Path);

			Object->SetStringField(TEXT("actor_label"), ActorLabel);

			Object->SetObjectField(TEXT("physics_properties"), PhysicsProperties.ToJsonObject());

			TArray<TSharedPtr<FJsonValue>> MaterialNamesArray;
			for (auto &val : MaterialNames)
				MaterialNamesArray.Add(MakeShareable(new FJsonValueString(val)));
			Object->SetArrayField(TEXT("material_names"), MaterialNamesArray);

			TArray<TSharedPtr<FJsonValue>> MaterialPathsArray;
			for (auto &val : MaterialPaths)
				MaterialPathsArray.Add(MakeShareable(new FJsonValueString(val)));
			Object->SetArrayField(TEXT("material_paths"), MaterialPathsArray);

			Object->SetStringField(TEXT("parent_id"), ParentId);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("name"), Name);

			Object->SetObjectField(TEXT("pose"), Pose.ToBsonObject());

			Object->SetStringField(TEXT("id"), Id);

			TArray<TSharedPtr<FBsonValue>> TagsArray;
			for (auto &val : Tags)
				TagsArray.Add(MakeShareable(new FBsonValueObject(val.ToBsonObject())));
			Object->SetArrayField(TEXT("tags"), TagsArray);

			Object->SetStringField(TEXT("path"), Path);

			Object->SetStringField(TEXT("actor_label"), ActorLabel);

			Object->SetObjectField(TEXT("physics_properties"), PhysicsProperties.ToBsonObject());

			TArray<TSharedPtr<FBsonValue>> MaterialNamesArray;
			for (auto &val : MaterialNames)
				MaterialNamesArray.Add(MakeShareable(new FBsonValueString(val)));
			Object->SetArrayField(TEXT("material_names"), MaterialNamesArray);

			TArray<TSharedPtr<FBsonValue>> MaterialPathsArray;
			for (auto &val : MaterialPaths)
				MaterialPathsArray.Add(MakeShareable(new FBsonValueString(val)));
			Object->SetArrayField(TEXT("material_paths"), MaterialPathsArray);

			Object->SetStringField(TEXT("parent_id"), ParentId);

			return Object;

		}
	};
		
	class Response : public SrvResponse
	{
	private:
		FString Id;
		bool Success;
			
			
	public:
		Response(){ }
		Response(FString InId,
			bool InSuccess)
			:
			Id(InId),
			Success(InSuccess) { }
			
			
		// Getters 
		FString GetId() const { return Id; }
		bool GetSuccess() const { return Success; }
			
			
		// Setters 
		void SetId(FString InId) { Id = InId; }
		void SetSuccess(bool InSuccess) { Success = InSuccess; }
			
			
		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Id = JsonObject->GetStringField(TEXT("id"));

			Success = JsonObject->GetBoolField(TEXT("success"));

		}
			
		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			Id = BsonObject->GetStringField(TEXT("id"));

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

			Object->SetStringField(TEXT("id"), Id);

			Object->SetBoolField(TEXT("success"), Success);

			return Object;

		}
			
		virtual TSharedPtr<FBsonObject> ToBsonObject() const
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetStringField(TEXT("id"), Id);

			Object->SetBoolField(TEXT("success"), Success);

			return Object;

		}
	};
		
};
	
