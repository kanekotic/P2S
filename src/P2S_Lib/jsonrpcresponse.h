#pragma once

#include "p2slib.h"
#include "jsonrpcvalidator.h"
#include "iresponse.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

/**
 * @name    JsonRpcResponse
 * @brief   implementation of the response for JSON-RPC 2.0
 */
class P2S_LIBSHARED_EXPORT JsonRpcResponse : public IResponse
{
private:
    JSonRPCRequestValidator validator;
protected:
    nlohmann::json content;
    JsonRpcResponse(std::string id);
public:
    JsonRpcResponse() = delete;
    virtual std::string Serialize();
};

/**
 * @name    JsonRpcResponse
 * @brief   implementation of the response for valid server result
 */
class P2S_LIBSHARED_EXPORT  ValidJsonRpcResponse : public JsonRpcResponse
{
public:
    ValidJsonRpcResponse(std::string result, std::string id);
};

/**
 * @name    JsonRpcResponse
 * @brief   implementation of the response for a server error
 */
class P2S_LIBSHARED_EXPORT  ErrorJsonRpcResponse : public JsonRpcResponse
{
public:
    ErrorJsonRpcResponse(int code, std::string message, std::string id, std::string data = "");
};

}
}
