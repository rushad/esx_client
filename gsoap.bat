@call config.cmd
@wsdl2h -f -qSoap -o gsoap/vim.h src/wsdl/vim.wsdl
@soapcpp2 -C -L -x -I%GSOAP_INCLUDE_PATH% -dgsoap gsoap/vim.h
