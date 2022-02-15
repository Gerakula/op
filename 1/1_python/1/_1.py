
def Input(f1):                                   
    file1 = open(f1, 'w')
    flag = True                                 
    symbol = 19;                   
    while flag:                                
        s = input()                             
        if s.find(chr(symbol)) != -1:           
            flag = False
            s = s.replace(chr(symbol), '')      
        if s != '':                             
            file1.write(s + '\n')
    file1.close()                              

def Output(f):
    print('')
    file = open(f, 'r')
    s = file.read()                       
    print(s)                         
    file.close()                               

def NewF(f1, f2):                           
    k = 1        
    s = ' '
    file1 = open(f1, "r")
    file2 = open(f2, "w")
    while s:                     
        s = file1.readline()      
        if s != "":          
            if s.find('\n') != -1: 
                snew = str(k) + " " + s.replace('\n', '') + " " + str(len(s) - 1) + '\n'
            else:
                snew = str(k) + " " + s.replace('\n', '') + " " + str(len(s)) + '\n'
            k += 1                                
            file2.write(snew)
    file1.close()
    file2.close()

def Add(f):                            
    file = open(f, 'a')
    flag = True                                 
    symbol = 19;                                
    while flag:                                 
        s = input()                             
        if s.find(chr(symbol)) != -1:           
            flag = False
            s = s.replace(chr(symbol), '')              
        if s != '':                             
            file.write(s)
    file.close()


sym = '1'
f1 = "file1.txt"
f2 = "file2.txt"
Input(f1)
Output(f1)
NewF(f1, f2)
Output(f2)
while sym == '1':
    sym = input("Поставте 1 если хотите продолжить ввод:  ")
    if sym == '1':
        Add(f1)
        Output(f1)
        NewF(f1, f2)
        Output(f2)