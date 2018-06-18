FROM ubuntu:16.04

LABEL maintainer="John Liu <bmzyDream@gmail.com"
LABEL readme.md="https://github.com/ColorfulTime/Sample/blob/master/Docker/README.md"
LABEL description="This Dockerfile will install the latest release of GDesign."

RUN apt-get update -y
RUN apt-get install -y wget
RUN wget http://github.com/ColorfulTime/Sample/releases/download/0.2.0/Sample_GDesign.deb
RUN dpkg -i Sample_GDesign.deb