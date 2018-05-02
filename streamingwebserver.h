#pragma once

#include <QObject>

#include "httpserver.h"

class HttpClientConnection;
class HttpRequest;

class StreamingWebserver : public HttpServer
{
    Q_OBJECT

public:
    explicit StreamingWebserver(QObject *parent = Q_NULLPTR);

protected:
    void handleRequest(HttpClientConnection *connection, const HttpRequest &request) Q_DECL_OVERRIDE;
};
