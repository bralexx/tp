FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN mkdir -p /copy
COPY . /copy
WORKDIR copy
RUN apt-get update -y && apt-get install -y cmake make python3 python3-pip
RUN pip3 install Flask

RUN useradd -ms /bin/bash techproguser && mkdir build && cd build && cmake .. && make
USER techproguser
CMD ["python3", "app.py", "--port", "5000", "--host", "0.0.0.0"]
