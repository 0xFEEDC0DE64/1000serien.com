#include "streamingwebserver.h"

#include "httpclientconnection.h"
#include "httpcontainers.h"

StreamingWebserver::StreamingWebserver(QObject *parent) :
    HttpServer(parent)
{
}

void StreamingWebserver::handleRequest(HttpClientConnection *connection, const HttpRequest &request)
{
    HttpResponse response;
    response.protocol = request.protocol;
    response.statusCode = HttpResponse::StatusCode::NotFound;
    response.headers.insert(QStringLiteral("Server"), QStringLiteral("Hatschi Server 1.0"));
    response.headers.insert(QStringLiteral("Content-Type"), QStringLiteral("text/html"));

    connection->sendResponse(response, tr("Not Found"));
}
