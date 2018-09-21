import rsa
import DBAdapter
import lib
import hashlib
import base64
import Cli
import os

class AuthorizationKeyMethods:
    account = {
        "FIO": None,
        "PrivateKey": None,
        "PublicKey": None,
        "Role": None,
        "IsIK": None,
    }

    isAuthorized = False
    dataBaseAdapt = None

    def __init__(self):
        self.dataBaseAdapt = DBAdapter.DBAdapter()
        return


    def authorization(self, PrivateKey):
        user = (self, AuthorizationKeyMethods.PrivateKeyToPublic(PrivateKey))
        if (user == None):
            self.do_logout()
            return False
        PublicKey = AuthorizationKeyMethods.PrivateKeyToPublic(PrivateKey)
        self.isAuthorized = True
        self.account['FIO'] = self.dataBaseAdapt.GetUserByPublicKey(PublicKey)['FIO']
        self.account['PrivateKey'] = PrivateKey
        self.account['PublicKey'] = AuthorizationKeyMethods.PrivateKeyToPublic(PrivateKey)
        self.account['Role'] = self.dataBaseAdapt.GetUserByPublicKey(PublicKey)['Role']
        self.account['IsIK'] = self.dataBaseAdapt.GetUserByPublicKey(PublicKey)['IsIk']
        return True

    def do_logout(self):
        isAuthorized = False
        self.account.FIO = None
        self.account.PrivateKey = None
        self.account.PublicKey = None
        self.account.Role = None
        self.account.IsIK = None
        return True

    '''
    generateKey - генерирует ключ
    '''

    @staticmethod
    def generateKey():
        (pubkey, privkey) = rsa.newkeys(1024)
        return privkey

    '''
    PrivateKeyToPublic - получает из закрытого ключа открытый
    '''

    @staticmethod
    def PrivateKeyToPublic(PrivateKey):
        try:
            PublicKey = str(rsa.PublicKey(PrivateKey.n, PrivateKey.e))
            return PublicKey
        except:
            return False


    '''
    PublicKeyToString - преобразует открытый ключ в строку
    '''

    @staticmethod
    def PublicKeyToString(PublicKey):
        string = (str(PublicKey.n)).encode()
        string = string + bytes(', ') + (str(PublicKey.e)).encode()
        return string.decode()

    '''
    StringToPublicKey - преобразует строку в открытый ключ
    '''

    @staticmethod
    def StringToPublicKey(string):
        if type(string) != str:
            string = string.decode()
        n = int(string[:string.find(',')])
        e = int(string[string.find(' '):])
        PublicKey = rsa.PublicKey(n, e)
        return PublicKey

    '''
    CreateSignature - подписывает строку
    '''

    @staticmethod
    def CreateSignature(string, PrivateKey):
        if type(string) == str:
            string = string.encode()
        s = rsa.sign(string, PrivateKey, 'SHA-256')
        return s.hex()

    '''
    CheckSignature - проверяет подпись
    '''
    @staticmethod
    def CheckSignature(publicKey, string, signature):
        if type(string) == str:
            string = string.encode()
            signature = bytes.fromhex(signature)
            if not rsa.verify(string, signature, publicKey):
                return rsa.pkcs1.VerificationError
        return True

'''
    def getPrivateKeyFromFile(self, fname):
        try:
            fname = os.path.abspath(fname)  # Переход по пути к файлу с ключем
            f = open(fname, 'r')  # Открытие файла с ключем с атриботом "Только для чтения"
            l = f.readlines()  # Считывание содержимого файла по строкам
            n = int(l[0][:-1])  # Считывание строк без последнего символа(им обычно указан пробел)
            e = int(l[1][:-1])
            d = int(l[2][:-1])
            p = int(l[3][:-1])
            q = int(l[4][:-1])
            PrivateKey = rsa.PrivateKey(n, e, d, p, q)  # Считывание закрытого ключа по алгоритму RSA
            return PrivateKey
        except Exception as e:
            print('Invalid Key, try again')
            return False

'''

(pubkey, privkey) = rsa.newkeys(1024)

#AuthorizationKeyMethods.PrivateKeyToPublic(privkey)
#pathPrivateKey = input('Please, enter way to private key:\n')
#exe = AuthorizationKeyMethods()
#var = exe.getPrivateKeyFromFile(pathPrivateKey)
#print(var)
#exe.authorization(var)