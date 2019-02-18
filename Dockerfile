FROM debian:latest

RUN mkdir /app
COPY app/ /app

ADD https://storage.googleapis.com/golang/go1.11.linux-amd64.tar.gz /opt/go.tar.gz
RUN tar -C /usr/local/ -xvf /opt/go.tar.gz
ENV PATH=$PATH:/usr/local/go/bin

RUN go run /app/lab1.go
