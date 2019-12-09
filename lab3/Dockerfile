FROM debian:latest

RUN mkdir /app
COPY app/ /app

RUN apt-get update -qq && apt-get install -y build-essential gcc g++

RUN cd /app && g++ -masm=intel lab3.cpp -o lab3