set vsExcutor="%VS140COMNTOOLS%..\IDE\devenv.exe"
%vsExcutor% .\CPPTest.sln /Project "CPPTest" /build "Debug|Win32|/D _MY_DEBUG_" /out Debug.native.log

.\Debug\CPPTest

pause