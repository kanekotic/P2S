#include "jsonrpcrequest.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;

void JsonRpcRequest::Deserialize(const string &rawContent)
{
    auto parsed = json::parse(rawContent);
    if(!validator.IsValid(parsed))
        throw RequestParseException("json is not valid JSON-RPC 2.0");
    content = parsed;
}

string JsonRpcRequest::GetMethod()
{
    return content["method"];
}

nlohmann::json JsonRpcRequest::GetParams()
{
    return content["params"];
}

string JsonRpcRequest::GetId()
{
    if(content.count("id") == 0)
        return "";
    return content["id"].dump();
}
