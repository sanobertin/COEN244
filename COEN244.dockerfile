
FROM alpine:3.18.4 AS build

RUN apk update && \
    RUN apk update && \
        apk add --no-cache \
            build-base=0.5-r3 \
            ninja \
            cmake=3.27.7 \

WORKDIR /coen244

COPY /users/bertin/clionprojects/coen244/assignment1/ ./
COPY CMakeLists.txt ./

RUN cmake -G ninja \
    cmkae --build -j 6


ENTRYPOINT [ "./src" ]