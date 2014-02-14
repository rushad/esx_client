@call config.cmd
rem wsdl2h -o gsoap/vim.h -t src/wsdl/typemap.dat src/wsdl/vim.wsdl
rem soapcpp2 -C -i -x -L -I%GSOAP_INCLUDE_PATH% -dgsoap gsoap/vim.h