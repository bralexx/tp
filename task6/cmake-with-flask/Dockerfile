FROM ubuntu:20.04

RUN mkdir runn
COPY . runn
WORKDIR /runn
RUN apt-get update -y && apt-get install -y cmake make python3 python3-pip &&  pip3 install Flask
RUN useradd -ms /bin/bash techproguser && cd /runn && mkdir build && cd build && cmake .. && make
USER techproguser
CMD ["python3", "/runn/app.py", "--port", "5000", "--host", "0.0.0.0"]
