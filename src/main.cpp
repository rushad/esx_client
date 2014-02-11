#include "../gsoap/soapVimBindingProxy.h"
#include "../gsoap/VimBinding.nsmap"

int main() 
{
  VimBindingProxy vb(SOAP_XML_INDENT);
  strcpy(vb.endpoint, "https://10.27.11.125/sdk/vimService");
  vim__RetrieveServiceContentRequestType req;
  _vim__RetrieveServiceContentResponse resp;
  if (vb.RetrieveServiceContent(&req, &resp) != SOAP_OK)
    vb.soap_stream_fault(std::cerr); 
/*
  calcProxy service; 
  double result; 
  if (service.add(1.0, 2.0, result) == SOAP_OK) 
    std::cout << "The sum of 1.0 and 2.0 is " << result << std::endl; 
  else
    service.soap_stream_fault(std::cerr); 
  service.destroy(); // delete data and release memory
*/
  return 0; 
}
