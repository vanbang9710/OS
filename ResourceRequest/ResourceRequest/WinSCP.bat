open sftp://vanba:vanba@192.168.88.128/ -hostkey="ssh-ed25519 255 DdSEqVq4ZggNPiBqFD2rgkvq982UPTHU+/ElGeJ4TBE"

lcd E:\Code\OS\ResourceRequest
cd /home/vanba

put ResourceRequest

exit

# Execute the script using a command like:
# "C:\Users\vanba\AppData\Local\Programs\WinSCP\WinSCP.exe" /log="C:\writable\path\to\log\WinSCP.log" /ini=nul /script="C:\path\to\script\script.txt"
