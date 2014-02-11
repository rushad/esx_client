@call config.cmd
wsdl2h -o gsoap/vimService.h -t src/wsdl/typemap.dat src/wsdl/vimService.wsdl
soapcpp2 -C -i -L -x -I%GSOAP_INCLUDE_PATH% -dgsoap gsoap/vimService.h