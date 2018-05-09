FROM 0xfeedc0de64/qt-build

ADD . /tmp/StreamingWebserver

RUN mkdir -p /tmp/build_StreamingWebserver \
 && qmake /tmp/StreamingWebserver -o /tmp/build_StreamingWebserver/Makefile -config release \
 && make -C /tmp/build_StreamingWebserver -j8 \
 && make -C /tmp/build_StreamingWebserver install



FROM 0xfeedc0de64/qt-runtime

COPY --from=0 /tmp/build_StreamingWebserver/StreamingWebserver /root/

EXPOSE 8080/tcp

CMD /root/StreamingWebserver
