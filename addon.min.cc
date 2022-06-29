#include <napi.h>
#include <windows.h>
#include <stdio.h>
#include <netlistmgr.h>
#pragma comment(lib, "ole32.lib" )
#include <chrono>
#include <thread>
#include <iostream>
Napi::Boolean GetConnectivity(const Napi::CallbackInfo&info){Napi::Env env=info.Env();CoInitialize(NULL);bool inetconnection=false;INetworkListManager*networkListManager=NULL;HRESULT hr=CoCreateInstance(CLSID_NetworkListManager,NULL,CLSCTX_ALL,IID_INetworkListManager,(LPVOID*)&networkListManager);if(SUCCEEDED(hr)){NLM_CONNECTIVITY result;hr=networkListManager->GetConnectivity(&result);if(SUCCEEDED(hr)){if(result&(NLM_CONNECTIVITY_IPV4_INTERNET|NLM_CONNECTIVITY_IPV6_INTERNET))inetconnection=true;};networkListManager->Release();};return Napi::Boolean::New(env,inetconnection);};Napi::Object Init(Napi::Env env,Napi::Object exports){exports.Set(Napi::String::New(env,"GetConnectivity"),Napi::Function::New(env,GetConnectivity));return exports;};NODE_API_MODULE(NODE_GYP_MODULE_NAME,Init);