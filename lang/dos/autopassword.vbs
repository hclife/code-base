set ws=wscript.createobject("wscript.shell")
'WScript.Echo("====Auto Password====")
'WScript.Echo("Using " & LCase(right(Wscript.fullName,11)))
'WScript.Echo("File:     " & Wscript.Arguments(0))
'WScript.Echo("Password: " & Wscript.Arguments(1))
file = chr(34) & Wscript.Arguments(0)& Chr(34)
ws.run file   '��PDF
'wscript.sleep 500
'ws.AppActivate "����"
wscript.sleep 1000        '���ô򿪺�ĵȴ�ʱ�䣬���ݸ��˻���������ó���
ws.SendKeys Wscript.Arguments(1)   'ģ����������
ws.SendKeys "{ENTER}"    '�س���pdf