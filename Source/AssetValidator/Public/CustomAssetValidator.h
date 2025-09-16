// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "CustomAssetValidator.generated.h"

UCLASS()
class ASSETVALIDATOR_API UCustomAssetValidator : public UEditorValidatorBase
{
	GENERATED_BODY()

public:

	UCustomAssetValidator();
	
	virtual bool CanValidateAsset_Implementation(UObject* InAsset) const override;
	virtual EDataValidationResult ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors) override;
	
};
