#include "service_instance.h"
#include "session_manager.h"

#include "../gsoap/VimBinding.nsmap"

#include <iostream>

int main(int argc, char* argv[])
{
  GSoap::ServiceInstance service("https://10.27.11.125/sdk/vimService");
  GSoap::ServiceContent::Ptr content = service.RetrieveServiceContent();
  GSoap::SessionManager sessionManager(content->sessionManager);
  sessionManager.Login("root", "qwe123QWE");
  
//  std::cout << content->about->fullName << std::endl;
/*
  VimBindingProxy vim(SOAP_XML_INDENT);
  vim__ManagedObjectReference ManagedObjectRef;
  vim__RetrieveServiceContentRequestType RetrieveServiceContentReq;
  _vim__RetrieveServiceContentResponse RetrieveServiceContentRes;
  vim__ServiceContent *ServiceContent;
  vim__AboutInfo *AboutInfo;
     
  vim.soap_endpoint = "https://10.27.11.125/sdk/vimService";
  soap_ssl_init();
     
  if (soap_ssl_client_context(
    &vim,
    SOAP_SSL_NO_AUTHENTICATION,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL))
  {
    std::cout << "SSL:";
    soap_stream_fault(&vim, std::cerr);
    soap_done(&vim);
    soap_end(&vim);
    exit(1);
  }

  ManagedObjectRef.__item = "ServiceInstance";
  ManagedObjectRef.type = new std::string("ServiceInstance");
  RetrieveServiceContentReq._USCOREthis = &ManagedObjectRef;
     
  if ( vim.RetrieveServiceContent(&RetrieveServiceContentReq, &RetrieveServiceContentRes) == SOAP_OK )
  {
    std::cout << "RetrieveServiceContent - OK" << std::endl;
  }
  else
  {
    delete ManagedObjectRef.type;
    soap_print_fault(&vim,stderr);
    soap_done(&vim);
    soap_end(&vim);
    exit(1);
  }
     
  ServiceContent = RetrieveServiceContentRes.returnval;
     
  if (ServiceContent && ServiceContent->about)
  {
    AboutInfo = ServiceContent->about;
    std::cout << "fullName: " << AboutInfo->fullName << std::endl;
    std::cout << "  name: " << AboutInfo->name << std::endl;
    std::cout << "  build: " << AboutInfo->build << std::endl;
    std::cout << "  version: " << AboutInfo->version << std::endl;
    std::cout << "  apiType: " << AboutInfo->apiType << std::endl;
    std::cout << "  productLineId: " << AboutInfo->productLineId << std::endl;
  }

  delete ManagedObjectRef.type;

  soap_done(&vim);
  soap_end(&vim);
*/
  return 0;
}