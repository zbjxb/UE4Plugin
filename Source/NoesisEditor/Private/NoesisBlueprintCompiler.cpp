////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintCompiler.h"

// NoesisEditor includes
#include "NoesisBlueprintCompilerContext.h"

bool FNoesisBlueprintCompiler::CanCompile(const UBlueprint* Blueprint)
{
	return Blueprint->IsA(UNoesisBlueprint::StaticClass());
}

void FNoesisBlueprintCompiler::PreCompile(UBlueprint* Blueprint)
{
}

void FNoesisBlueprintCompiler::Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompilerOptions, FCompilerResultsLog& Results, TArray<UObject*>* ObjLoaded)
{
	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	FNoesisBlueprintCompilerContext Compiler(NoesisBlueprint, Results, CompilerOptions, ObjLoaded);
	Compiler.Compile();
	check(Compiler.NewClass);
}

void FNoesisBlueprintCompiler::PostCompile(UBlueprint* Blueprint)
{
}
