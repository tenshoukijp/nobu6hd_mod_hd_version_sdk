
#include "resource.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// アセンブリに関する一般情報は以下の属性セットをとおして制御されます。
// アセンブリに関連付けられている情報を変更するには、
// これらの属性値を変更してください。
//
[assembly:AssemblyTitleAttribute(L"天翔記 HD version 基盤MOD")];
[assembly:AssemblyDescriptionAttribute(L"天翔記 HD version 基盤MOD")];
[assembly:AssemblyConfigurationAttribute(L"")];
[assembly:AssemblyCompanyAttribute(L"")];
[assembly:AssemblyProductAttribute(L"天翔記 HD version 基盤MOD")];
[assembly:AssemblyCopyrightAttribute(L"Copyright (c) 2015 天翔記.jp")];
[assembly:AssemblyTrademarkAttribute(L"")];
[assembly:AssemblyCultureAttribute(L"")];

//
// アセンブリのバージョン情報は次の 4 つの値で構成されています:
//
//      Major Version
//      Minor Version
//      Build Number
//      Revision
//
// すべての値を指定するか、下のように '*' を使ってリビジョンおよびビルド番号を
// 既定値にすることができます:

[assembly:AssemblyVersionAttribute(STRING_VERSION)];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];