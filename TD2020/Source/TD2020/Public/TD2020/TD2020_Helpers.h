#pragma once

#include "TD2020.h"
/*
template<typename TEnum>
static FORCEINLINE FString GetEnumValueToString(const FString& Name, TEnum Value)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!enumPtr)
	{
		return FString("Invalid");
	}

	FString Str = enumPtr->GetNameByValue((int64)Value).ToString();
	// parse so that we 
	TArray<FString> Parsed;

	Str.ParseIntoArray(Parsed, TEXT(":"), false);
	if (Parsed.Num() > 1) {
		return Parsed[2];//return only type-> MYENUM::TYPE
	}
	else {
		// else we got only type-> TYPE
		return Str;
	}


	
}
*/