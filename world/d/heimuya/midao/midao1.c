//Room:/d/heimuya/midao/midao1.c 
//write by dfbb@hero
//Date: 1/25/96
inherit ROOM;

void create()
 {
        set("short", "�����ܵ�");
        set("long", @LONG ����������,ֻ��ǽ���ϵ���һյ�谵���͵�
 ��ʪ����ζ����ʮ�ֲ����,ֻ�����߳������ط�.
LONG );
        set("exits", ([
	  "up":	"/d/heimuya/xiaowu",
          "east" : __DIR__"midao7",
         ]));
        setup();
}
// the end of the file 

