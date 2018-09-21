import base64
import hashlib
import rsa
import json
import copy
import DBAdapter
import lib
import AuthorizationKeyMethods
'''
import network
'''

class Blockchain:
    CNetwork = None
    dataBaseAdapt = DBAdapter.DBAdapter()

    def __init__(self):
        pass

    '''
    TransactDict = 
    {
    ID = 'ID',
    type = 'type',
    data = 'data',
    publicKey = 'publicKey',
    signature = 'signature'
    }
    type ==
    0 - регистрация в открытые пользователи
    1 - регистрация в закрытые пользователи
    2 - создание открытого голосования
    3 - создание закрытого голосования
    4 - отдать голос
    5 - повысить роль
    6 - понизить роль
    7 - ИК
    8 - ИК нет
    9 - редактирование профиля
    
    
    
    '''

    def InitNetwork(self, NetClass):
        self.CNetwork = NetClass
        return True
    '''
    '''
    def AddTransactFromUser(self, Transact):
        if self.TransactVerification(Transact):
            if self.AddTransactToUncTransact(Transact):
                self.SendTransact(Transact)
        return True

    def AddTransactFromNet(self, Transact):
        if self.TransactVerification(Transact):
            self.AddTransactToUncTransact(Transact)
        return True

    def AddBlockFromUser(self, block):
        if self.BlockVerification(block):
            if self.AddBlockToChain(block):
                self.SendBlock(block)
        return True

    def AddBlockFromNet(self, block):
        if self.BlockVerification(block):
            self.AddBlockToChain(block)
        return True

    def SendTransact(self, Transact):
        return True

    def TransactVerification(self, Transact):
        type = Transact['type']
        jsonTransact = copy.deepcopy(Transact)
        signature = jsonTransact.pop(Transact)['signature']
        jsonTransact = jsonTransact.pop(Transact)['ID']
        string = json.dump(jsonTransact, sort_keys=True)

        pubkey = AuthorizationKeyMethods.AuthorizationKeyMethods.PrivateKeyToPublic(Transact)['PrivateKey']

        if not (AuthorizationKeyMethods.AuthorizationKeyMethods.CheckSignature(pubkey, string, signature)):
            return False

        if type == 0:
            self.checkAddUserToOpenTable(Transact)
            return True
        if type == 1:
            self.checkAddUserToCloseTable(Transact)
            return True
        if type == 2:
            self.checkCreateOpenVote(Transact)
            return True
        if type == 3:
            self.checkCreateCloseVote(Transact)
            return True
        if type == 4:
            self.checkGiveVote(Transact)
            return True
        if type == 5:
            self.checkUpRole(Transact)
            return True
        if type == 6:
            self.checkDownRole(Transact)
            return True
        if type == 7:
            self.checkStatusIK(Transact)
            return True
        if type == 8:
            self.checkStatusIKOut(Transact)
            return True
        if type == 9:
            self.checkEditProfile(Transact)
            return True

    def blockVerification(self):
        return True

    def CommitTransaction(self, Transact, CreateTime):
        type = Transact['type']

        if type == 0:
            self.AddUserToOpenTable(Transact)
            return True
        if type == 1:
            self.AddUserToCloseTable(Transact)
            return True
        if type == 2:
            self.CreateOpenVote(Transact)
            return True
        if type == 3:
            self.CreateCloseVote(Transact)
            return True
        if type == 4:
            self.GiveVote(Transact)
            return True
        if type == 5:
            self.UpRole(Transact)
            return True
        if type == 6:
            self.DownRole(Transact)
            return True
        if type == 7:
            self.StatusIK(Transact)
            return True
        if type == 8:
            self.StatusIKOut(Transact)
            return True
        if type == 9:
            self.EditProfile(Transact)
            return True

    def checkAddUserToOpenTable(self, Transact):
        if not self.dataBaseAdapt.GetUserByPublicKey((Transact('publicKey'))['role']) == "admin":
            return False

    def checkAddUserToCloseTable(self, Transact):
        return True

    def checkCreateOpenVote(self, Transact):
        return True

    def checkCreateCloseVote(self, Transact):
        return True

    def checkGiveVote(self, Transact):
        return True

    def checkUpRole(self, Transact):
        return True

    def checkDownRole(self, Transact):
        return True

    def checkStatusIK(self, Transact):
        return True

    def checkStatusIKOut(self, Transact):
        return True

    def checkEditProfile(self, Transact):
        return True