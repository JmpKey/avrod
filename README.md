# avrod
Automation (baka) of Bus station and Firebird (Red database)

# How to get a hurdy-gurdy?
Firebird is powered by its own firebird user. Therefore, we do the following:
1.  Create a directory and run there (databases are pushed along this path, because the /tmp/ is cleaned after each reboot!):
```
cd /var/
mkdir rdb
cd rdb
```
2.  Copy or create a DATABASE file in /var/rdb (this is important if you want to migrate the database):
[!] From the super god
```
cp <where from> /var/rdb
```
Our database name is "adb4_462.fdb"

3. Redoing the user:
[!] To fulfill the following from God
```
chown firebird:firebird /var/rdb/<your DB name>.fdb
```
The database should now work with Firebird.
Privileges can be reset when migrating a Database!

0. If there is an error: "remote interface Error opening database" - Your distribution does not know where the library is located libfbclient.so (if you don't have it, you'll have to use your pens to assemble it). Okay, here's the solution:
[!] To fulfill the following from God
```
ln -fs /opt/<*>/lib/libfbclient.so /usr/lib64/libfbclient.so.2
```
*set it depending on what you have Firebird or RedDatabase

You may need to reboot or restart the service.

-1. How can I free the Database from root?:
[!] From the super god
```
chmod 777 <your DB name>.fdb>
```

# Configuration
To do this, there is a path.conf file in build/Desktop-Debug/. It has the following parameters:
"pathdb" = "<*database path>"
"pathreport" = "<*home address>"
"rdata" = "<*role>"
* The role can be one of 3: "PASSENGERS", "PERSONNEL", "ST_ATTENDAT" (station attendant).

# Dependencies
* qibase
* ODBC
* firebird-dev
* firebird
* QSqlDataBase
