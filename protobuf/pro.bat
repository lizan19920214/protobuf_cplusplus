for /r %%i in (*.proto) do (
echo %%~ni.proto 	
protoc.exe -I=. --cpp_out=../TestProtobuf/TestProtobuf/protobufdes/  %%~ni.proto
)

pause