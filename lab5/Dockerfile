FROM debian:latest

RUN mkdir /app
COPY app/ /app

RUN apt-get update -qq && apt-get install -y build-essential gcc
ADD https://storage.googleapis.com/golang/go1.11.linux-amd64.tar.gz /opt/go.tar.gz
RUN tar -C /usr/local/ -xvf /opt/go.tar.gz
ENV PATH=$PATH:/usr/local/go/bin

RUN cd /app && gcc -pthread lab5.c -o lab5