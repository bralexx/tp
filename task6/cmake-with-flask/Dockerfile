FROM ubuntu
ADD ..
WORKDIR .
ENV TZ=Europe/Minsk
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime
RUN apt update; apt install -y g++ cmake make python3.9 python3-pip
RUN python3.9 -m pip install flask
RUN mkdir build
RUN cd build
RUN cmake ..
RUN make
RUN cd ..
RUN useradd techproguser
USER techproguser
CMD ["python3.9", "app.py", "--port", "5000", "--host", "0.0.0.0"]
