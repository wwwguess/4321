//Room:/d/heimuya/midao/midao22.c 
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
          "north" : __DIR__"midao11",
           "east" : __DIR__"midao23",
           "west" : __DIR__"midao21",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

