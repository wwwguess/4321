//Room:/d/heimuya/midao/midao46.c 
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
          "north" : __DIR__"midao36",
           "east" : __DIR__"midao47",
           "south" : __DIR__"midao55",
           "west" : __DIR__"midao45",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

