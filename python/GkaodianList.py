#coding=utf-8
import sys
import pymssql
reload(sys)
#------------------------------连接数据库全局变量
sys.setdefaultencoding('utf8')
conn=pymssql.connect(host='192.168.1.17',user='sa',password='sa',database='kddb',charset='utf8')
cur=conn.cursor()

def godview():
    xuexiao=[]
    query = "select kdmingchen from kaodian;"
    aa = cur.execute(query)
    info=cur.fetchall()
    for row in info:
        xuexiao.append(row[0].encode('latin1').decode('gbk')) 
    for item in xuexiao:
        print item,
        query = "select kdjscount from kaodian where kdmingchen ='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0]

        print u"考点主任:",
        query = "select ryname,dianhua from kdry where kdry.rolename='考点主任' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0].encode('latin1').decode('gbk'),
            print  row[1].encode('latin1').decode('gbk'),
        print ""

        print u"考务主任:",
        query = "select ryname,dianhua from kdry where kdry.rolename='考务主任' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0].encode('latin1').decode('gbk'),
            print  row[1].encode('latin1').decode('gbk'),
        print ""

        print u"人事巡视人数:",
        query = "select count(*) from kdry where kdry.rolename='人事巡视' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0]

        print u"人事考务:",
        query = "select ryname from kdry where kdry.rolename='人事考务' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0].encode('latin1').decode('gbk'),
        print ""

        print u"监考人员数量:",
        query = "select count(*) from kdry where kdry.rolename='监考' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0]

        print u"驾驶员:",
        query = "select ryname,dianhua,chepaihao from kdry where kdry.rolename='驾驶员' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0].encode('latin1').decode('gbk'),
            print  row[1].encode('latin1').decode('gbk'),
            print  row[2].encode('latin1').decode('gbk'),
        print ""

        print u"医务数量:",
        query = "select count(*) from kdry where kdry.rolename='医务' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0]

        print u"人事安保数量:",
        query = "select count(*) from kdry where kdry.rolename='人事保卫' and kdry.kdmingchen='%s'" % (item)
        bb = cur.execute(query)
        info=cur.fetchall()
        for row in info:
            print  row[0]
        print ""
    cur.close()
    conn.close()
#def GnameList()

if __name__ == "__main__":
    godview()
