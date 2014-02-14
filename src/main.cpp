#include "../gsoap/soapVimBindingProxy.h"
#include "../gsoap/VimBinding.nsmap"
#include <time.h>
#include <iostream>
#include <typeinfo>

using namespace std;
SOAP_SOCKET tcp_connect(struct soap*, const char *endpoint, const char *host, int port);

void sigpipe_handle(int x) { cout << "sigpipe: " << x << endl; }

int main(int argc, char* argv[])
{
     VimBindingProxy vim;
     vim__ManagedObjectReference ManagedObjectRef;
     vim__RetrieveServiceContentRequestType RetrieveServiceContentReq;
     _vim__RetrieveServiceContentResponse RetrieveServiceContentRes;
     vim__ServiceContent *ServiceContent;
     vim__AboutInfo *AboutInfo;
     
//     vim.endpoint = "https://10.27.11.125:443/sdk/vim";
     vim.soap_endpoint = "https://10.27.11.125/sdk/vimService";
     soap_ssl_init();
     
     if (soap_ssl_client_context(
          &vim,
          SOAP_SSL_NO_AUTHENTICATION,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL     ))
     {
          cout << "SSL:";
          soap_print_fault(&vim, stderr);
          soap_done(&vim);
          soap_end(&vim);
          exit(1);
     }

     ManagedObjectRef.__item = "ServiceInstance";
     ManagedObjectRef.type = new string("ServiceInstance");
     RetrieveServiceContentReq._USCOREthis = &ManagedObjectRef;
     
     if ( vim.RetrieveServiceContent(&RetrieveServiceContentReq, &RetrieveServiceContentRes) == SOAP_OK )
     {
          cout << "RetrieveServiceContent - OK" << endl;
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
          cout << "fullName: " << AboutInfo->fullName << endl;
          cout << "  name: " << AboutInfo->name << endl;
          cout << "  build: " << AboutInfo->build << endl;
          cout << "  version: " << AboutInfo->version << endl;
          cout << "  apiType: " << AboutInfo->apiType << endl;
          cout << "  productLineId: " << AboutInfo->productLineId << endl;
     }
     
     delete ManagedObjectRef.type;

/*
     vim.soap->fopen(vim.soap, vim.endpoint, "10.27.11.125", 443);

     const std::string pack = 
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<SOAP-ENV:Envelope"
        " xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\""
        " xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\""
        " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\""
        " xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
        " xmlns:vim=\"urn:vim25\">"
        " <SOAP-ENV:Body>"
        "   <vim:RetrieveServiceContent>"
        "    <vim:_this type=\"\"></vim:_this>"
        "   </vim:RetrieveServiceContent>"
        ""
        " </SOAP-ENV:Body>"
        "</SOAP-ENV:Envelope>";

     vim.soap->fsend(vim.soap, pack.c_str(), pack.size());
*/
     soap_done(&vim);
     soap_end(&vim);
     
     return 0;
}
/*#include "../gsoap/soapVimBindingProxy.h"
#include "../gsoap/VimBinding.nsmap"

static int always_true_callback(X509_STORE_CTX *ctx, void *arg)
{
  std::cout << "qwe" << std::endl;
  return 1;
}
*/
#if 0
int main1() 
{
  const char* url = "https://10.27.11.125:443/sdk/vimService";
  VimBindingProxy vim(SOAP_XML_INDENT);
/*  vim.userid = "root";
  vim.passwd = "qwe123QWE";*/

  vim.soap_endpoint = url;
  soap_ssl_init();
  if (soap_ssl_client_context(&vim, SOAP_SSL_DEFAULT,
                                 NULL, NULL, NULL, NULL, NULL ))
  {
    std::cout << "SSL:";
    soap_stream_fault(&vim, std::cerr);
    exit(1);
  }  
//  soap_ssl_client_context(&vim, SOAP_SSL_DEFAULT, 0, 0, 0, 0, 0);
  SSL_CTX_set_cert_verify_callback(vim.ctx, always_true_callback, 0);

  vim__ManagedObjectReference mor;

  mor.__item = "ServiceInstance";
  mor.type = new std::string("ServiceInstance");

  vim__RetrieveServiceContentRequestType req;
  req._USCOREthis = &mor;

  _vim__RetrieveServiceContentResponse resp;

  if (vim.RetrieveServiceContent(&req, &resp) == SOAP_OK )
  {
    std::cout << "RetrieveServiceContent - OK" << std::endl;
  }
  else
  {
    soap_stream_fault(&vim, std::cerr);
    exit(1);
  }

  vim__ServiceContent* sc;
  sc = resp.returnval;

  if (sc && sc->about)
  {
    vim__AboutInfo* ai = sc->about;
    std::cout << "fullName: " << ai->fullName << std::endl;
  }
//  SSL_CTX_set_cert_verify_callback(vb.ctx, always_true_callback, 0);
/*
  vim__RetrieveServiceContentRequestType req;
  _vim__RetrieveServiceContentResponse resp;

  if (vb.RetrieveServiceContent(&req, &resp) != SOAP_OK)
    vb.soap_stream_fault(std::cerr); 
*/
/*
  vim__LoginRequestType req;
  _vim__LoginResponse resp;

  vim__ManagedObjectReference mor;
  mor.__item = "ServiceInstance";

  req._USCOREthis = &mor;
  req.userName = "root";
  req.password = "qwe123QWE";
  req.__item = "Login";

  if (vb.Login(&req, &resp) != SOAP_OK)
    vb.soap_stream_fault(std::cerr); 
  if(resp.returnval)
    std::cout << resp.returnval->fullName << std::endl;
*/
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
#endif