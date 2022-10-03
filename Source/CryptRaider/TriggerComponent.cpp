// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent() {
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these
    // features off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    UE_LOG(LogTemp, Display, TEXT("Constructing."));
}

// Called when the game starts
void UTriggerComponent::BeginPlay() {
    Super::BeginPlay();

    UE_LOG(LogTemp, Display, TEXT("Trigger Component alive."));
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    TArray<AActor*> Actors;

    GetOverlappingActors(Actors);

    for (AActor* Actor : Actors) {
        if (Actor->ActorHasTag(AcceptableActorTag)) {
            FString ActorName = Actor->GetActorNameOrLabel();

            UE_LOG(LogTemp, Display, TEXT("unlocking"));
        }
    }
}