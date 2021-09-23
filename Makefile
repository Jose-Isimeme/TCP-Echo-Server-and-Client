# makefile command for the client
client: client.c
  gcc -I . client.c -o echo
  
# makefile command for the server:
server: server.c
  gcc -I . server.c -o echos
  
# makefile command for cleaning
clean:
  $(RM) *.o
