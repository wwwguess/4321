//Room:/d/heimuya/midao/midao24.c 
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
          "north" : __DIR__"midao13",
           "east" : __DIR__"midao25",
           "south" : __DIR__"midao36",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

