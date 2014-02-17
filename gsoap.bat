@call config.cmd
wsdl2h -o gsoap/vimService.h -t src/wsdl/typemap.dat src/wsdl/vimService.wsdl
soapcpp2 -C -x -L -I%GSOAP_INCLUDE_PATH% -dgsoap gsoap/vimService.h