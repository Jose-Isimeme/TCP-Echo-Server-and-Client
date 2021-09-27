# TCP-Echo-Server-and-Client

## ECEN 602 MP1 
Emily Feller and Jose Isimeme

### Code Description
This project represents a TCP echo service, utilizing both a server and a client than can be run in a Linux environment. This small example of a network application requires the echoing of input by a user. 

### Architecture and Approach
Using the diagram provided in the lecture and the recitation, our application follows a simple server and client format. This is shown below:

<img width="717" alt="Screen Shot 2021-09-23 at 1 36 59 PM" src="https://user-images.githubusercontent.com/60982611/134564578-dc3dceb2-dcb7-41a3-91df-f09c050423f0.png">

By utilizing given libraries and standard system calls, we were able to step through this architecture. The project also required the writing of the read(), readlines(), and writen() functions to communicate the echo within the service. 

### Usage and Makefile Commands
A makefile was created to make the usage of this project easier. There is a makefile for both the server and the client as well as a clean command to clean out the project.

To start the project, start the server either with the make command or with echos Port. Then start the client with the make command or with echo IPAdr Port.
