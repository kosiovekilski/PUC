import wx

class randomName(wx.Frame):
    def __init__(self, parent, id):
        wx.Frame.__init__(self, parent, id, 'Imeto na prozoreca', size=(200,300))
        

if __name__ == '__main__':
    app = wx.PySimpleApp()
    frame = randomName(parent=None,id=-1)
    frame.Show()
    app.MainLoop()
