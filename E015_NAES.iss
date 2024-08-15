#define MyAppName "E015_NAES"
; Version
#define MyAppVersion "0.01"
#define MyAppPublisher "HGT"
#define MyAppURL "https://www.example.com/"
#define MyAppExeName "NAES.exe"
#define MyAppAssocName MyAppName + " File"
#define MyAppAssocExt ".myp"
#define MyAppAssocKey StringChange(MyAppAssocName, " ", "") + MyAppAssocExt

[Setup]
AppId={{80B8A783-48E2-4280-9F6F-CC892E446AE1}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
SetupIconFile=D:\hgt-platform\application\projects\E015_NAES\build\logo.ico
ChangesAssociations=yes
DisableProgramGroupPage=yes
PrivilegesRequired=admin
UsePreviousAppDir=no

OutputDir=C:\Users\Administrator\Desktop
; output file name
OutputBaseFilename=E015_NAES-0.01
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\d3dcompiler_47.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\libEGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\libEGLd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\libGLESv2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\libGLESv2d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\opengl32sw.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DAnimation.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DAnimationd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DCore.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DCored.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DExtras.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DExtrasd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DInput.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DInputd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DLogic.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DLogicd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuick.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickAnimation.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickAnimationd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickExtras.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickExtrasd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickInput.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickInputd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickRender.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickRenderd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickScene2D.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DQuickScene2Dd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DRender.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt53DRenderd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Bluetooth.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Bluetoothd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Concurrent.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Concurrentd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Cored.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5DBus.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5DBusd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Designer.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5DesignerComponents.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5DesignerComponentsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Designerd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Gamepad.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Gamepadd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Guid.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Help.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Helpd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Location.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Locationd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Multimedia.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Multimediad.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5MultimediaQuick_p.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5MultimediaQuick_pd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5MultimediaWidgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5MultimediaWidgetsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Network.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Networkd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Nfc.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Nfcd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5OpenGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5OpenGLd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Positioning.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Positioningd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5PrintSupport.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5PrintSupportd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Qml.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Qmld.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Quick.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickControls2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickControls2d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Quickd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickParticles.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickParticlesd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickTemplates2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickTemplates2d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickTest.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickTestd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickWidgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5QuickWidgetsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Scxml.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Scxmld.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Sensors.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Sensorsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5SerialBus.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5SerialBusd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5SerialPort.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5SerialPortd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Sql.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Sqld.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Svgd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Test.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Testd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WebChannel.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WebChanneld.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WebSockets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WebSocketsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WebView.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WebViewd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Widgetsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WinExtras.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5WinExtrasd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Xml.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5Xmld.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5XmlPatterns.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\foundation\x86-win32\trolltech\qt-5.9.4\bin\Qt5XmlPatternsd.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\hgt-platform\application\projects\E015_NAES\build\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\data\*"; DestDir: "{app}\data"; Flags: ignoreversion recursesubdirs createallsubdirs   
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\img\*"; DestDir: "{app}\img"; Flags: ignoreversion recursesubdirs createallsubdirs  
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\keyboard\*"; DestDir: "{app}\keyboard"; Flags: ignoreversion recursesubdirs createallsubdirs    
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\lang\*"; DestDir: "{app}\lang"; Flags: ignoreversion recursesubdirs createallsubdirs   
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\QPCRDatabase\*"; DestDir: "{app}\QPCRDatabase"; Flags: ignoreversion recursesubdirs createallsubdirs 
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\qss\*"; DestDir: "{app}\qss"; Flags: ignoreversion recursesubdirs createallsubdirs 
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\Solution\*"; DestDir: "{app}\Solution"; Flags: ignoreversion recursesubdirs createallsubdirs    
;Source: "D:\hgt-platform\application\projects\E015_NAES\build\ttf\*"; DestDir: "{app}\ttf"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Dirs]
;Name: "{app}\YourFolder"; Permissions: everyone-modify

[Registry]
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocExt}\OpenWithProgids"; ValueType: string; ValueName: "{#MyAppAssocKey}"; ValueData: ""; Flags: uninsdeletevalue
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}"; ValueType: string; ValueName: ""; ValueData: "{#MyAppAssocName}"; Flags: uninsdeletekey
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\{#MyAppExeName},0"
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\{#MyAppExeName}"" ""%1"""
Root: HKA; Subkey: "Software\Classes\Applications\{#MyAppExeName}\SupportedTypes"; ValueType: string; ValueName: ".myp"; ValueData: ""

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; IconFilename: {app}\logo.ico; 
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; IconFilename: {app}\logo.ico ;

;[Run]
;Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent 

