#include "streamingwebserver.h"

#include <QStringBuilder>
#include <QDir>
#include <QFile>

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
    response.headers.insert(QStringLiteral("Server"), QStringLiteral("Hatschi Server 1.0"));
    response.headers.insert(QStringLiteral("Content-Type"), QStringLiteral("text/html"));

    auto path = QStringLiteral(":/StreamingWebserver/htdocs") %
                QDir::separator() %
                (request.path == QStringLiteral("/") ? QStringLiteral("index.html") : request.path);

    qDebug() << request.path << path;

    std::unique_ptr<QIODevice> device = std::make_unique<QFile>(path);
    if(device->open(QIODevice::ReadOnly))
    {
        response.statusCode = HttpResponse::StatusCode::OK;
        connection->sendResponse(response, std::move(device));
    }
    else
    {
        response.statusCode = HttpResponse::StatusCode::NotFound;
        connection->sendResponse(response, tr("Not Found"));
    }
}
