// Copyright 2016-2019 Chris Conway (Koderz). All Rights Reserved.

#include "RuntimeMeshActor.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeMeshComponentPlugin.h"
#include "Engine/CollisionProfile.h"



ARuntimeMeshActor::ARuntimeMeshActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCanBeDamaged = false;

	RuntimeMeshComponent = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("RuntimeMeshComponent0"));
	RuntimeMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	RuntimeMeshComponent->Mobility = EComponentMobility::Static;

	RuntimeMeshComponent->SetGenerateOverlapEvents(false);
	RootComponent = RuntimeMeshComponent;
}

ERuntimeMeshMobility ARuntimeMeshActor::GetRuntimeMeshMobility()
{
	if (RuntimeMeshComponent)
	{
		return RuntimeMeshComponent->GetRuntimeMeshMobility();
	}
	return ERuntimeMeshMobility::Static;
}

void ARuntimeMeshActor::SetRuntimeMeshMobility(ERuntimeMeshMobility NewMobility)
{
	if (RuntimeMeshComponent)
	{
		RuntimeMeshComponent->SetRuntimeMeshMobility(NewMobility);
	}
}

void ARuntimeMeshActor::SetMobility(EComponentMobility::Type InMobility)
{
	if (RuntimeMeshComponent)
	{
		RuntimeMeshComponent->SetMobility(InMobility);
	}
}

EComponentMobility::Type ARuntimeMeshActor::GetMobility()
{
	if (RuntimeMeshComponent)
	{
		return RuntimeMeshComponent->Mobility;
	}
	return EComponentMobility::Static;
}

void ARuntimeMeshActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	GenerateMeshes();
}

void ARuntimeMeshActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARuntimeMeshActor::GenerateMeshes_Implementation()
{

}
