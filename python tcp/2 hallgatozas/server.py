import socket
import select
import sys

'''SERVER'''
print("én vagyok a szerver")


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind(('localhost', 12346))
sock.listen(10)
inputs = [sock]
clients = []


while True:
    readable, _, _ = select.select(inputs, [], [])
    for s in readable:
        if s is sock:
            new_cient, cli_addr = s.accept()
            print('Uj kliens kapcsolodott: ' + str(cli_addr))
            inputs.append(new_cient)
            clients.append(new_cient)
        else:
            client_message = s.recv(1024)
            if client_message:
                print(client_message.decode())
                for c in clients:
                    if c is not s:
                        c.send(client_message)
            else:
                print("lelepett valaki")
                inputs.remove(s)
                clients.remove(s)
sock.close()
